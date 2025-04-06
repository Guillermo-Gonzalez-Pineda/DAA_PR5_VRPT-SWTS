#include "../include/summary-generator.h"
#include "../include/data-parser.h"
#include "../include/recolection-greedy-strategy.h"
#include "../include/transport-greedy-strategy.h"
#include <fstream>
#include <iomanip>
#include <chrono>

SummaryGenerator::SummaryGenerator(const std::string& summaryFile, const std::vector<std::string>& instanceFiles)
    : summaryFile_(summaryFile), instanceFiles_(instanceFiles) {}

void SummaryGenerator::generate() {
    try {
        std::ofstream outFile(summaryFile_);
        if (!outFile.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo de resumen.");
        }

        outFile << "=============================\n";
        outFile << "Resumen Resultados Instancias\n";
        outFile << "=============================\n\n";

        outFile << "|| VORAZ ||\n";
        outFile << "==================================================================\n";
        outFile << "INSTANCE        ZONES         CV        TV        CPU_TIME\n";

        double totalCV = 0, totalTV = 0, totalCPU = 0;
        int instanceCount = 0;

        for (const auto& instanceFile : instanceFiles_) {
            try {
                DataParser parser(instanceFile);

                auto collectionZones = parser.getCollectionZones();
                auto transferStations = parser.getTransferStations();
                auto depot = parser.getDepot();
                auto dumpsite = parser.getDumpsite();
                auto distances = parser.getDistances();
                double collectionVehicleCapacity = parser.getCollectionVehicleCapacity();
                double transportVehicleCapacity = parser.getTransportVehicleCapacity();
                double maxCollectionRouteTime = parser.getMaxCollectionRouteTime();
                double maxTransportRouteTime = parser.getMaxTransportationRouteTime();
                double speed = parser.getSpeed();

                // Ejecutar algoritmos voraces
                double cpuTime = 0; // Simular el tiempo de CPU
                // Aqui se inicia el tiempo de CPU
                std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
                RecolectionGreedyStrategy recolectionGreedy(collectionVehicleCapacity, maxCollectionRouteTime, speed);
                auto collectionVehicles = recolectionGreedy.computeRoutes(collectionZones, transferStations, depot, distances);

                TransportGreedyStrategy transportGreedy(transportVehicleCapacity, maxTransportRouteTime, speed);
                auto transportVehicles = transportGreedy.computeTransportRoutes(collectionVehicles, dumpsite, distances);

                // Aqui se termina el tiempo de CPU
                std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
                cpuTime = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

                // Calcular estadísticas
                int totalZones = parser.getNumZones();
                int collectionVehiclesUsed = collectionVehicles.size();
                int transportVehiclesUsed = transportVehicles.size();

                // Acumular estadísticas
                totalCV += collectionVehiclesUsed;
                totalTV += transportVehiclesUsed;
                totalCPU += cpuTime;
                ++instanceCount;

                // Escribir resultados de la instancia
                outFile << instanceFile << "       " << totalZones << "            "
                        << collectionVehiclesUsed << "          " << transportVehiclesUsed << "       "
                        << std::fixed << std::setprecision(6) << cpuTime << "\n";

            } catch (const std::exception& e) {
                std::cerr << "Error procesando la instancia " << instanceFile << ": " << e.what() << "\n";
            }
        }

        outFile << "==================================================================\n";
        double avgCV = (instanceCount > 0) ? (totalCV / instanceCount) : 0;
        double avgTV = (instanceCount > 0) ? (totalTV / instanceCount) : 0;
        outFile << "Avarage of CV: " << avgCV << "\n";
        outFile << "Avarage of TV: " << avgTV << "\n";

        outFile.close();
        std::cout << "Resumen generado en: " << summaryFile_ << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error generando el resumen: " << e.what() << "\n";
    }
}
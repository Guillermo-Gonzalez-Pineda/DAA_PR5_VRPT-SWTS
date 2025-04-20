#include "../include/instance-processor.h"

InstanceProcessor::InstanceProcessor(const std::string& inputFile, const std::string& outputFile)
    : inputFile_(inputFile), outputFile_(outputFile) {}

void InstanceProcessor::process() {
    try {
        DataParser parser(inputFile_);

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

        // Estrategia Greedy
        RecolectionGreedyStrategy recolectionGreedy(collectionVehicleCapacity, maxCollectionRouteTime, speed);
        auto collectionVehiclesGreedy = recolectionGreedy.computeRoutes(collectionZones, transferStations, depot, distances);

        TransportGreedyStrategy transportGreedy(transportVehicleCapacity, maxTransportRouteTime, speed);
        auto transportVehiclesGreedy = transportGreedy.computeTransportRoutes(collectionVehiclesGreedy, dumpsite, distances);

        // Estrategia GRASP
        RecolectionGRASPStrategy recolectionGRASP(collectionVehicleCapacity, maxCollectionRouteTime, speed, 5); // Tamaño LRC = 5
        auto collectionVehiclesGRASP = recolectionGRASP.computeRoutes(collectionZones, transferStations, depot, distances);

        // Generar reporte
        ReportGenerator reportGenerator(outputFile_);
        reportGenerator.addRecolectionResult(collectionVehiclesGreedy);
        reportGenerator.addTransportResult(transportVehiclesGreedy);

        // Agregar resultados de GRASP
        reportGenerator.addGRASPResult(inputFile_, parser.getNumZones(), 5, collectionVehiclesGRASP.size(), transportVehiclesGreedy.size(), 0.123456); // Simulación de tiempo de CPU

        reportGenerator.writeToFile();

        std::cout << "Resultados generados en: " << outputFile_ << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error procesando la instancia: " << e.what() << "\n";
    }
}
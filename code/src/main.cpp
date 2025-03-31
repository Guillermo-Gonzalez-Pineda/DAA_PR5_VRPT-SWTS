#include <iostream>
#include <fstream>
#include "../include/data-parser.h"
#include "../include/recolection-greedy-strategy.h"
#include "../include/transport-greedy-strategy.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo_de_entrada>" << std::endl;
        return 1;
    }

    std::string inputFile = argv[1];

    try {
        // Parsear el archivo de entrada
        DataParser parser(inputFile);

        // Obtener los datos necesarios
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

        // Crear la estrategia greedy para recolección
        RecolectionGreedyStrategy recolectionStrategy(collectionVehicleCapacity, maxCollectionRouteTime, speed);

        // Ejecutar el algoritmo de recolección
        auto collectionVehicles = recolectionStrategy.computeRoutes(collectionZones, transferStations, depot, distances);

        // Mostrar los resultados de recolección
        std::cout << "Número de vehículos de recolección utilizados: " << collectionVehicles.size() << std::endl;
        for (const auto& vehicle : collectionVehicles) {
            std::cout << "Vehículo de recolección " << vehicle.getId() << " - Ruta: ";
            for (const auto& location : vehicle.getRoute()) {
                std::cout << location->getId() << " -> ";
            }
            std::cout << "FIN" << std::endl;
        }

        // Crear la estrategia greedy para transporte
        TransportGreedyStrategy transportStrategy(transportVehicleCapacity, maxTransportRouteTime, speed);

        // Ejecutar el algoritmo de transporte
        auto transportVehicles = transportStrategy.computeTransportRoutes(collectionVehicles, transferStations, dumpsite, distances);

        // Mostrar los resultados de transporte
        std::cout << "\nNúmero de vehículos de transporte utilizados: " << transportVehicles.size() << std::endl;
        for (const auto& vehicle : transportVehicles) {
            std::cout << "Vehículo de transporte " << vehicle->getId() << " - Ruta: ";
            for (const auto& location : vehicle->getRoute()) {
                std::cout << location->getId() << " -> ";
            }
            std::cout << "FIN" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
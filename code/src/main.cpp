#include <iostream>
#include <fstream>
#include "../include/data-parser.h"
#include "../include/recolection-greedy-strategy.h"
#include "../include/recolection-grasp-strategy.h"
#include "../include/transport-greedy-strategy.h"

void printRoute(const std::vector<std::shared_ptr<Location>>& route) {
    for (const auto& location : route) {
        std::string locationType;
        int id = location->getId();
        if (id == 0) {
            locationType = "Depot";
        } else if (id == 21) {
            locationType = "IF";
        } else if (id == 22) {
            locationType = "IF1";
        } else if (id == 23) {
            locationType = "Dumpsite";
        } else {
            locationType = "Zone" + std::to_string(id);
        }
        std::cout << locationType << " (" << location->getX() << ", " << location->getY() << ") -> ";
    }
    std::cout << "FIN" << std::endl;
}

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
        auto collectionZonesGRASP = collectionZones;
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
        RecolectionGreedyStrategy recolectionGreedy(collectionVehicleCapacity, maxCollectionRouteTime, speed);

        // Ejecutar el algoritmo de recolección voraz
        auto collectionVehiclesGreedy = recolectionGreedy.computeRoutes(collectionZones, transferStations, depot, distances);

        // Mostrar los resultados de recolección voraz
        std::cout << "=== Recolección (Voraz) ===" << std::endl;
        for (const auto& vehicle : collectionVehiclesGreedy) {
            std::cout << "Vehículo de recolección " << vehicle.getId() << " - Ruta: ";
            printRoute(vehicle.getRoute());
        }

        // Crear la estrategia greedy para transporte
        TransportGreedyStrategy transportGreedy(transportVehicleCapacity, maxTransportRouteTime, speed);

        // Ejecutar el algoritmo de transporte voraz
        auto transportVehiclesGreedy = transportGreedy.computeTransportRoutes(collectionVehiclesGreedy, dumpsite, distances);

        // Mostrar los resultados de transporte voraz
        std::cout << "\n=== Transporte (Voraz) ===" << std::endl;
        for (const auto& vehicle : transportVehiclesGreedy) {
            std::cout << "Vehículo de transporte " << vehicle->getId() << " - Ruta: ";
            printRoute(vehicle->getRoute());
        }

        // Crear la estrategia GRASP para recolección
        double alpha = 0.5; // Parámetro alpha para la RCL
        RecolectionGRASPStrategy recolectionGRASP(collectionVehicleCapacity, maxCollectionRouteTime, speed, alpha);

        // Ejecutar el algoritmo de recolección GRASP
        auto collectionVehiclesGRASP = recolectionGRASP.computeRoutes(collectionZonesGRASP, transferStations, depot, distances);

        // Mostrar los resultados de recolección GRASP
        std::cout << "\n=== Recolección (GRASP) ===" << std::endl;
        for (const auto& vehicle : collectionVehiclesGRASP) {
            std::cout << "Vehículo de recolección " << vehicle.getId() << " - Ruta: ";
            printRoute(vehicle.getRoute());
        }

        // Ejecutar el algoritmo de transporte voraz con las rutas de recolección GRASP
        auto transportVehiclesGRASP = transportGreedy.computeTransportRoutes(collectionVehiclesGRASP, dumpsite, distances);

        // Mostrar los resultados de transporte voraz con recolección GRASP
        std::cout << "\n=== Transporte (Voraz con Recolección GRASP) ===" << std::endl;
        for (const auto& vehicle : transportVehiclesGRASP) {
            std::cout << "Vehículo de transporte " << vehicle->getId() << " - Ruta: ";
            printRoute(vehicle->getRoute());
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
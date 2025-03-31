#ifndef RECOLECTION_GREEDY_STRATEGY_H
#define RECOLECTION_GREEDY_STRATEGY_H

#include <vector>
#include <memory>
#include "collection-vehicle.h"
#include "collection-zone.h"
#include "solid-waste-transfer-station.h"

class RecolectionGreedyStrategy {
public:
  // Constructor con parámetros para capacidad, tiempo máximo de ruta y velocidad
  RecolectionGreedyStrategy(double vehicleCapacity, double maxRouteTime, double speed)
    : vehicleCapacity_(vehicleCapacity), maxRouteTime_(maxRouteTime), speed_(speed) {}

  // Método que calcula las rutas para los vehículos de recolección
  std::vector<CollectionVehicle> computeRoutes(
    std::vector<std::shared_ptr<CollectionZone>>& collectionZones, // Usamos shared_ptr para las zonas
    std::vector<std::shared_ptr<SWTS>>& transferStations,          // Usamos shared_ptr para las estaciones de transferencia
    const std::shared_ptr<Location>& depot,                        // Usamos shared_ptr para el depósito
    std::vector<std::vector<double>>& distances
  );

private:
  double vehicleCapacity_;  // Capacidad máxima del vehículo
  double maxRouteTime_;     // Tiempo máximo permitido para la ruta
  double speed_;            // Velocidad del vehículo
};

#endif

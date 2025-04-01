#ifndef RECOLECTION_GRASP_STRATEGY_H
#define RECOLECTION_GRASP_STRATEGY_H

#include <vector>
#include <memory>
#include "collection-vehicle.h"
#include "collection-zone.h"
#include "solid-waste-transfer-station.h"

class RecolectionGRASPStrategy {
public:
  // Constructor con parámetros para capacidad, tiempo máximo de ruta, velocidad y parámetro alpha para la RCL
  RecolectionGRASPStrategy(double vehicleCapacity, double maxRouteTime, double speed, double alpha)
    : vehicleCapacity_(vehicleCapacity), maxRouteTime_(maxRouteTime), speed_(speed), alpha_(alpha) {}

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
  double alpha_;            // Parámetro para la RCL en GRASP (entre 0 y 1)
};

#endif

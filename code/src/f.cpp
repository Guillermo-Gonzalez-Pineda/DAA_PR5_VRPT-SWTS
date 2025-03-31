#include "../include/recolection-greedy-strategy.h"
#include <iostream>
#include <limits>
#include <algorithm>

std::vector<CollectionVehicle> RecolectionGreedyStrategy::computeRoutes(
    std::vector<CollectionZone>& collectionZones, 
    std::vector<SWTS>& transferStations, 
    const Location& depot,
    std::vector<std::vector<double>>& distances) {
    
  std::vector<CollectionVehicle> vehiclesWithRoutes;
  int vehicleId = 1;

  while (!collectionZones.empty()) {
    // Crear un nuevo vehículo
    CollectionVehicle vehicle(vehicleId++, vehicleCapacity_, maxRouteTime_);
    vehicle.addZoneToRoute(depot); // Inicializar la ruta con el depósito

    while (true) {
      // Encontrar la zona de recolección más cercana
      CollectionZone* closestZone = nullptr;
      double minDistance = std::numeric_limits<double>::max();

      for (auto& zone : collectionZones) {
        double distance = distances[vehicle.getLastZone().getId()][zone.getId()];
        if (distance < minDistance) {
          minDistance = distance;
          closestZone = &zone;
        }
      }

      if (!closestZone) {
        break; // Si no hay más zonas, terminamos
      }

      // Calcular el tiempo necesario para visitar la zona, una SWTS y volver al depósito
      double travelTimeToZone = minDistance / speed_;
      SWTS* nearestSWTS = nullptr;
      double minSWTSDistance = std::numeric_limits<double>::max();

      for (auto& station : transferStations) {
        double distToSWTS = distances[closestZone->getId()][station.getId()];
        if (distToSWTS < minSWTSDistance) {
          minSWTSDistance = distToSWTS;
          nearestSWTS = &station;
        }
      }

      if (!nearestSWTS) {
        break; // Si no hay SWTS, terminamos
      }

      double travelTimeToSWTS = minSWTSDistance / speed_;
      double travelTimeToDepot = distances[nearestSWTS->getId()][depot.getId()] / speed_;
      double totalTime = travelTimeToZone + travelTimeToSWTS + travelTimeToDepot;

      if (closestZone->getDemand() <= vehicle.getCurrentLoad() && totalTime <= vehicle.getCurrentTime()) {
        // Agregar la zona a la ruta
        vehicle.addZoneToRoute(*closestZone);
        vehicle.addLoad(closestZone->getDemand());
        vehicle.addTime(travelTimeToZone);

        // Eliminar la zona de la lista
        collectionZones.erase(
          std::remove(collectionZones.begin(), collectionZones.end(), *closestZone), 
          collectionZones.end()
        );
      } else {
        if (totalTime <= vehicle.getCurrentTime()) {
          // Visitar la SWTS más cercana
          vehicle.addZoneToRoute(*nearestSWTS);
          vehicle.addTime(travelTimeToSWTS);
          vehicle.resetLoad(); // Reiniciar la capacidad del vehículo
        } else {
          // Si no hay suficiente tiempo, cerrar la ruta
          break;
        }
      }
    }

    // Asegurarse de que la ruta termine en una SWTS antes de regresar al depósito
    if (std::find(transferStations.begin(), transferStations.end(), vehicle.getLastZone()) == transferStations.end()) {
      SWTS* nearestSWTS = nullptr;
      double minDistance = std::numeric_limits<double>::max();

      for (auto& station : transferStations) {
        double dist = distances[vehicle.getLastZone().getId()][station.getId()];
        if (dist < minDistance) {
          minDistance = dist;
          nearestSWTS = &station;
        }
      }

      if (nearestSWTS) {
        vehicle.addZoneToRoute(*nearestSWTS);
      }
    }
    vehicle.addZoneToRoute(depot); // Regresar al depósito
    vehiclesWithRoutes.push_back(vehicle); // Agregar el vehículo a la lista de vehículos
  }

  return vehiclesWithRoutes; // Devolver la lista de vehículos con rutas
}
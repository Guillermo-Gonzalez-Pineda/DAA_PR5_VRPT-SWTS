#include "../include/recolection-greedy-strategy.h"
#include <iostream>
#include <limits>
#include <algorithm>

std::vector<CollectionVehicle> RecolectionGreedyStrategy::computeRoutes(
      std::vector<std::shared_ptr<CollectionZone>>& collectionZones,
      std::vector<std::shared_ptr<SWTS>>& transferStations,
      const std::shared_ptr<Location>& depot,
      std::vector<std::vector<double>>& distances) {

  std::vector<CollectionVehicle> vehiclesWithRoutes;
  int vehicleId = 1;
  while (!collectionZones.empty()) {
    // Crear nuevo vehículo
    CollectionVehicle vehicle(vehicleId++, vehicleCapacity_, maxRouteTime_);
    vehicle.addZoneToRoute(depot); // Inicializar la ruta con el depósito

    while (true) {
      // Encontrar la zona de recolección más cercana
      std::shared_ptr<CollectionZone> closestZone = nullptr;
      double minDistance = std::numeric_limits<double>::max();

      for (auto& zone : collectionZones) {
        double distance = distances[vehicle.getLastZone()->getId()][zone->getId()];
        if (distance < minDistance) {
          minDistance = distance;
          closestZone = zone;
        }
      }
      if (!closestZone) {
        break; // Si no hay más zonas, terminamos
      }

      // Calcular el tiempo necesario para visitar la zona, una SWTS y volver al depósito
      double travelTimeToZone = (minDistance / speed_) + (closestZone->getProcessTime());
      std::shared_ptr<SWTS> nearestSWTS = nullptr;
      double minSWTSDistance = std::numeric_limits<double>::max();

      // Encontrar la SWTS más cercana
      for (auto& station : transferStations) {
        double distToSWTS = distances[closestZone->getId()][station->getId()];
        if (distToSWTS < minSWTSDistance) {
          minSWTSDistance = distToSWTS;
          nearestSWTS = station;
        }
      }
      if (!nearestSWTS) {
        break; // Si no hay SWTS, terminamos
      }

      // Calcular el tiempo total de la ruta
      double travelTimeToSWTS = minSWTSDistance / speed_;
      double travelTimeToDepot = distances[nearestSWTS->getId()][depot->getId()] / speed_;
      double totalTime = travelTimeToZone + travelTimeToSWTS + travelTimeToDepot;

      // Verificar si la zona puede ser asignada al vehículo
      if (closestZone->getDemand() <= vehicle.getRemainingLoad() && totalTime <= vehicle.getRemainingTime()) {
        // Agregar la zona a la ruta
        vehicle.addZoneToRoute(closestZone);
        vehicle.addLoad(closestZone->getDemand());
        vehicle.addTime(travelTimeToZone);

        // Eliminar la zona de la lista de zonas
        collectionZones.erase(std::remove_if(collectionZones.begin(), collectionZones.end(),
          [&closestZone](const std::shared_ptr<CollectionZone>& zone) { return *zone == *closestZone; }), collectionZones.end());
      } else {
        if (totalTime <= vehicle.getRemainingTime()) {
          // Calcular la SWTS más cercana
          double minSWTSDistance = std::numeric_limits<double>::max();
          for (auto& station : transferStations) {
            double distToSWTS = distances[vehicle.getLastZone()->getId()][station->getId()];
            if (distToSWTS < minSWTSDistance) {
              minSWTSDistance = distToSWTS;
              nearestSWTS = station;
            }
          }
          if (!nearestSWTS) {
            break; // Si no hay SWTS, terminamos
          }
          // Visitar la SWTS más cercana
          double travelTimeToSWTS = minSWTSDistance / speed_;
          vehicle.addZoneToRoute(nearestSWTS);
          vehicle.addTime(travelTimeToSWTS);
          vehicle.resetLoad();

        } else {
          break;
        }
      }
    }

    // Asegurarse de que la ruta termine en una SWTS antes de regresar al depósito
    if (vehicle.getLastZone()) {
      bool lastIsSWTS = false;
      for (const auto& station : transferStations) {
        if (*vehicle.getLastZone() == *station) {
          lastIsSWTS = true;
          break;
        }
      }
      if (!lastIsSWTS) {
        // Busca la SWTS más cercana al último punto de la ruta
        std::shared_ptr<SWTS> nearestSWTS = nullptr;
        double minSWTSDistance = std::numeric_limits<double>::max();

        for (auto& station : transferStations) {
          double distToSWTS = distances[vehicle.getLastZone()->getId()][station->getId()];
          if (distToSWTS < minSWTSDistance) {
            minSWTSDistance = distToSWTS;
            nearestSWTS = station;
          }
        }
        if (nearestSWTS) {
          vehicle.addZoneToRoute(nearestSWTS);
        }
      }
    }
    // Regresar al depósito
    vehicle.addZoneToRoute(depot);
    vehiclesWithRoutes.push_back(vehicle);
  }
  return vehiclesWithRoutes;
}

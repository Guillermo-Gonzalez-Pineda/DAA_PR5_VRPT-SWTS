#include "../include/recolection-grasp-strategy.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <random>

std::vector<CollectionVehicle> RecolectionGRASPStrategy::computeRoutes(
      std::vector<std::shared_ptr<CollectionZone>>& collectionZones,
      std::vector<std::shared_ptr<SWTS>>& transferStations,
      const std::shared_ptr<Location>& depot,
      std::vector<std::vector<double>>& distances) {

  std::vector<CollectionVehicle> vehiclesWithRoutes;
  int vehicleId = 1;
  
  // Inicializamos el generador de números aleatorios
  std::random_device rd;
  std::mt19937 gen(rd());
  
  while (!collectionZones.empty()) {
    // Crear nuevo vehículo
    CollectionVehicle vehicle(vehicleId++, vehicleCapacity_, maxRouteTime_);
    vehicle.addZoneToRoute(depot); // Inicializar la ruta con el depósito

    while (true) {
      // Calcular las distancias desde la última ubicación del vehículo a todas las zonas
      std::vector<std::pair<std::shared_ptr<CollectionZone>, double>> zoneDistances;
      for (auto& zone : collectionZones) {
        double distance = distances[vehicle.getLastZone()->getId()][zone->getId()];
        zoneDistances.emplace_back(zone, distance);
      }

      // Ordenar las zonas por distancia
      std::sort(zoneDistances.begin(), zoneDistances.end(),
                [](const auto& a, const auto& b) { return a.second < b.second; });

      // Construir la LRC con un tamaño fijo
      std::vector<std::shared_ptr<CollectionZone>> candidateList;
      for (size_t i = 0; i < std::min(static_cast<size_t>(lrcSize_), zoneDistances.size()); ++i) {
        candidateList.push_back(zoneDistances[i].first);
      }

      // Seleccionar una zona aleatoriamente de la LRC
      std::shared_ptr<CollectionZone> selectedZone = nullptr;
      if (!candidateList.empty()) {
        std::uniform_int_distribution<> dis(0, candidateList.size() - 1);
        selectedZone = candidateList[dis(gen)];
      }

      if (!selectedZone) {
        break; // Si no hay zona seleccionada, terminamos
      }

      // Calcular el tiempo necesario para visitar la zona, una SWTS y volver al depósito
      double travelTimeToZone = (distances[vehicle.getLastZone()->getId()][selectedZone->getId()] / speed_) + 
                                (selectedZone->getProcessTime());
      std::shared_ptr<SWTS> nearestSWTS = nullptr;
      double minSWTSDistance = std::numeric_limits<double>::max();

      // Encontrar la SWTS más cercana a la zona seleccionada
      for (auto& station : transferStations) {
        double distToSWTS = distances[selectedZone->getId()][station->getId()];
        if (distToSWTS < minSWTSDistance) {
          minSWTSDistance = distToSWTS;
          nearestSWTS = station;
        }
      }
      if (!nearestSWTS) {
        break; // Si no hay SWTS, terminamos
      }

      // Calcular tiempos: desde la zona a la SWTS y desde la SWTS al depósito
      double travelTimeToSWTS = minSWTSDistance / speed_;
      double travelTimeToDepot = distances[nearestSWTS->getId()][depot->getId()] / speed_;
      double totalTime = travelTimeToZone + travelTimeToSWTS + travelTimeToDepot;

      // Verificar si la zona puede ser asignada al vehículo
      if (selectedZone->getDemand() <= vehicle.getRemainingLoad() && totalTime <= vehicle.getRemainingTime()) {
        // Agregar la zona a la ruta
        vehicle.addZoneToRoute(selectedZone);
        vehicle.addLoad(selectedZone->getDemand());
        vehicle.addTime(travelTimeToZone);

        // Eliminar la zona de la lista de zonas
        collectionZones.erase(std::remove_if(collectionZones.begin(), collectionZones.end(),
          [&selectedZone](const std::shared_ptr<CollectionZone>& zone) { return *zone == *selectedZone; }), collectionZones.end());
      } else {
        if (totalTime <= vehicle.getRemainingTime()) {
          // Recalcular la SWTS más cercana desde la última ubicación del vehículo
          minSWTSDistance = std::numeric_limits<double>::max();
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
          travelTimeToSWTS = minSWTSDistance / speed_;
          vehicle.addZoneToRoute(nearestSWTS);
          vehicle.addTime(travelTimeToSWTS);
          vehicle.resetLoad();

        } else {
          // Si no se puede visitar la zona ni la SWTS, terminamos la ruta
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

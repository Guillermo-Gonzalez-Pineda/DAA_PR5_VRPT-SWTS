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
      // Primero, recorrer todas las zonas para determinar la distancia mínima y máxima desde la última ubicación del vehículo.
      double minDistance = std::numeric_limits<double>::max();
      double maxDistance = 0.0;
      for (auto& zone : collectionZones) {
        double distance = distances[vehicle.getLastZone()->getId()][zone->getId()];
        if (distance < minDistance) {
          minDistance = distance;
        }
        if (distance > maxDistance) {
          maxDistance = distance;
        }
      }
      
      // Si no se encontró ninguna zona (debería ser redundante), terminamos
      if (minDistance == std::numeric_limits<double>::max())
        break;
      
      // Definir el umbral para la RCL
      double threshold = minDistance + alpha_ * (maxDistance - minDistance);
      
      // Construir la RCL: todas las zonas con distancia <= threshold
      std::vector<std::shared_ptr<CollectionZone>> candidateList;
      for (auto& zone : collectionZones) {
        double distance = distances[vehicle.getLastZone()->getId()][zone->getId()];
        if (distance <= threshold) {
          candidateList.push_back(zone);
        }
      }
      
      // Si la lista de candidatos está vacía, usamos la zona más cercana (por seguridad)
      std::shared_ptr<CollectionZone> selectedZone = nullptr;
      if (!candidateList.empty()) {
        std::uniform_int_distribution<> dis(0, candidateList.size() - 1);
        selectedZone = candidateList[dis(gen)];
      } else {
        // En principio no debería ocurrir, pero se asigna la zona más cercana
        for (auto& zone : collectionZones) {
          double distance = distances[vehicle.getLastZone()->getId()][zone->getId()];
          if (distance == minDistance) {
            selectedZone = zone;
            break;
          }
        }
      }
      
      if (!selectedZone) {
        break; // Si no hay zona seleccionada, terminamos
      }

      // Calcular el tiempo necesario para visitar la zona, una SWTS y volver al depósito
      double travelTimeToZone = distances[vehicle.getLastZone()->getId()][selectedZone->getId()] / speed_;
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

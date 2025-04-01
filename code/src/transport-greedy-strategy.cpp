#include "../include/transport-greedy-strategy.h"
#include <algorithm>
#include <limits>
#include <vector>

std::vector<TransportVehicle*> TransportGreedyStrategy::computeTransportRoutes(
    std::vector<CollectionVehicle>& collectionVehicles,
    const std::shared_ptr<Location>& dumpsite,
    std::vector<std::vector<double>>& distances) {
  std::vector<TransportVehicle*> transportVehicles;  // Conjunto E de vehículos de transporte
  std::vector<Task> tasks;                          // Conjunto H de tareas

  // Extraer todas las tareas desde los vehículos de recolección
  for (auto& collectionVehicle : collectionVehicles) {
    for (const auto& task : collectionVehicle.getTasks()) {
      tasks.push_back(task);
    }
  }

  // Ordenar las tareas por tiempo de llegada
  std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
    return a.getTh() < b.getTh();
  });

  // Calcular la cantidad mínima de residuos a transportar
  double minWaste = std::numeric_limits<double>::max();
  for (const auto& task : tasks) {
    if (task.getWasteAmount() < minWaste) {
      minWaste = task.getWasteAmount();
    }
  }

  double thPrev = 0;  // Inicialmente no hay tarea anterior
  std::shared_ptr<Location> lastSWTS = dumpsite;

  // Procesar cada tarea
  while (!tasks.empty()) {
    Task currentTask = tasks.front();
    tasks.erase(tasks.begin());  // Eliminar la tarea actual de la lista

    // Buscar un vehículo de transporte adecuado
    TransportVehicle* selectedVehicle = ChooseVehicle(
        transportVehicles, currentTask, thPrev, *lastSWTS, distances);

    // Si no hay vehículo disponible, crear uno nuevo
    if (!selectedVehicle) {
      selectedVehicle = new TransportVehicle(transportVehicles.size() + 1,
                                             vehicleCapacity_, maxRouteTime_, dumpsite);
      transportVehicles.push_back(selectedVehicle);

      // Inicia su ruta en el vertedero
      selectedVehicle->addLocationToRoute(dumpsite);
    }

    // Asignar la tarea al vehículo seleccionado
    double travelTime = distances[selectedVehicle->getLastLocation()->getId()]
                                    [currentTask.getSWTS().getId()] / speed_;
    selectedVehicle->assignTask(currentTask.getWasteAmount(), currentTask.getSWTS(), travelTime);

    // Verificar si el vehículo debe regresar al vertedero
    if (selectedVehicle->getRemainingCapacity() < minWaste) {
      selectedVehicle->addLocationToRoute(dumpsite);
      selectedVehicle->resetLoad();
    }

    // Actualizar el tiempo de la tarea anterior
    thPrev = currentTask.getTh();
    lastSWTS = std::make_shared<Location>(currentTask.getSWTS());
  }

  // Asegurar que todas las rutas terminan en el vertedero
  for (auto& vehicle : transportVehicles) {
    if (vehicle->getLastLocation() != dumpsite) {
      vehicle->addLocationToRoute(dumpsite);
    }
  }

  return transportVehicles;  // Devolver el conjunto de vehículos de transporte
}


TransportVehicle* TransportGreedyStrategy::ChooseVehicle(
    std::vector<TransportVehicle*>& transportVehicles, 
    const Task& task,
    double thPrev,
    const Location& lastSWTS,
    const std::vector<std::vector<double>>& distances) {
  TransportVehicle* bestVehicle = nullptr;
  double bestInsertionCost = std::numeric_limits<double>::infinity();

  // Iterar sobre todos los vehículos
  for (auto& vehicle : transportVehicles) {
    // Calcular el tiempo de viaje desde la última ubicación del vehículo hasta la SWTS de la tarea
    double computedTravelTime = distances[vehicle->getLastLocation()->getId()][task.getSWTS().getId()] / speed_;

    // Verificar que el vehículo cumple las restricciones usando el objeto Task
    if (vehicle->canAssignTask(task.getWasteAmount(), task.getTh(), thPrev, lastSWTS, computedTravelTime)) {
      // Usamos el tiempo de viaje como costo de inserción
      if (computedTravelTime < bestInsertionCost) {
        bestInsertionCost = computedTravelTime;
        bestVehicle = vehicle;
      }
    }
  }
  return bestVehicle;
}
#include "../include/transport-vehicle.h"

// Constructor
TransportVehicle::TransportVehicle(int id, double capacity, double maxRouteTime, 
                                   const std::shared_ptr<Location>& dumpsite)
    : id_(id), capacity_(capacity), maxRouteTime_(maxRouteTime), currentLoad_(0), 
      currentTime_(0), route_(), tasks_(), dumpsite_(dumpsite) {}

// Método para agregar una ubicación a la ruta
void TransportVehicle::addLocationToRoute(const std::shared_ptr<Location>& location) {
  route_.push_back(location);
}

// Método para verificar si se puede asignar una tarea de transporte
bool TransportVehicle::canAssignTask(double Dh, double th, double thPrev, const Location& lastSWTS, double travelTimeToSh) const {
  // (a) Restricción de tiempo de viaje entre SWTS
  if (!route_.empty() && travelTimeToSh > (th - thPrev)) {
    return false;
  }

  // (b) Restricción de capacidad restante
  if (Dh > getRemainingCapacity()) {
    return false;
  }

  // (c) Restricción de tiempo total de la ruta incluyendo el retorno al vertedero
  double timeToDumpsite = lastSWTS.distanceTo(*dumpsite_) / speed_;
  if (currentTime_ + travelTimeToSh + timeToDumpsite > maxRouteTime_) {
    return false;
  }

  return true;
}

// Asigna una tarea al vehículo
void TransportVehicle::assignTask(double Dh, const SWTS& sh, double travelTimeToSh) {
    // Actualizar carga y tiempo
    currentLoad_ += Dh;
    currentTime_ += travelTimeToSh;

    // Agregar la SWTS a la ruta
    auto swtsPtr = std::make_shared<SWTS>(sh);
    addLocationToRoute(swtsPtr);

    // Registrar la tarea
    tasks_.emplace_back(Dh, swtsPtr, currentTime_);
}

// Reinicia la carga del vehículo
void TransportVehicle::resetLoad() {
  currentLoad_ = 0.0;
}


// Programa un viaje al vertedero
void TransportVehicle::returnToDumpsite() {
  if (route_.empty() || *route_.back() != *dumpsite_) {
    addLocationToRoute(dumpsite_);
  }
  resetLoad(); // Descargar residuos en el vertedero
}
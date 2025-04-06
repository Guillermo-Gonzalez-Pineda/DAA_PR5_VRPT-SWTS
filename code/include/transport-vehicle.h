#ifndef TRANSPORT_VEHICLE_H
#define TRANSPORT_VEHICLE_H

#include <vector>
#include <memory>
#include "location.h"
#include "collection-zone.h"
#include "task.h"
#include "solid-waste-transfer-station.h"

class TransportVehicle {
public:
    // Constructor
    TransportVehicle(int id, double capacity, double maxRouteTime, 
                     const std::shared_ptr<Location>& dumpsite);

    // Métodos getters
    int getId() const { return id_; }
    double getRemainingCapacity() const { return capacity_ - currentLoad_; }
    double getRemainingTime() const { return maxRouteTime_ - currentTime_; }
    const std::shared_ptr<Location> getLastLocation() const { return route_.empty() ? dumpsite_ : route_.back(); }
    const std::vector<std::shared_ptr<Location>>& getRoute() const { return route_; }
    double getCurrentLoad() const { return currentLoad_; }

    // Métodos para manejar tareas
    bool canAssignTask(double Dh, double th, double thPrev, const Location& lastSWTS, double travelTimeToSh) const;
    void assignTask(double Dh, const SWTS& sh, double travelTimeToSh);
    void returnToDumpsite();
    void addLocationToRoute(const std::shared_ptr<Location>& location);
    void resetLoad();

private:
    int id_;                                      // Identificador del vehículo
    double capacity_;                             // Capacidad máxima del vehículo
    double maxRouteTime_;                         // Tiempo máximo permitido para la ruta
    double currentLoad_ = 0.0;                    // Carga actual del vehículo
    double currentTime_ = 0.0;                    // Tiempo actual de la ruta
    std::vector<std::shared_ptr<Location>> route_; // Ruta del vehículo
    std::shared_ptr<Location> dumpsite_;          // Ubicación del vertedero
    std::vector<Task> tasks_;                     // Lista de tareas generadas
    double speed_ = 1.0;                          // Velocidad del vehículo (km/s)
    double totalLoad_ = 0.0;                      // Carga total transportada
    double totalTime_ = 0.0;                      // Tiempo total de la ruta

    // Métodos privados para encapsular la lógica de añadir carga y tiempo
    void addLoad(double load);
    void addTime(double time);
};

#endif // TRANSPORT_VEHICLE_H

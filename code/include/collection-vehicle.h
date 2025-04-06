#ifndef COLLECTION_VEHICLE_H
#define COLLECTION_VEHICLE_H

#include <vector>
#include <memory>
#include "location.h"
#include "collection-zone.h"
#include "solid-waste-transfer-station.h"
#include "task.h"

class CollectionVehicle {
  public:
    CollectionVehicle(int id, double capacity, double maxTime) 
      : id(id), capacity(capacity), maxTime(maxTime), remainingCapacity_(capacity), remainingTime_(maxTime), 
        totalLoad_(0), totalTime_(0), route_(), tasks_() {}
    
    // Métodos getters
    int getId() const { return id; }
    double getRemainingLoad() const { return remainingCapacity_; }
    double getMaxTime() const { return maxTime; }
    double getMaxCapacity() const { return capacity; }
    double getRemainingTime() const { return remainingTime_; }
    double getTotalLoad() const { return totalLoad_; } // Nuevo getter para la carga total
    double getTotalTime() const { return totalTime_; } // Nuevo getter para el tiempo total
    int getNumberOfZones() const { return route_.size(); }

    // Devuelve la última zona visitada, o nullptr si no hay ninguna
    std::shared_ptr<Location> getLastZone() const { 
      return route_.empty() ? nullptr : route_.back(); 
    }

    const std::vector<std::shared_ptr<Location>>& getRoute() const { return route_; }
    const std::vector<Task>& getTasks() const { return tasks_; }

    // Métodos setters
    void resetTime() { remainingTime_ = maxTime; }
    void resetLoad() { this->remainingCapacity_ = capacity; }
    void addLoad(double load) { 
      remainingCapacity_ -= load; 
      totalLoad_ += load;
    }
    void addTime(double time) { 
      this->remainingTime_ -= time; 
      totalTime_ += time;
    }

    // Métodos para agregar zonas a la ruta, ir a la estación de transferencia, etc.
    void addZoneToRoute(const std::shared_ptr<Location>& zone) {
      // Supongamos que `swts` es un std::shared_ptr<SWTS> asociado a la zona
      auto swts = std::dynamic_pointer_cast<SWTS>(zone);
      if (swts) {
        Task task(capacity - remainingCapacity_, swts, maxTime - remainingTime_);
        tasks_.push_back(task);
      }
      route_.push_back(zone);
    }

  private:
    int id;                                         // Identificador del vehículo
    double capacity;                                // Capacidad del vehículo en kg
    double maxTime;                                 // Tiempo máximo permitido para la ruta
    double remainingCapacity_;                      // Carga actual del vehículo
    double remainingTime_;                          // Tiempo actual de la ruta
    double totalLoad_;                              // Carga total acumulada
    double totalTime_;                              // Tiempo total acumulado
    std::vector<std::shared_ptr<Location>> route_;  // Zonas visitadas en la ruta (shared_ptr a Location)
    std::vector<Task> tasks_;                       // Lista de tareas generadas
};

#endif

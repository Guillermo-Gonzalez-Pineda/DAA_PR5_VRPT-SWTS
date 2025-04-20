#ifndef TASK_H
#define TASK_H

#include "solid-waste-transfer-station.h"
#include "collection-zone.h"
#include "route.h"
#include <memory>

class Task {
  public:
    Task(double Dh, std::shared_ptr<SWTS> swts, double th) : wasteAmount_(Dh), swts_(swts.get()), arrivalTime_(th) {}

    // Métodos getters
    double getWasteAmount() const { return wasteAmount_; }
    const SWTS& getSWTS() const { return *swts_; }
    double getArrivalTime() const { return arrivalTime_; }
    const std::vector<Route>& getSubRoutes() const { return subRoutes_; }
    void addSubRoute(const Route& route) { subRoutes_.push_back(route); }

    // Sobrecarga del operador <
    bool operator<(const Task& other) const {
      return this->arrivalTime_ < other.arrivalTime_;
    }

  private:
    double wasteAmount_; // Cantidad de residuos transportados
    const SWTS* swts_;   // Estación de transferencia de residuos
    double arrivalTime_; // Tiempo de llegada de los residuos
    std::vector<Route> subRoutes_; // Subrutas asociadas a la tarea
};

#endif
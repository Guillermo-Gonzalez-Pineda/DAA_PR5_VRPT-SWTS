#ifndef TRANSPORT_GREEDY_STRATEGY_H
#define TRANSPORT_GREEDY_STRATEGY_H

#include <vector>
#include <memory>
#include "collection-vehicle.h"
#include "transport-vehicle.h"
#include "solid-waste-transfer-station.h"

class TransportGreedyStrategy {
  public:
    TransportGreedyStrategy(double vehicleCapacity, double maxRouteTime, double speed)
        : vehicleCapacity_(vehicleCapacity), maxRouteTime_(maxRouteTime), speed_(speed) {}

    std::vector<TransportVehicle*> computeTransportRoutes(
        std::vector<CollectionVehicle>& collectionVehicles,
        std::vector<std::shared_ptr<SWTS>>& transferStations,
        const std::shared_ptr<Location>& dumpsite,
        std::vector<std::vector<double>>& distances);

  private:
    double vehicleCapacity_;  // Capacidad máxima de los vehículos de transporte
    double maxRouteTime_;     // Duración máxima de la ruta
    double speed_;            // Velocidad de los vehículos de transporte

    TransportVehicle* ChooseVehicle(std::vector<TransportVehicle*>& transportVehicles, 
      const Task& task, 
      double thPrev, 
      const Location& lastSWTS, 
      double travelTimeToSh,
      const std::vector<std::vector<double>>& distances);

};

#endif // TRANSPORT_GREEDY_STRATEGY_H

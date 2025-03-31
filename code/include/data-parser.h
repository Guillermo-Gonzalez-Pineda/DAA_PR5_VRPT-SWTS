#ifndef DATAPARSER_H
#define DATAPARSER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>  // Incluir para punteros inteligentes
#include "collection-zone.h"
#include "location.h"
#include "solid-waste-transfer-station.h"

class DataParser {
  public:
    DataParser(const std::string& filename);

    // Getters
    const std::vector<std::shared_ptr<CollectionZone>>& getCollectionZones() const { return collectionZones_; }
    const std::vector<std::shared_ptr<SWTS>>& getTransferStations() const { return transferStations_; }
    double getMaxCollectionRouteTime() const { return maxCollectionRouteTime_; }
    double getMaxTransportationRouteTime() const { return maxTransportationRouteTime_; }
    int getMaxVehicles() const { return maxVehicles_; }
    int getNumZones() const { return numZones_; }
    double getCollectionVehicleCapacity() const { return collectionVehicleCapacity_; }
    double getTransportVehicleCapacity() const { return transportVehicleCapacity_; }
    double getSpeed() const { return speed_; }
    std::shared_ptr<Location> getDepot() const { return depot_; }
    std::shared_ptr<Location> getDumpsite() const { return dumpsite_; }
    const std::vector<std::vector<double>>& getDistances() const { return distances_; }

  private:
    double maxCollectionRouteTime_;
    double maxTransportationRouteTime_;
    int maxVehicles_;
    int numZones_;
    double collectionVehicleCapacity_;
    double transportVehicleCapacity_;
    double speed_;
    std::shared_ptr<Location> depot_;  // Usamos std::shared_ptr
    std::shared_ptr<Location> dumpsite_;  // Usamos std::shared_ptr
    std::vector<std::shared_ptr<CollectionZone>> collectionZones_;  // Usamos punteros inteligentes
    std::vector<std::shared_ptr<SWTS>> transferStations_;  // Usamos punteros inteligentes
    std::vector<std::vector<double>> distances_;

    void parseFile(const std::string& filename);
    void computeDistances();
};

#endif // DATAPARSER_H

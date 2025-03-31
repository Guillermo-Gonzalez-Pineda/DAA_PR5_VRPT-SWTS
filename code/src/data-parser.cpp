#include "../include/data-parser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <memory>  // Incluir para punteros inteligentes

// Constructor que inicializa el parseo
DataParser::DataParser(const std::string& filename)
    : maxCollectionRouteTime_(0),
      maxTransportationRouteTime_(0),
      maxVehicles_(0),
      numZones_(0),
      collectionVehicleCapacity_(0),
      transportVehicleCapacity_(0),
      speed_(0),
      depot_(nullptr),
      dumpsite_(nullptr),
      collectionZones_(),
      transferStations_(),
      distances_() {
  parseFile(filename);
  computeDistances();
}

// Método para parsear el archivo de entrada
void DataParser::parseFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("No se pudo abrir el archivo: " + filename);
  }
  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string key;
    iss >> key;
    if (key == "L1") {
      iss >> maxCollectionRouteTime_;
    } else if (key == "L2") {
      iss >> maxTransportationRouteTime_;
    } else if (key == "num_vehicles") {
      iss >> maxVehicles_;
    } else if (key == "num_zones") {
      iss >> numZones_;
    } else if (key == "Q1") {
      iss >> collectionVehicleCapacity_;
    } else if (key == "Q2") {
      iss >> transportVehicleCapacity_;
    } else if (key == "V") {
      double speedHours;
      iss >> speedHours;
      speed_ = speedHours / 60; // Convertir a km/s
    } else if (key == "Depot") {
      double x, y;
      iss >> x >> y;
      depot_ = std::make_shared<Location>(x, y, -1);  // Usamos make_shared
    } else if (key == "IF" || key.find("IF") == 0) {
      double x, y;
      iss >> x >> y;
      transferStations_.emplace_back(std::make_shared<SWTS>(-1, x, y));  // Usamos make_shared
    } else if (key == "Dumpsite") {
      double x, y;
      iss >> x >> y;
      dumpsite_ = std::make_shared<Location>(x, y, -1);  // Usamos make_shared
    } else if (isdigit(key[0])) {
      double x, y, d1, d2;
      iss >> x >> y >> d1 >> d2;
      collectionZones_.emplace_back(std::make_shared<CollectionZone>(-1, x, y, d1, d2));  // Usamos make_shared
    }
  }
}

// Método para calcular las distancias entre ubicaciones
void DataParser::computeDistances() {
  std::vector<std::shared_ptr<Location>> allLocations;
  allLocations.push_back(depot_);
  for (auto& zone : collectionZones_) {
    allLocations.push_back(zone);
  }
  for (auto& station : transferStations_) {
    allLocations.push_back(station);
  }
  allLocations.push_back(dumpsite_);
  distances_.resize(allLocations.size(), std::vector<double>(allLocations.size(), 0));

  for (size_t i = 0; i < allLocations.size(); ++i) {
    for (size_t j = 0; j < allLocations.size(); ++j) {
      if (i != j) {
        distances_[i][j] = allLocations[i]->distanceTo(*allLocations[j]);
      }
    }
    allLocations[i]->setId(i);
  }
}

#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <limits>
#include "location.h"
#include "collection-zone.h"
#include "solid-waste-transfer-station.h"

#ifndef ROUTE_H
#define ROUTE_H

class Route {
  public:
    // Constructor por defecto
    Route() : totalDistance_(0.0) {}

    Route(const std::vector<std::shared_ptr<Location>>& positions, double totalDistance)
        : positions_(positions), totalDistance_(totalDistance) {}

    // Método para obtener la distancia total de la ruta
    double getTotalDistance() const {
      return totalDistance_;
    }
    // Método para obtener la ruta 
    const std::vector<std::shared_ptr<Location>>& getPositions() const {
      return positions_;
    }

    // Añade una zona en una posición dada. Si 'position' es mayor o igual que el tamaño actual, se añade al final.
    void addZone(const std::shared_ptr<Location>& loc, size_t position = std::numeric_limits<size_t>::max()) {
      if (position >= positions_.size()) {
        positions_.push_back(loc);
      } else {
        positions_.insert(positions_.begin() + position, loc);
      }
    }

    // Método para eliminar una zona en una posición dada
    void removeZone(size_t position) {
      if (position < positions_.size()) {
        positions_.erase(positions_.begin() + position);
      }
    }

    // Calcula el tiempo total de la ruta
    double calculateTotalTime(double speed) const {
      double totalTime = 0.0;
      if (positions_.empty()) {
        return totalTime;
      }
      for (size_t i = 0; i < positions_.size() - 1; ++i) {
        totalTime += positions_[i]->distanceTo(*positions_[i + 1]) / speed;

        // Si la siguiente posicion es una zona de recolección, añade el tiempo de procesamiento
        std::shared_ptr<CollectionZone> zone = std::dynamic_pointer_cast<CollectionZone>(positions_[i + 1]);
        if (zone) {
          totalTime += zone->getProcessTime();
        }
      }
      return totalTime;
    }

  private:
    std::vector<std::shared_ptr<Location>> positions_; // Lista de ubicaciones en la ruta
    double totalDistance_;                             // Distancia total de la ruta
};

#endif // ROUTE_H
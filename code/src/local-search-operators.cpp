#include "../include/local-search-operators.h"

#include <algorithm>
#include <limits>
#include <iostream>

double LocalSearchOperators::isFeasible(const Route &r, double speed, double maxRouteTime, double maxLoad, const std::vector<std::vector<double>> & distances) {
    double totalTime = 0.0;
    double currentLoad = 0.0;
    const auto& positions = r.getPositions();

    // Recorremos la ruta desde el primer elemento hasta el penúltimo
    for (size_t i = 0; i < positions.size() - 1; ++i) {
      // Calculamos el tiempo de viaje entre dos posiciones usando la matriz de distancias
      totalTime += distances[positions[i]->getId()][positions[i + 1]->getId()] / speed;

      // Comprobar si la siguiente posición es una zona de recolección
      std::shared_ptr<CollectionZone> zone = std::dynamic_pointer_cast<CollectionZone>(positions[i + 1]);
      if (zone) {
        // Añadimos el tiempo de procesamiento de la zona y actualizamos la carga
        totalTime += zone->getProcessTime();
        currentLoad += zone->getDemand();
      } else {
        // Si no es una zona de recolección, verificamos si es una estación de transferencia.
        std::shared_ptr<SWTS> swts = std::dynamic_pointer_cast<SWTS>(positions[i + 1]);
        if (swts) {
          currentLoad = 0.0;
        }
      }
      if (currentLoad > maxLoad) {
        return -1; // Carga excede la capacidad máxima
      }
    }
}
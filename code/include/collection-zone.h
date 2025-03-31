/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Diseño y Análisis de Algoritmos
 * Curso: 3º
 * Práctica 5: (VRPT-SWTS)
 * 
 * @autor Guillermo González Pineda
 * @email alu0101574899@ull.edu.es
 * @date 24/03/2025
 * @file collection-zone.h: archivo que contiene la cabecera de la clase CollectionZone
 * @brief Contiene la cabecera de la clase CollectionZone del programa que resuelve el problema del VRPT-SWTS
 */

#ifndef COLLECTION_ZONE_H
#define COLLECTION_ZONE_H

#include <vector>
#include "location.h"

class CollectionZone : public Location {
  public:
    // Constructor
    CollectionZone(int id, double x, double y, double D1, double D2) : Location(x, y, id), demand_(D2 - D1) {}
    CollectionZone(int id, double x, double y, double demand) : Location(x, y, id), demand_(demand) {}

    // Métodos getter
    int getId() const { return Location::getId(); }
    double getDemand() const { return demand_; }

    // Sobrecarga del operador ==
    bool operator==(const CollectionZone& other) const {
      return this->getId() == other.getId();
    }

  private:
    double demand_;  // Demanda calculada (D2 - D1)
};

#endif
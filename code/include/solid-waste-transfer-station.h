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
 * @file solid-waste-transfer-station.h: archivo que contiene la cabecera de la clase SolidWasteTransferStation
 * @brief Contiene la cabecera de la clase SolidWasteTransferStation del programa que resuelve el problema del VRPT-SWTS
 */

#ifndef SOLID_WASTE_TRANSFER_STATION_H
#define SOLID_WASTE_TRANSFER_STATION_H

#include <vector>
#include "location.h"
#include "collection-zone.h"

class SWTS : public Location {
  public:
    SWTS(int id, double x, double y) : Location(x, y, id) {}

    // Sobrecarga del operador == para comparar con Location
    bool operator==(const Location& other) const {
      return this->getId() == other.getId();
    }

  private:
    int totalWaste = 0;
};

#endif
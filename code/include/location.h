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
 * @file location.h: archivo que contiene la cabecera de la clase Location
 * @brief Contiene la cabecera de la clase Location del programa que resuelve el problema del VRPT-SWTS
 */

 #ifndef LOCATION_H
 #define LOCATION_H

 #include <cmath>
 #include <utility>
#include <string>

class Location {
  public:
    Location(double x = 0, double y = 0, int id = -1) : coordenateX_(x), coordenateY_(y), id_(id) {}
    virtual ~Location() = default; // Destructor virtual para hacer la clase polimórfica

    // Métodos getters
    double getX() const { return coordenateX_; }
    double getY() const { return coordenateY_; }
    int getId() const { return id_; }

    // Calcular la distancia entre dos ubicaciones
    double distanceTo(const Location& other) const {
      return sqrt(pow(coordenateX_ - other.coordenateX_, 2) + pow(coordenateY_ - other.coordenateY_, 2));
    }

    // Establecer nuevas coordenadas
    void setLocation(double newX, double newY) {
      coordenateX_ = newX;
      coordenateY_ = newY;
    }
    // Establecer un nuevo id
    void setId(int newId) {
      id_ = newId;
    }

    // Sobrecarga del operador ==
    bool operator==(const Location& other) const {
      return this->id_ == other.id_;
    }

    // Sobrecarga del operador !=
    bool operator!=(const Location& other) const {
      return !(*this == other);
    }

  private:
    double coordenateX_, coordenateY_;
    int id_;
  };


#endif
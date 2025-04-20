#ifndef LOCAL_SEARCH_OPERATORS_H
#define LOCAL_SEARCH_OPERATORS_H

#include <vector>
#include <memory>
#include "route.h"

class LocalSearchOperators {
public:
  /**
   * Aplica el movimiento de reinserción (reinsertion) sobre la ruta.
   * Se busca, de forma iterativa, mejorar la ruta moviendo cada elemento (excepto el primer y último)
   * a otra posición.
   * @param original Ruta original.
   * @param speed Velocidad del vehículo.
   * @param tiempoAnterior Tiempo total de la ruta antes del movimiento.
   * @param maxRouteTime Tiempo máximo permitido para la ruta.
   * @param maxLoad Carga máxima permitida.
   * @param distances Matriz de distancias.
   * @return Nueva ruta después de aplicar el movimiento de reinserción, si se mejora; de lo contrario,
   *         devuelve la ruta original.
   */
  static Route reinsercion(const Route &original, double speed, double tiempoAnterior, double maxRouteTime, double maxLoad, const std::vector<std::vector<double>> & distances);

  /**
   * Aplica el movimiento de intercambio (interchange) sobre la ruta.
   * Se busca, de forma iterativa, mejorar la ruta intercambiando dos elementos (excepto el primer y último).
   * @param original Ruta original.
   * @param speed Velocidad del vehículo.
   * @param tiempoAnterior Tiempo total de la ruta antes del movimiento.
   * @param maxRouteTime Tiempo máximo permitido para la ruta.
   * @param maxLoad Carga máxima permitida.
   * @param distances Matriz de distancias.
   * @return Nueva ruta después de aplicar el movimiento de intercambio, si se mejora; de lo contrario,
   *         devuelve la ruta original.
   */
  static Route intercambio(const Route &original, double speed, double tiempoAnterior, double maxRouteTime, double maxLoad, const std::vector<std::vector<double>> & distances);

  /**
   * Verifica si la ruta es factible.
   * @param r Ruta a verificar.
   * @param speed Velocidad del vehículo.
   * @param maxRouteTime Tiempo máximo permitido para la ruta.
   * @param maxLoad Carga máxima permitida.
   * @param distances Matriz de distancias.
   * @return El tiempo total de la ruta si es factible, o -1 si no lo es.
   */
  static double isFeasible(const Route &r, double speed, double maxRouteTime, double maxLoad, const std::vector<std::vector<double>> & distances);

  /**
   * Compara el tiempo anterior y el tiempo nuevo para determinar si la nueva ruta es mejor.
   * @param tiempoAnterior Tiempo antes del movimiento.
   * @param tiempoNuevo Tiempo después del movimiento.
   * @return true si la nueva ruta es mejor (menor tiempo) que la anterior.
   */
  static bool isBetter(double tiempoAnterior, double tiempoNuevo);
};

#endif // LOCAL_SEARCH_OPERATORS_H

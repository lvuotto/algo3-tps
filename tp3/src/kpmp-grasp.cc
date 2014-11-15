#include "kpmp-grasp.h"

using namespace std;

Particion kpmp_grasp(Particion (*greedy)(Grafo& grafo, unsigned int cantidad_de_conjuntos, unsigned int random_aristas, unsigned int random_conjuntos, unsigned int seed),
  void (*local)(Particion& particion), Grafo& grafo, unsigned int cantidad_de_conjuntos,
  CriterioDeTerminacion criterio, unsigned int repeticiones,
  unsigned int random_aristas, unsigned int random_conjuntos, unsigned int seed)
{
  Particion particion = greedy(grafo, cantidad_de_conjuntos, random_aristas, random_conjuntos, seed);
  local(particion);
  double peso_min = particion.peso();

  if (criterio == MEJOR_LUEGO_DE_X_VECES) {
    for (unsigned int i = 1; i < repeticiones; i++) {
      Particion nueva_particion = greedy(grafo, cantidad_de_conjuntos, random_aristas, random_conjuntos, seed);
      local(nueva_particion);

      if (nueva_particion.peso() < peso_min) {
        peso_min = nueva_particion.peso();
        particion = nueva_particion;
      }
    }
  } else if (criterio == CUANDO_EL_MEJOR_SE_REPITA_X_VECES) {
    unsigned int contador_repeticiones = 1;

    while (contador_repeticiones < repeticiones) {
      Particion nueva_particion = greedy(grafo, cantidad_de_conjuntos, random_aristas, random_conjuntos, seed);
      local(nueva_particion);

      if (nueva_particion.peso() < peso_min) {
        peso_min = nueva_particion.peso();
        particion = nueva_particion;
        contador_repeticiones = 1;
      } else if (nueva_particion.peso() == peso_min) {
        contador_repeticiones++;
      }
    }
  }

  return particion;
}

#ifndef KPMP_GRASP_H
#define KPMP_GRASP_H

#include <algorithm>
#include "kpmp.h"

enum CriterioDeTerminacion {MEJOR_LUEGO_DE_X_VECES, CUANDO_EL_MEJOR_SE_REPITA_X_VECES};

using namespace std;

Particion kpmp_grasp(Particion (*greedy)(Grafo& grafo, unsigned int cantidad_de_conjuntos, unsigned int random_aristas, unsigned int random_conjuntos, unsigned int seed),
  void (*local)(Particion& particion), Grafo& grafo, unsigned int cantidad_de_conjuntos,
  CriterioDeTerminacion criterio, unsigned int repeticiones,
  unsigned int random_aristas, unsigned int random_conjuntos, unsigned int seed);

#endif

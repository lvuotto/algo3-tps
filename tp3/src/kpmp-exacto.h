#ifndef KPMP_EXACTO_H
#define KPMP_EXACTO_H

#include <stack>
#include "kpmp.h"

using namespace std;

Particion kpmp_exacto(Grafo& grafo, unsigned int cantidad_de_conjuntos);
void      backtracking(Particion& particion, Particion& particion_min, stack<unsigned int>& vertices_pendientes, double& peso_min);

#endif

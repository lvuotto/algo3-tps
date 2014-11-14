#ifndef KPMP_HG_H
#define KPMP_HG_H

#include <algorithm>
#include "kpmp.h"
#include "shuffle_vector.h"

#ifndef RANDOM_ARISTAS
#define RANDOM_ARISTAS 10
#endif

#ifndef RANDOM_CONJUNTOS
#define RANDOM_CONJUNTOS 10
#endif


using namespace std;

Particion kpmp_hg(Grafo& grafo, unsigned int cantidad_de_conjuntos);
Particion kpmp_hg_random_aristas(Grafo& grafo, unsigned int cantidad_de_conjuntos);
Particion kpmp_hg_random_conjuntos(Grafo& grafo, unsigned int cantidad_de_conjuntos);
Particion kpmp_hg_random_aristas_conjuntos(Grafo& grafo, unsigned int cantidad_de_conjuntos);
void      agregar_al_de_menos_peso(Particion& particion, unsigned int vertice);
void      agregar_al_de_menos_peso_random(Particion& particion, unsigned int vertice);
bool      sort_pair(pair<unsigned int, double> a, pair<unsigned int, double> b);

#endif

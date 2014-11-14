#ifndef KPMP_H
#define KPMP_H

#include <vector>
#include "grafo.h"
#include "conjunto_de_vertices.h"
#include "particion.h"

using namespace std;

enum Algortimo {EXACTO, GOLOSO, LOCAL, GRASP};
enum EstrategiaVertices {MOVER, INTERCAMBIAR};
enum EstrategiaRandomizar {NADA, ARISTAS, CONJUNTOS, AMBOS};

struct Entrada {
  Grafo grafo;
  unsigned int cantidad_de_conjuntos;

  Entrada(Grafo grafo_, unsigned int cantidad_de_conjuntos);
};

Entrada leer_entrada();

Particion leer_solucion(Grafo& grafo, unsigned int cantidad_de_conjuntos);

void imprimir_particion(Particion& particion);

vector<unsigned int> particion_a_solucion(Particion& particion);

void imprimir_uso();

#endif

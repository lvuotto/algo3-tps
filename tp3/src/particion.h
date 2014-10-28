#ifndef PARTICION_H
#define PARTICION_H

#include <vector>
#include "grafo.h"
#include "conjunto_de_vertices.h"

using namespace std;

struct Particion {
  Particion(Grafo& grafo, unsigned int cantidad_de_conjuntos);
  double peso() const;
  unsigned int cantidad_nodos();
  vector<ConjuntoDeVertices> conjuntos;

private:
  Grafo& grafo_;
  double peso_;
};

#endif

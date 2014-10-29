#ifndef PARTICION_H
#define PARTICION_H

#include <vector>
#include "grafo.h"
#include "conjunto_de_vertices.h"

using namespace std;

struct Particion {
  Particion(Grafo& grafo, unsigned int cantidad_de_conjuntos);
  double peso() const;
  unsigned int cantidad_de_vertices();
  unsigned int cantidad_de_conjuntos();
  double costo(unsigned int conjunto, unsigned int vertice);
  void agregar_vertice(unsigned int conjunto, unsigned int vertice);
  set<unsigned int>::iterator begin(unsigned int conjunto);
  set<unsigned int>::iterator end(unsigned int conjunto);

  vector<ConjuntoDeVertices> conjuntos;

private:
  Grafo& grafo_;
  double peso_;
  unsigned int cantidad_de_conjuntos_;
};

#endif

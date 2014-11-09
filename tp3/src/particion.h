#ifndef PARTICION_H
#define PARTICION_H

#include <vector>
#include "grafo.h"
#include "conjunto_de_vertices.h"

using namespace std;

struct Particion {
  Particion(Grafo& grafo, unsigned int cantidad_de_conjuntos);
  double                      peso() const;
  unsigned int                cantidad_de_vertices();
  unsigned int                cantidad_de_conjuntos();
  double                      costo(unsigned int conjunto, unsigned int vertice);
  void                        agregar_vertice(unsigned int conjunto, unsigned int vertice);
  void                        sacar_vertice(unsigned int conjunto, unsigned int vertice);
  set<unsigned int>::iterator begin(unsigned int conjunto);
  set<unsigned int>::iterator end(unsigned int conjunto);
  unsigned int                conjunto_del_vertice(unsigned int vertice);
  bool                        contiene_a(unsigned int vertice);
  void                        operator=(Particion particion);

private:
  vector<ConjuntoDeVertices> conjuntos_;
  Grafo& grafo_;
  double peso_;
  unsigned int cantidad_de_conjuntos_;
  vector<bool> vertices_;
};

#endif

#ifndef CONJUNTO_DE_VERTICES_H
#define CONJUNTO_DE_VERTICES_H

#include <set>
#include "grafo.h"

using namespace std;

struct ConjuntoDeVertices {
  ConjuntoDeVertices(Grafo& grafo);
  void agregar_vertice(unsigned int vertice);
  void sacar_vertice(unsigned int vertice);
  bool vacio() const;
  double peso() const;
  double costo(unsigned int vertice) const;
  set<unsigned int>::iterator begin();
  set<unsigned int>::iterator end();

private:
  Grafo& grafo_;
  set<unsigned int> vertices_;
  double peso_;
};

#endif

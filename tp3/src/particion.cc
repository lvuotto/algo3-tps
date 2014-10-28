#include <vector>
#include "particion.h"


Particion::Particion(Grafo& grafo, unsigned int cantidad_de_conjuntos) :
  conjuntos(cantidad_de_conjuntos, ConjuntoDeVertices(grafo)), grafo_(grafo), peso_(0.0)
  {}

double Particion::peso() const
{
  return peso_;
}

unsigned int Particion::cantidad_nodos() {
  return grafo_.cantidad_nodos();
}

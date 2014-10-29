#include <vector>
#include "particion.h"


Particion::Particion(Grafo& grafo, unsigned int cantidad_de_conjuntos) :
  conjuntos(cantidad_de_conjuntos, ConjuntoDeVertices(grafo)), grafo_(grafo), peso_(0.0), cantidad_de_conjuntos_(cantidad_de_conjuntos)
  {}


double Particion::peso() const
{
  return peso_;
}


unsigned int Particion::cantidad_de_vertices()
{
  return grafo_.cantidad_de_vertices();
}


unsigned int Particion::cantidad_de_conjuntos()
{
  return cantidad_de_conjuntos_;
}


double Particion::costo(unsigned int conjunto, unsigned int vertice)
{
  return conjuntos[conjunto].costo(vertice);
}


void Particion::agregar_vertice(unsigned int conjunto, unsigned int vertice)
{
  conjuntos[conjunto].agregar_vertice(vertice);
}


set<unsigned int>::iterator Particion::begin(unsigned int conjunto)
{
  return conjuntos[conjunto].begin();
}


set<unsigned int>::iterator Particion::end(unsigned int conjunto)
{
  return conjuntos[conjunto].end();
}

#include <vector>
#include "particion.h"


Particion::Particion(Grafo& grafo, unsigned int cantidad_de_conjuntos) :
  conjuntos_(cantidad_de_conjuntos, ConjuntoDeVertices(grafo)), grafo_(grafo), peso_(0.0),
  cantidad_de_conjuntos_(cantidad_de_conjuntos), vertices_(grafo.cantidad_de_vertices(), false)
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
  return conjuntos_[conjunto - 1].costo(vertice);
}


void Particion::agregar_vertice(unsigned int conjunto, unsigned int vertice)
{
  peso_ -= conjuntos_[conjunto - 1].peso();

  conjuntos_[conjunto - 1].agregar_vertice(vertice);
  vertices_[vertice - 1] = true;

  peso_ += conjuntos_[conjunto - 1].peso();
}


void Particion::sacar_vertice(unsigned int conjunto, unsigned int vertice)
{
  peso_ -= conjuntos_[conjunto - 1].peso();

  conjuntos_[conjunto - 1].sacar_vertice(vertice);
  vertices_[vertice - 1] = false;

  peso_ += conjuntos_[conjunto - 1].peso();
}


set<unsigned int>::iterator Particion::begin(unsigned int conjunto)
{
  return conjuntos_[conjunto - 1].begin();
}


set<unsigned int>::iterator Particion::end(unsigned int conjunto)
{
  return conjuntos_[conjunto - 1].end();
}


unsigned int Particion::conjunto_del_vertice(unsigned int vertice)
{
  unsigned int conjunto;

  for (conjunto = 0; conjunto < cantidad_de_conjuntos(); conjunto++) {
    if (conjuntos_[conjunto].find(vertice) != conjuntos_[conjunto].end()) {
      break;
    }
  }

  return conjunto + 1;
}


bool Particion::contiene_a(unsigned int vertice)
{
  return vertices_[vertice - 1];
}


void Particion::operator=(Particion particion)
{
  grafo_ = particion.grafo_;
  peso_ = particion.peso_;
  cantidad_de_conjuntos_ = particion.cantidad_de_conjuntos_;
  
  for (unsigned int i = 0; i < conjuntos_.size(); i++) {
    conjuntos_[i] = particion.conjuntos_[i];
  }
}

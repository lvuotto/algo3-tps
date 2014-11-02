#include "conjunto_de_vertices.h"

using namespace std;

ConjuntoDeVertices::ConjuntoDeVertices(Grafo& grafo) : grafo_(grafo), vertices_(), peso_(0.0) {}


void ConjuntoDeVertices::agregar_vertice(unsigned int vertice)
{
  peso_ += costo(vertice);
  vertices_.insert(vertice);
}


void ConjuntoDeVertices::sacar_vertice(unsigned int vertice)
{
  vertices_.erase(vertice);
  peso_ -= costo(vertice);
}


bool ConjuntoDeVertices::vacio() const
{
  return vertices_.empty();
}


double ConjuntoDeVertices::peso() const
{
  return peso_;
}


double ConjuntoDeVertices::costo(unsigned int vertice) const
{
  double costo = 0.0;
  for (auto it = vertices_.begin(); it != vertices_.end(); it++)
    costo += grafo_.peso_arista(vertice, *it);
  return costo;
}


set<unsigned int>::iterator ConjuntoDeVertices::begin() 
{
  return vertices_.begin();
}


set<unsigned int>::iterator ConjuntoDeVertices::end() 
{
  return vertices_.end();
}


set<unsigned int>::iterator ConjuntoDeVertices::find(unsigned int vertice) 
{
  return vertices_.find(vertice);
}


void ConjuntoDeVertices::operator=(ConjuntoDeVertices& conjunto)
{
  peso_ = conjunto.peso_;
  vertices_ = conjunto.vertices_;
}

#include "kpmp.h"
#include <limits>


using namespace std;


Grafo::Grafo(unsigned int n) : ady_(n, vector<double>(n, 0.0)) {}

void Grafo::agregar(unsigned int u, unsigned int v, double w)
{
  ady_[u - 1][v - 1] = w;
  ady_[v - 1][u - 1] = w;
}

double Grafo::peso(unsigned int u, unsigned int v)
{
  return ady_[u - 1][v - 1];
}

unsigned int Grafo::cantidad_nodos()
{
  return ady_.size();
}


Particion::Particion(Grafo& G) : G_(G), peso_(0.0) {}

void Particion::agregar(unsigned int v)
{
  peso_ += costo(v);
  vertices_.insert(v);
}

void Particion::sacar(unsigned int v)
{
  vertices_.erase(v);
  peso_ -= costo(v);
}

bool Particion::vacia() const
{
  return vertices_.empty();
}

double Particion::peso() const
{
  return peso_;
}

double Particion::costo(unsigned int v) const
{
  double p = 0.0;
  for (auto it = vertices_.begin(); it != vertices_.end(); it++)
    p += G_.peso(v, *it);
  return p;
}
 

Particiones::Particiones(unsigned int k, Grafo& G) :
  ps_(k, Particion(G)),
  cant_(G.cantidad_nodos()),
  sol_(G.cantidad_nodos(), 0),
  peso_(0.0),
  sol_opt_(G.cantidad_nodos(), 0),
  peso_min_(numeric_limits<double>::infinity())
{}

void Particiones::agregar(unsigned int i, unsigned int v)
{
  peso_ -= ps_[i - 1].peso();
  ps_[i - 1].agregar(v);
  peso_ += ps_[i - 1].peso();
  sol_[v - 1] = i;
}

void Particiones::sacar(unsigned int i, unsigned int v)
{
  peso_ -= ps_[i - 1].peso();
  ps_[i - 1].sacar(v);
  peso_ += ps_[i - 1].peso();
}

bool Particiones::vacia(unsigned int i) const
{
  return ps_[i].vacia();
}

unsigned int Particiones::cantidad() const
{
  return ps_.size();
}

unsigned int Particiones::cantidad_nodos() const
{
  return cant_;
}

vector<unsigned int> Particiones::solucion() const
{
  return sol_opt_;
}

void Particiones::actualizar()
{
  sol_opt_ = sol_;
  peso_min_ = peso_;
}

double Particiones::peso() const
{
  return peso_;
}

double Particiones::peso_min() const
{
  return peso_min_;
}

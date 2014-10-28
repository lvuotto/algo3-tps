#include "grafo.h"

using namespace std;

Arista::Arista(unsigned int vertice1, unsigned int vertice2, double peso) :
  vertice1_(vertice1), vertice2_(vertice2), peso_(peso)
  {}

unsigned int Arista::vertice1()
{
  return vertice1_;
}

unsigned int Arista::vertice2()
{
  return vertice2_;
}

double Arista::peso()
{
  return peso_;
}

bool Arista::operator<(const Arista& otra) const {
  return peso_ < otra.peso_;
}

Grafo::Grafo(unsigned int n) : adyacencias_(n, vector<double>(n, 0.0)) {}

void Grafo::agregar_arista(unsigned int vertice1, unsigned int vertice2, double peso)
{
  adyacencias_[vertice1 - 1][vertice2 - 1] = peso;
  adyacencias_[vertice2 - 1][vertice1 - 1] = peso;
  aristas_.push_back(Arista(vertice1, vertice2, peso));
}

double Grafo::peso_arista(unsigned int vertice1, unsigned int vertice2)
{
  return adyacencias_[vertice1 - 1][vertice2 - 1];
}

unsigned int Grafo::cantidad_nodos()
{
  return adyacencias_.size();
}

vector<Arista> Grafo::aristas()
{
  return aristas_;
}

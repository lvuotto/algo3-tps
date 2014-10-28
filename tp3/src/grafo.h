#ifndef GRAFO_H
#define GRAFO_H

#include <vector>

using namespace std;

typedef vector<vector<double> > Matriz;

struct Arista {
  Arista(unsigned int vertice1, unsigned int vertice2, double peso);
  unsigned int vertice1();
  unsigned int vertice2();
  double peso();
  bool operator<(const Arista& otra) const;

private:
  unsigned int vertice1_;
  unsigned int vertice2_;
  double peso_;
};

struct Grafo {
  Grafo(unsigned int n);
  void agregar_arista(unsigned int vertice1, unsigned int vertice2, double peso);
  double peso_arista(unsigned int vertice1, unsigned int vertice2);
  unsigned int cantidad_nodos();
  vector<Arista> aristas();

private:
  Matriz adyacencias_;
  vector<Arista> aristas_;
};

#endif

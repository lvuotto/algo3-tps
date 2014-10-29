#include <iostream>
#include <vector>
#include "kpmp.h"

using namespace std;

Entrada::Entrada(Grafo grafo_, unsigned int cantidad_de_conjuntos_) :
  grafo(grafo_), cantidad_de_conjuntos(cantidad_de_conjuntos_)
  {}


Entrada leer_entrada() {
  unsigned int n, m, k;
  cin >> n >> m >> k;
  Grafo grafo(n);

  for (unsigned int i = 0; i < m; i++) {
    unsigned int vertice1, vertice2;
    double peso;
    cin >> vertice1 >> vertice2 >> peso;

    grafo.agregar_arista(vertice1, vertice2, peso);
  }

  return Entrada(grafo, k);
}


Particion leer_solucion(Grafo& grafo, unsigned int cantidad_de_conjuntos) {
  Particion particion(grafo, cantidad_de_conjuntos);
  unsigned int conjunto;

  for (unsigned int vertice = 1; vertice <= grafo.cantidad_de_vertices(); vertice++) {
    cin >> conjunto;

    particion.agregar_vertice(conjunto - 1, vertice);
  }

  return particion;
}


void imprimir_particion(Particion& particion) {
  vector<unsigned int> solucion = particion_a_solucion(particion);

  for (auto it = solucion.begin(); it != solucion.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
}


vector<unsigned int> particion_a_solucion(Particion& particion) {
  vector<unsigned int> solucion(particion.cantidad_de_vertices(), 0);

  for (unsigned int conjunto = 0; conjunto < particion.cantidad_de_conjuntos(); conjunto++) {
    for (auto vertice = particion.begin(conjunto); vertice != particion.end(conjunto); vertice++) {
      solucion[*vertice - 1] = conjunto + 1;
    }
  }

  return solucion;
}
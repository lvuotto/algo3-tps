#include <iostream>
#include <vector>
#include <algorithm>
#include "grafo.cc"
#include "conjunto_de_vertices.cc"
#include "particion.cc"

using namespace std;


Particion            kpmp_hg(Grafo& grafo, unsigned int cantidad_de_conjuntos);
void                 agregar_al_de_menos_peso(Particion& particion, unsigned int vertice);
vector<unsigned int> particion_a_solucion(Particion& particion);

int main()
{
  unsigned int n, m, k;
  cin >> n >> m >> k;
  Grafo grafo(n);

  for (unsigned int i = 0; i < m; i++) {
    unsigned int vertice1, vertice2;
    double peso;
    cin >> vertice1 >> vertice2 >> peso;

    grafo.agregar_arista(vertice1, vertice2, peso);
  }

  Particion particion = kpmp_hg(grafo, k);

  vector<unsigned int> solucion = particion_a_solucion(particion);
  for (auto it = solucion.begin(); it != solucion.end(); it++)
    cout << *it << " ";
  cout << endl;

  return 0;
}


Particion kpmp_hg(Grafo& grafo, unsigned int cantidad_de_conjuntos)
{
  Particion particion(grafo, cantidad_de_conjuntos);

  vector<Arista> aristas = grafo.aristas();

  sort(aristas.begin(), aristas.end());

  for (auto it = aristas.rbegin(); it != aristas.rend(); it++) {
    agregar_al_de_menos_peso(particion, it->vertice1());
    agregar_al_de_menos_peso(particion, it->vertice2());
  }

  return particion;
}

void agregar_al_de_menos_peso(Particion& particion, unsigned int vertice) {
  unsigned int min_index = 0;
  double min_costo = particion.conjuntos[0].costo(vertice);

  for (unsigned int i = 1; i < particion.conjuntos.size(); i++) {
    double costo = particion.conjuntos[i].costo(vertice);

    if (costo < min_costo) {
      min_index = i;
      min_costo = costo;
    }
  }

  particion.conjuntos[min_index].agregar_vertice(vertice);
}

vector<unsigned int> particion_a_solucion(Particion& particion) {
  vector<unsigned int> solucion(particion.cantidad_nodos(), 0);

  for (unsigned int conjunto = 0; conjunto < particion.conjuntos.size(); conjunto++) {
    for (auto vertice = particion.conjuntos[conjunto].begin(); vertice != particion.conjuntos[conjunto].end(); vertice++) {
      solucion[*vertice - 1] = conjunto + 1;
    }
  }

  return solucion;
}

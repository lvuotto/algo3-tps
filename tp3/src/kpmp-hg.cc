#include "kpmp-hg.h"
#include <iostream>

using namespace std;

Particion kpmp_hg(Grafo& grafo, unsigned int cantidad_de_conjuntos, unsigned int, unsigned int, default_random_engine&)
{
  Particion particion(grafo, cantidad_de_conjuntos);

  vector<Arista> aristas = grafo.aristas();

  sort(aristas.begin(), aristas.end());

  for (auto it = aristas.rbegin(); it != aristas.rend(); it++) {
    agregar_al_de_menos_peso(particion, it->vertice1());
    agregar_al_de_menos_peso(particion, it->vertice2());
  }

  for (unsigned int vertice = 1; vertice <= grafo.cantidad_de_vertices(); vertice++) {
    if (!particion.contiene_a(vertice)) {
      particion.agregar_vertice(1, vertice);
    }
  }

  return particion;
}


Particion kpmp_hg_random_aristas(Grafo& grafo, unsigned int
cantidad_de_conjuntos, unsigned int random_aristas, unsigned int, default_random_engine& re)
{
  Particion particion(grafo, cantidad_de_conjuntos);

  vector<Arista> aristas = grafo.aristas();

  sort(aristas.begin(), aristas.end());

  while (aristas.size()) {
    shuffle_vector_range_from_end(aristas, random_aristas, re);

    agregar_al_de_menos_peso(particion, aristas.back().vertice1());
    agregar_al_de_menos_peso(particion, aristas.back().vertice2());

    aristas.pop_back();
  }

  for (unsigned int vertice = 1; vertice <= grafo.cantidad_de_vertices(); vertice++) {
    if (!particion.contiene_a(vertice)) {
      particion.agregar_vertice(1, vertice);
    }
  }

  return particion;
}


Particion kpmp_hg_random_conjuntos(Grafo& grafo, unsigned int
cantidad_de_conjuntos, unsigned int, unsigned int random_conjuntos, default_random_engine& re)
{
  Particion particion(grafo, cantidad_de_conjuntos);

  vector<Arista> aristas = grafo.aristas();

  sort(aristas.begin(), aristas.end());

  for (auto it = aristas.rbegin(); it != aristas.rend(); it++) {
    agregar_al_de_menos_peso_random(particion, it->vertice1(), random_conjuntos, re);
    agregar_al_de_menos_peso_random(particion, it->vertice2(), random_conjuntos, re);
  }

  for (unsigned int vertice = 1; vertice <= grafo.cantidad_de_vertices(); vertice++) {
    if (!particion.contiene_a(vertice)) {
      particion.agregar_vertice(1, vertice);
    }
  }

  return particion;
}


Particion kpmp_hg_random_aristas_conjuntos(Grafo& grafo, unsigned int
cantidad_de_conjuntos, unsigned int random_aristas, unsigned int random_conjuntos, default_random_engine& re)
{
  Particion particion(grafo, cantidad_de_conjuntos);

  vector<Arista> aristas = grafo.aristas();

  sort(aristas.begin(), aristas.end());

  while (aristas.size()) {
    shuffle_vector_range_from_end(aristas, random_aristas, re);

    agregar_al_de_menos_peso_random(particion, aristas.back().vertice1(), random_conjuntos, re);
    agregar_al_de_menos_peso_random(particion, aristas.back().vertice2(), random_conjuntos, re);

    aristas.pop_back();
  }

  for (unsigned int vertice = 1; vertice <= grafo.cantidad_de_vertices(); vertice++) {
    if (!particion.contiene_a(vertice)) {
      particion.agregar_vertice(1, vertice);
    }
  }

  return particion;
}


void agregar_al_de_menos_peso(Particion& particion, unsigned int vertice)
{
  if (particion.contiene_a(vertice)) {
    return;
  }

  unsigned int min_conjunto = 1;
  double min_costo = particion.costo(min_conjunto, vertice);

  for (unsigned int i = 2; i <= particion.cantidad_de_conjuntos(); i++) {
    double costo = particion.costo(i, vertice);

    if (costo < min_costo) {
      min_conjunto = i;
      min_costo = costo;
    }
  }

  particion.agregar_vertice(min_conjunto, vertice);
}


void agregar_al_de_menos_peso_random(Particion& particion, unsigned int vertice, unsigned int random_conjuntos, default_random_engine& re)
{
  if (particion.contiene_a(vertice)) {
    return;
  }

  vector< pair<unsigned int, double> > conjuntos;

  for (unsigned int i = 1; i <= particion.cantidad_de_conjuntos(); i++) {
    conjuntos.push_back(make_pair(i, particion.costo(i, vertice)));
  }

  sort(conjuntos.begin(), conjuntos.end(), sort_pair);

  shuffle_vector_range_from_end(conjuntos, random_conjuntos, re);

  particion.agregar_vertice(conjuntos.back().first, vertice);
}


bool sort_pair(pair<unsigned int, double> a, pair<unsigned int, double> b)
{
  return a.second > b.second;
}

#include <algorithm>
#include "kpmp.cc"

using namespace std;

Particion kpmp_hg(Grafo& grafo, unsigned int cantidad_de_conjuntos);
void      agregar_al_de_menos_peso(Particion& particion, unsigned int vertice);


int main()
{
  Entrada entrada = leer_entrada();

  Particion particion = kpmp_hg(entrada.grafo, entrada.cantidad_de_conjuntos);

  imprimir_particion(particion);

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



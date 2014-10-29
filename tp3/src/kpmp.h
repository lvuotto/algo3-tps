#include <vector>
#include "grafo.cc"
#include "conjunto_de_vertices.cc"
#include "particion.cc"

using namespace std;

struct Entrada {
  Grafo grafo;
  unsigned int cantidad_de_conjuntos;

  Entrada(Grafo grafo_, unsigned int cantidad_de_conjuntos);
};

Entrada leer_entrada();

Particion leer_solucion(Grafo& grafo, unsigned int cantidad_de_conjuntos);

void imprimir_particion(Particion& particion);

vector<unsigned int> particion_a_solucion(Particion& particion);

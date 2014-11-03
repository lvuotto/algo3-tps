#include <stack>
#include <limits>
#include "kpmp-exacto.h"

using namespace std;

Particion kpmp_exacto(Grafo& grafo, unsigned int cantidad_de_conjuntos)
{
  Particion particion(grafo, cantidad_de_conjuntos);

  stack<unsigned int> vertices_pendientes;

  for (unsigned int i = 1; i <= grafo.cantidad_de_vertices(); i++) {
    vertices_pendientes.push(i);
  }

  double infinity = numeric_limits<double>::infinity();

  Particion particion_min = particion;

  backtracking(particion, particion_min, vertices_pendientes, infinity);

  return particion_min;
}


void backtracking(Particion& particion, Particion& particion_min, stack<unsigned int>& vertices_pendientes, double& peso_min)
{
  if (vertices_pendientes.empty()) {
    if (particion.peso() < peso_min) {
      peso_min = particion.peso();
      particion_min = particion;  
    }

    return;
  }

  if (particion.peso() >= peso_min) {
    return;
  }

  unsigned int vertice = vertices_pendientes.top();
  vertices_pendientes.pop();

  for (unsigned int conjunto = 1; conjunto <= particion.cantidad_de_conjuntos(); conjunto++) {
    particion.agregar_vertice(conjunto, vertice);

    backtracking(particion, particion_min, vertices_pendientes, peso_min);

    particion.sacar_vertice(conjunto, vertice);
  }

  vertices_pendientes.push(vertice);
}

#include <iostream>
#include <vector>
#include "kpmp.h"
#include "kpmp-hg.cc"
#include "kpmp-hl.cc"
#include "kpmp-grasp.cc"

#define CRITERIO MEJOR_LUEGO_DE_X_VECES
#define REPETICIONES 10

using namespace std;


int main(int argc, char *argv[])
{
  if (argc == 1) {
    imprimir_uso();

    return 1;
  }

  Entrada entrada = leer_entrada();

  switch (atoi(argv[1])) {
    case 0: {
      cout << "FALTA IMPLEMENTAR";
      break;
    }
    case 1: {
      Particion particion = kpmp_hg(entrada.grafo, entrada.cantidad_de_conjuntos);
      imprimir_particion(particion);
      break;
    }
    case 2: {
      Particion particion = kpmp_hg_random_aristas(entrada.grafo, entrada.cantidad_de_conjuntos);
      imprimir_particion(particion);
      break;
    }
    case 3: {
      Particion particion = kpmp_hg_random_conjuntos(entrada.grafo, entrada.cantidad_de_conjuntos);
      imprimir_particion(particion);
      break;
    }
    case 4: {
      Particion particion = kpmp_hg_random_aristas_conjuntos(entrada.grafo, entrada.cantidad_de_conjuntos);
      imprimir_particion(particion);
      break;
    }
    case 5: {
      Particion particion = leer_solucion(entrada.grafo, entrada.cantidad_de_conjuntos);
      kpmp_hl_mover_vertice(particion);
      imprimir_particion(particion);
      break;
    }
    case 6: {
      Particion particion = leer_solucion(entrada.grafo, entrada.cantidad_de_conjuntos);
      kpmp_hl_switch_vertices(particion);
      imprimir_particion(particion);
      break;
    }
    case 7: {
      Particion particion = kpmp_grasp(kpmp_hg_random_aristas, kpmp_hl_mover_vertice, entrada.grafo, entrada.cantidad_de_conjuntos, CRITERIO, REPETICIONES);
      imprimir_particion(particion);
      break;
    }
    case 8: {
      Particion particion = kpmp_grasp(kpmp_hg_random_aristas, kpmp_hl_switch_vertices, entrada.grafo, entrada.cantidad_de_conjuntos, CRITERIO, REPETICIONES);
      imprimir_particion(particion);
      break;
    }
    case 9: {
      Particion particion = kpmp_grasp(kpmp_hg_random_conjuntos, kpmp_hl_mover_vertice, entrada.grafo, entrada.cantidad_de_conjuntos, CRITERIO, REPETICIONES);
      imprimir_particion(particion);
      break;
    }
    case 10: {
      Particion particion = kpmp_grasp(kpmp_hg_random_conjuntos, kpmp_hl_switch_vertices, entrada.grafo, entrada.cantidad_de_conjuntos, CRITERIO, REPETICIONES);
      imprimir_particion(particion);
      break;
    }
    case 11: {
      Particion particion = kpmp_grasp(kpmp_hg_random_aristas_conjuntos, kpmp_hl_mover_vertice, entrada.grafo, entrada.cantidad_de_conjuntos, CRITERIO, REPETICIONES);
      imprimir_particion(particion);
      break;
    }
    case 12: {
      Particion particion = kpmp_grasp(kpmp_hg_random_aristas_conjuntos, kpmp_hl_switch_vertices, entrada.grafo, entrada.cantidad_de_conjuntos, CRITERIO, REPETICIONES);
      imprimir_particion(particion);
      break;
    }
    default:
      imprimir_uso();
      return 1;
  }

  return 0;
}

Entrada::Entrada(Grafo grafo_, unsigned int cantidad_de_conjuntos_) :
  grafo(grafo_), cantidad_de_conjuntos(cantidad_de_conjuntos_)
  {}


Entrada leer_entrada()
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

  return Entrada(grafo, k);
}


Particion leer_solucion(Grafo& grafo, unsigned int cantidad_de_conjuntos)
{
  Particion particion(grafo, cantidad_de_conjuntos);
  unsigned int conjunto;

  for (unsigned int vertice = 1; vertice <= grafo.cantidad_de_vertices(); vertice++) {
    cin >> conjunto;

    particion.agregar_vertice(conjunto, vertice);
  }

  return particion;
}


void imprimir_particion(Particion& particion)
{
  vector<unsigned int> solucion = particion_a_solucion(particion);

  for (auto it = solucion.begin(); it != solucion.end(); it++) {
    cout << *it << " ";
  }

  cout << endl << particion.peso() << endl;
}


vector<unsigned int> particion_a_solucion(Particion& particion)
{
  vector<unsigned int> solucion(particion.cantidad_de_vertices(), 0);

  for (unsigned int conjunto = 1; conjunto <= particion.cantidad_de_conjuntos(); conjunto++) {
    for (auto vertice = particion.begin(conjunto); vertice != particion.end(conjunto); vertice++) {
      solucion[*vertice - 1] = conjunto;
    }
  }

  return solucion;
}


void imprimir_uso()
{
  cout << "Indicá qué algoritmo querés usar:" << endl;
  cout << " 0 -\t Exacto" << endl;
  cout << " 1 -\t Goloso" << endl;
  cout << " 2 -\t Goloso randomizado en elegir aristas" << endl;
  cout << " 3 -\t Goloso randomizado en seleccionar el conjunto" << endl;
  cout << " 4 -\t Goloso randomizado en aristas y conjuntos" << endl;
  cout << " 5 -\t Búsqueda local moviendo vértices (recibe un grafo Y una solución inicial)" << endl;
  cout << " 6 -\t Búsqueda local intercambiando vértices (recibe un grafo Y una solución inicial)" << endl;
  cout << " 7 -\t GRASP con 2 y 5" << endl;
  cout << " 8 -\t GRASP con 2 y 6" << endl;
  cout << " 9 -\t GRASP con 3 y 5" << endl;
  cout << "10 -\t GRASP con 3 y 6" << endl;
  cout << "11 -\t GRASP con 4 y 5" << endl;
  cout << "12 -\t GRASP con 4 y 6" << endl;
}

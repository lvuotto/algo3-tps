#include <utility>

using namespace std;

struct Grafo
{
  /* n == #(nodos), m == #(aristas).
   *
   * en la posición i,j de la matriz se encuentra el costo del enlace i,j
   * que va desde el nodo i al nodo j. Si no hay enlace entre dos nodos, el
   * costo de i,j es -1.
   */
  int n;
  int m;
  vector< vector<int> > matriz_conexiones;

  Grafo() {}

  Grafo(int cant_nodos, int cant_aristas)
  {
    n = cant_nodos;
    m = cant_aristas;

    matriz_conexiones.resize(n);
    for (int i = 0; i < n; i++) {
      matriz_conexiones[i].resize(n);

      for (int j = 0; j < n; j++) {
        matriz_conexiones[i][j] = -1;
      }
    }
  }

  bool es_conexo();
  bool tiene_solucion();
  int  peso_total();
};

struct Arista
{
  int nodo1;
  int nodo2;
  int peso;

  Arista(int n1, int n2, int p) :
    nodo1(n1),
    nodo2(n2),
    peso(p)
  {}
};

Grafo                                  prim(Grafo& g);
bool                                   estan_todos(std::vector<bool> v);
void                                   imprimir_grafo(Grafo& g);
Arista                                 minima_no_incluida(Grafo& g, Grafo& agm);
pair< vector<Arista>, vector<Arista> > anillar(Grafo& g, int& peso_anillo);

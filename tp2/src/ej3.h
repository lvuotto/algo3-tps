#include <vector>
#include <tuple>


struct Grafo
{
  /* n == #(nodos), m == #(aristas).
   *
   * en la posición i,j de la matriz se encuentra el costo del enlace i,j
   * que va desde el nodo i al nodo j. Un enlace no válido (inexistente entre
   * dos nodos) tiene costo -1.
   */
  int n;
  int m;
  vector<bool> nodos_visitados;
  vector< vector<int> > matriz_conexiones;

  Grafo () {}

  Grafo(int cant_nodos, int cant_aristas)
  {
    n = cant_nodos;
    m = cant_aristas;

    nodos_visitados.resize(n);
    // inicializo el vector nodos_visitados en false.
    matriz_conexiones.resize(n);
    for(int h = 0; h < n; h++)
    {
      nodos_visitados[h] = false;
      matriz_conexiones[h].resize(n);
    }
    // inicializo la matriz con -1.
    for(int i = 0; i < matriz_conexiones[i].size(); i++)
    {
      for(int j = 0; j < matriz_conexiones[j].size(); j++)
      {
        matriz_conexiones[i][j] = -1;
      }
    }
  }

  bool es_conexo(Grafo g);
  bool tiene_solucion(Grafo g);
};

bool  se_puede_anillar(Grafo g);
Grafo prim(Grafo g);
bool  estan_todos(vector<bool> v);
tuple <int, int> buscar_peso_minimo(vector<int> v);
Grafo completar_anillo(Grafo agm, Grafo g);
void  restar_aristas(Grafo agm, Grafo g);

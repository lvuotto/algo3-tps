#include <vector>
#include <tuple>


struct Grafo
{
  /* n == #(nodos), m == #(aristas).
   *
   * en la posición i,j de la matriz se encuentra el costo del enlace i,j
   * que va desde el nodo i al nodo j. Si no hay conexión entre dos nodos,
   * el costo del enlace correspondiente es cero.
   */
  unsigned int n;
  unsigned int m;
  vector<bool> nodos_visitados;
  vector< vector<unsigned int> > matriz_conexiones;

  Grafo () {}

  Grafo(unsigned int cant_nodos, unsigned int cant_aristas)
  {
    n = cant_nodos;
    m = cant_aristas;

    nodos_visitados.resize(n);

    matriz_conexiones.resize(n);
    for(int h = 0; h < n; h++)
    {
      nodos_visitados[h] = false;
      matriz_conexiones[h].resize(n);
    }
    for(int i = 0; i < matriz_conexiones[i].size(); i++)
    {
      for(int j = 0; j < matriz_conexiones[j].size(); j++)
      {
        matriz_conexiones[i][j] = 0;
      }
    }
  }

  bool es_conexo(Grafo g);
};

bool  anillar(Grafo g);
bool  no_tiene_solucion(Grafo g);
Grafo prim(Grafo g);
bool  estan_todos(vector<bool> v);
tuple <unsigned int, unsigned int> buscar_peso_minimo(vector<unsigned int> v);
Grafo completar_anillo(Grafo agm, Grafo g);
void  restar_aristas(Grafo agm, Grafo g);

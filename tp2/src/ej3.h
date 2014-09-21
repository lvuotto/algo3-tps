#include <iostream>
#include <vector>
#include <climits>
#include <tuple>


struct Grafo
{
  // n == #(nodos), m == #(aristas).
  unsigned int n;
  unsigned int m;
  vector<bool> nodos_visitados = {false};
  /**
   * en la posición i,j de la matriz se encuentra el costo del enlace i,j
   * que va desde el nodo i al nodo j. Si no hay conexión entre dos nodos,
   * el costo del enlace correspondiente es cero.
   **/
  vector< vector<unsigned int> > matriz_conexiones;

  Grafo()
  {
    n = 0;
    m = 0;

    matriz_conexiones.resize(n);
    for(int h = 0; h < n; h++)
    {
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
};

bool  anillar(Grafo g);
bool  no_tiene_solucion(Grafo g);
bool  es_conexo(Grafo g);
Grafo prim(Grafo g);
bool  estan_todos(vector<bool> v);
void  completar_anillo(Grafo agm, Grafo g)
tuple <unsigned int, unsigned int> buscar_peso_minimo(vector<unsigned int> v);

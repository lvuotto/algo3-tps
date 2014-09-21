#include <iostream>
#include <vector>

#include "ej3.h"

using namespace std;



int main () {

  // cargar matriz_conexiones con datos de entrada
  unsigned int cant_nodos, cant_aristas;
  cin >> cant_nodos;
  cin >> cant_aristas;

  Grafo g = Grafo(cant_nodos, cant_aristas);

  unsigned int e1, e2, c = 0;
  for(int i = 0; i < g.m; i++)
  {
    cin >> e1 >> e2 >> c;
    g.matriz_conexiones[e1-1][e2-1] = c;
    g.matriz_conexiones[e2-1][e1-1] = c;
  }

  imprimir_salida(anillar(g));

  return 0;
}



bool anillar(Grafo g)
{
  if(no_tiene_solucion(g))
  {
    return false;
  }
  completar_anillo(prim(g), g);
  return true;
}


bool no_tiene_solucion(Grafo g)
{
  return !g.es_conexo() || (g.m < g.n);
}


bool Grafo::es_conexo(Grafo g)
{
  while(!estan_todos(g.nodos_visitados))
  {
    for(int i = 0; i < g.n; i++)
    {
      for(int j = 0; j < g.n; j++)
      {
        if(g.matriz_conexiones[i][j] > 0)
        {
          if(!g.nodos_visitados[j])
          {
            g.nodos_visitados[j] = true;
          }
        }
      }
    }
    return estan_todos(g.nodos_visitados);
  }
}


Grafo prim(Grafo g)
{
  /**
   * 1. elijo un vértice arbitrario de la matriz.
   * 2. mientas el agm no incluya a todos los vértices v de V:
   *      encontrar el vértice incidente a v de menor peso
   *      agregar este vértice al agm
   **/
  Grafo agm = Grafo(g.n, g.m);
  agm.m = 0;

  while(!estan_todos(agm.nodos_visitados))
  {
    for(int i = 0; i < g.n; i++)
    {
      auto t = buscar_peso_minimo(g.matriz_conexiones[i]);
      agm.matriz_conexiones[i][get<0>(t)] = get<1>(t);
      agm.matriz_conexiones[get<0>(t)][i] = get<1>(t);
      agm.m += 1;
    }
  }
  return agm;
}


bool estan_todos(vector<bool> v)
{
  for(int i = 0; i < v.size(); i++)
  {
    if(!v[i])
    {
      return false;
    }
  }
  return true;
}


tuple <unsigned int, unsigned int> buscar_peso_minimo(vector<unsigned int> v)
{
  unsigned int min = INT_MAX;
  unsigned int pos = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] < min && v[i] != 0)
    {
      min = v[i];
      pos = i;
    }
  }
  auto t = make_tuple(pos, min);
  return t;
}


Grafo completar_anillo(Grafo agm, Grafo g)
{
  // X = aristas(G) \ aristas(AGM)
  restar_aristas(agm, g);
  // busco la arista de menor peso
  unsigned int eje_de_menor_peso = g.matriz_conexiones[0][0];
  unsigned int pos_i, pos_j = 0;
  for(int i = 0; i < g.n; i++)
  {
    for(int j = 0; j < g.n; j++)
    {
      if(g.matriz_conexiones[i][j] < eje_de_menor_peso)
      {
        pos_i = i;
        pos_j = j;
        eje_de_menor_peso = g.matriz_conexiones[i][j];
      }
    }
  }
  agm.matriz_conexiones[pos_i][pos_j] = eje_de_menor_peso;
  return agm;
}


void restar_aristas(Grafo agm, Grafo g)
{
  for(int i = 0; i < g.n; i++)
  {
    for(int j = 0; j < g.n; j++)
    {
      if(!agm.matriz_conexiones[i][j])
      {
        g.matriz_conexiones[i][j] = 0;
        g.matriz_conexiones[j][i] = 0;
      }
    }
  }
}


void imprimir_salida(Grafo agm)
{
  ;
}

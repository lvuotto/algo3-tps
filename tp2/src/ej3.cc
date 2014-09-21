//#include <iostream>
//#include <vector>


#include "ej3.h"

using namespace std;



int main () {

  // cargar matriz_conexiones con datos de entrada
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
  return !(es_conexo(g)) || (g.m < g.n);
}


bool es_conexo(Grafo g)
{
  g.nodos_visitados.resize(g.n);
  for(int h = 0; h < nodos_visitados.size(); h++)
  {
    nodos_visitados[h] = false;
  }
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


Grafo prim(Grafo g)
{
  /**
   * 1. elijo un vértice arbitrario de la matriz.
   * 2. mientas el agm no incluya a todos los vértices v de V:
   *      encontrar el vértice incidente a v de menor peso
   *      agregar este vértice al agm
   **/
  Grafo agm;
  agm.n = g.n;
  agm.nodos_visitados.resize(agm.n);
  for(int h = 0; h < nodos_visitados.size(); h++)
  {
    agm.nodos_visitados[h] = false;
  }

  while(!estan_todos(agm.nodos_visitados))
  {
    for(int i = 0; i < g.n; i++)
    {
      for(int j = 0; i < g.n; j++)
      {
        auto t = buscar_peso_minimo(g.matriz_conexiones[i][j]);
        agm.matriz_conexiones[i][get<0>(t)] = get<1>(t);
        agm.m += 1;
      }
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


void completar_anillo(Grafo agm, Grafo g)
{
  ;
}

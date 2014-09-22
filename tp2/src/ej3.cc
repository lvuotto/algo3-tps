#include <iostream>
#include <vector>
#include <climits>
#include <tuple>

#include "ej3.h"

using namespace std;



int main () {
  // creo el grafo.
  int cant_nodos, cant_aristas;
  cin >> cant_nodos;
  cin >> cant_aristas;
  Grafo g = Grafo(cant_nodos, cant_aristas);

  // cargo matriz_conexiones con los datos de entrada.
  int e1, e2, c = 0;
  for(int i = 0; i < g.m; i++)
  {
    cin >> e1 >> e2 >> c;
    g.matriz_conexiones[e1-1][e2-1] = c;
    g.matriz_conexiones[e2-1][e1-1] = c;
  }

  if(!se_puede_anillar(g))
  {
    cout << "no" << endl;
  }
  // imprimir_salida(se_puede_anillar(g));
  return 0;
}



bool se_puede_anillar(Grafo g)
{
  if(!g.tiene_solucion())
  {
    return false;
  }
  completar_anillo(prim(g), g);
  return true;
}


bool Grafo::tiene_solucion(Grafo g)
{
  return g.es_conexo() && (g.m >= g.n);
}


bool Grafo::es_conexo(Grafo g)
{
  for(int i = 0; i < g.n; i++)
  {
    for(int j = 0; j < g.n; j++)
    {
      if(g.matriz_conexiones[i][j] > -1)
      {
        g.nodos_visitados[j] = true;
      }
    }
  }
  return estan_todos(g.nodos_visitados);
}


Grafo prim(Grafo g)
{
  /*
   * 1. elijo un vértice arbitrario de la matriz.
   * 2. mientas el agm no incluya a todos los vértices v de V:
   *      encontrar el vértice incidente a v de menor peso.
   *      agregar este vértice al agm.
   */
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


tuple <int, int> buscar_peso_minimo(vector<int> v)
{
  int min = INT_MAX;
  int pos = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] < min && v[i] > -1)
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
  // X = aristas(g) \ aristas(agm).
  restar_aristas(agm, g);
  // busco la arista de menor peso en g.
  int eje_de_menor_peso = g.matriz_conexiones[0][0];
  int pos_i, pos_j = 0;
  for(int i = 0; i < g.n; i++)
  {
    for(int j = 0; j < g.n; j++)
    {
      if(g.matriz_conexiones[i][j] < eje_de_menor_peso && g.matriz_conexiones[i][j] > -1)
      {
        pos_i = i;
        pos_j = j;
        eje_de_menor_peso = g.matriz_conexiones[i][j];
      }
    }
  }
  agm.matriz_conexiones[pos_i][pos_j] = eje_de_menor_peso;
  agm.matriz_conexiones[pos_j][pos_i] = eje_de_menor_peso;
  return agm;
}


void restar_aristas(Grafo agm, Grafo g)
{
  for(int i = 0; i < g.n; i++)
  {
    for(int j = 0; j < g.n; j++)
    {
      if(agm.matriz_conexiones[i][j] > -1)
      {
        g.matriz_conexiones[i][j] = -1;
        g.matriz_conexiones[j][i] = -1;
      }
    }
  }
}


void imprimir_salida(Grafo agm)
{;}

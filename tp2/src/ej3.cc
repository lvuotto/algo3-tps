#include <iostream>
#include <climits>
#include <vector>
#include <tuple>
#include <queue>
#include <list>

#include "ej3.h"
using namespace std;



int main () {
  // creo el grafo.
  int cant_nodos   = 0;
  int cant_aristas = 0;
  cin >> cant_nodos;
  cin >> cant_aristas;
  Grafo g = Grafo(cant_nodos, cant_aristas);

  // cargo matriz_conexiones con los datos de entrada.
  int e1 = 0;
  int e2 = 0;
  int c  = 0;
  for(int i = 0; i < g.m; i++)
  {
    cin >> e1 >> e2 >> c;
    g.matriz_conexiones[e1-1][e2-1] = c;
    g.matriz_conexiones[e2-1][e1-1] = c;
  }

  if (g.es_conexo()) {
    cout << "si" << endl;
    //completar_anillo(prim(g), g);
  } else {
    cout << "no" << endl;
  }
  // falta imprimir_salida(g);
  Grafo agm = prim(g);
  imprimir_grafo(g);
  cout << endl << "------" << endl;
  imprimir_grafo(agm);

  return 0;
}


void imprimir_grafo(Grafo& g) {
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; j < g.n; j++) {
      cout << g.matriz_conexiones[i][j] << " ";
    }
    cout << endl;
  }
}


bool Grafo::tiene_solucion()
{
  return this->m >= this->n && this->es_conexo();
}


bool Grafo::es_conexo()
{
  queue<unsigned int> nodos_pendientes;
  nodos_pendientes.push(0);

  while (!nodos_pendientes.empty()) {
    unsigned int nodo = nodos_pendientes.front();
    nodos_pendientes.pop();

    nodos_visitados[nodo] = true;

    for (unsigned int i = 0; i < this->matriz_conexiones.size(); i++) {
      if (this->matriz_conexiones[nodo][i] != -1 && !nodos_visitados[i]) {
        nodos_pendientes.push(i);
      }
    }
  }

  return estan_todos(this->nodos_visitados);
}


// Prim para matriz de adyacencias sacado de:
// https://www.youtube.com/watch?v=jHusW_j1blU
Grafo prim(Grafo& g)
{
  Grafo agm = Grafo(g.n, g.n - 1);
  vector<bool> faltan_agregar(g.n, true);
  vector<int> predecesores(g.n, -1);
  vector<int> pesos(g.n, -1);
  pesos[0] = 0;


  for (int i = 0; i < g.n; i++) {
    // Obtengo el mínimo
    int nodo = -1;
    for (int j = 0; j < g.n; j++) {
      if (faltan_agregar[j] && pesos[j] != -1 && (nodo == -1 || pesos[j] < pesos[nodo])) {
        nodo = j;
      }
    }

    faltan_agregar[nodo] = false;

    if (predecesores[nodo] != -1) {
      agm.matriz_conexiones[nodo][predecesores[nodo]] = pesos[nodo];
      agm.matriz_conexiones[predecesores[nodo]][nodo] = pesos[nodo];
    }

    for (int j = 0; j < g.n; j++) {
      if (nodo != j && g.matriz_conexiones[nodo][j] != -1 // Son adyacentes
          && faltan_agregar[j]
          && (pesos[j] == -1 || g.matriz_conexiones[nodo][j] < pesos[j]) // Es menos pesado
      ) {
        pesos[j] = g.matriz_conexiones[nodo][j];
        predecesores[j] = nodo;
      }
    }
  }

  return agm;
}

//Grafo prim(Grafo& g)
// {
//   /*
//    * 1. elijo un vértice arbitrario de la matriz.
//    * 2. mientas el agm no incluya a todos los vértices v de V:
//    *      encontrar la arista incidente a v de menor peso.
//    *      agregar esta arista al agm.
//    */
//   Grafo agm = Grafo(g.n, 0);

//   while(!estan_todos(agm.nodos_visitados))
//   {
//     for(int i = 0; i < g.n; i++)
//     {
//       auto t = buscar_peso_minimo(g.matriz_conexiones[i]);
//       agm.matriz_conexiones[i][get<0>(t)] = get<1>(t);
//       agm.matriz_conexiones[get<0>(t)][i] = get<1>(t);
//       agm.m += 1;
//       agm.nodos_visitados[get<0>(t)] = true;
//     }
//   }
//   return agm;
// }


bool estan_todos(std::vector<bool> v)
{
  for(unsigned int i = 0; i < v.size(); i++)
  {
    if(!v[i])
    {
      return false;
    }
  }
  return true;
}


// std::tuple <int, int> buscar_peso_minimo(std::vector<int> v)
// {
//   int min = INT_MAX;
//   int pos = 0;
//   for(unsigned int i = 0; i < v.size(); i++)
//   {
//     if(v[i] < min && v[i] > -1)
//     {
//       min = v[i];
//       pos = i;
//     }
//   }
//   auto t = make_tuple(pos, min);
//   return t;
// }


// Coordenadas completar_anillo(Grafo agm, Grafo g)
// {
//   // X = aristas(g) \ aristas(agm).
//   restar_aristas(g, agm);
//   // busco la arista de menor peso en X, para agregarla al agm y formar el anillo.
//   int eje_de_menor_peso = INT_MAX;
//   int pos_i = 0;
//   int pos_j = 0;
//   int c1    = 0;
//   int c2    = 0;

//   for(int i = 0; i < g.n; i++)
//   {
//     for(int j = 0; j < g.n; j++)
//     {
//       if(g.matriz_conexiones[i][j] > -1 && g.matriz_conexiones[i][j] < eje_de_menor_peso)
//       {
//         eje_de_menor_peso = g.matriz_conexiones[i][j];
//         pos_i = i;
//         pos_j = j;
//       }
//     }
//   }
//   // agrego la arista al agm
//   agm.matriz_conexiones[pos_i][pos_j] = eje_de_menor_peso;
//   agm.matriz_conexiones[pos_j][pos_i] = eje_de_menor_peso;
//   agm.m += 1;
//   c1     = pos_i;
//   c2     = pos_j;

//   Coordenadas crd;
//   crd.g = agm;
//   crd.coordenada_1 = c1;
//   crd.coordenada_2 = c2;

//   return crd;
// }


void restar_aristas(Grafo g, Grafo agm)
{
  for(int i = 0; i < g.n; i++)
  {
    for(int j = 0; j < g.n; j++)
    {
      // si la arista pertenece al agm, la anulo en g
      if(agm.matriz_conexiones[i][j] > -1)
      {
        g.matriz_conexiones[i][j] = -1;
        g.matriz_conexiones[j][i] = -1;
      }
    }
  }
}


// list<std::tuple<int, int, int> > aristas_del_anillo(Coordenadas cs)
// {

//   * cs contiene el grafo agm y las coordenadas de los extremos de
//   * la arista agregada. Para encontrar las aristas que forman
//   * parte del anillo, hago bfs partiendo de la coordenada_1, hasta
//   * encontrar la coordenada_2.

//   for(int h = 0; h < n; h++)
//   {
//     cs.g.nodos_visitados[h] = false;
//   }

// }


//void imprimir_salida(Grafo agm)
/*{
  if(!se_puede_anillar(g))
  {
    cout << "no" << endl;
    ...
}*/

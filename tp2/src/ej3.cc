#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <list>
#include <utility>

#include "ej3.h"
#include <chrono>

#define CANTIDAD 25

using namespace std;
using namespace std::chrono;


int main () {
  // Creo el grafo.
  int cant_nodos, cant_aristas;
  cin >> cant_nodos;
  cin >> cant_aristas;
  Grafo g = Grafo(cant_nodos, cant_aristas);

  // Cargo matriz_conexiones con los datos de entrada.
  int e1, e2, c;
  for(int i = 0; i < g.m; i++)
  {
    cin >> e1 >> e2 >> c;
    g.matriz_conexiones[e1-1][e2-1] = c;
    g.matriz_conexiones[e2-1][e1-1] = c;
  }

  int peso_;
  Grafo backup = g;
  pair<vector<Arista>, vector<Arista>> resultado_;
  auto inicio = high_resolution_clock::now();
  if (g.tiene_solucion()) resultado_ = anillar(g, peso_);
  auto fin = high_resolution_clock::now();
  auto mejor = fin - inicio;
  for (int i = 0; i < CANTIDAD; i++) {
    g = backup;
    inicio = high_resolution_clock::now();
    if (g.tiene_solucion()) resultado_ = anillar(g, peso_);
    fin = high_resolution_clock::now();
    if (fin - inicio < mejor) mejor = fin - inicio;
  }
  cerr << cant_nodos << " "
       << cant_aristas << " "
       << duration_cast<milliseconds>(mejor).count() << endl;

  g = backup;
  if (g.tiene_solucion()) {
    int peso;
    pair< vector<Arista>, vector<Arista> > resultado = anillar(g, peso);

    cout << peso << " " << resultado.first.size() << " " << resultado.second.size() << endl;

    for (auto it = resultado.first.begin(); it != resultado.first.end(); it++) {
      cout << (it->nodo1 + 1) << " " << (it->nodo2 + 1) << endl;
    }

    for (auto it = resultado.second.begin(); it != resultado.second.end(); it++) {
      cout << (it->nodo1 + 1) << " " << (it->nodo2 + 1) << endl;
    }
  } else {
    cout << "no" << endl;
  }

  return 0;
}


void imprimir_grafo(Grafo& g) {
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; j < g.n; j++) {
      if (g.matriz_conexiones[i][j] < 10 && g.matriz_conexiones[i][j] != -1) {
        cout << 0;
      }
      cout << g.matriz_conexiones[i][j] << " ";
    }
    cout << endl;
  }
}


bool Grafo::tiene_solucion()
{
  return this->n >= 3 && this->m >= this->n && this->es_conexo();
}


bool Grafo::es_conexo()
{
  vector<bool> nodos_visitados(n, -1);
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

  return estan_todos(nodos_visitados);
}


int Grafo::peso_total()
{
  int sum = 0;

  for (int i = 0; i < this->n; i++) {
    for (int j = i + 1; j < this->n; j++) {
      if (this->matriz_conexiones[i][j] != -1) {
        sum += this->matriz_conexiones[i][j];
      }
    }
  }

  return sum;
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


bool estan_todos(std::vector<bool> v)
{
  for (unsigned int i = 0; i < v.size(); i++) {
    if (!v[i]) {
      return false;
    }
  }

  return true;
}


Arista minima_no_incluida(Grafo& g, Grafo& agm)
{
  Arista minima(-1, -1, -1);

  for (int i = 0; i < g.n; i++) {
    for (int j = i + 1; j < g.n; j++) {
      if (g.matriz_conexiones[i][j] != -1 // Está en g
          && agm.matriz_conexiones[i][j] == -1 // No está en agm
          && (minima.peso == -1 || g.matriz_conexiones[i][j] < minima.peso) // Es menor que la que tengo
      ) {
        minima.nodo1 = i;
        minima.nodo2 = j;
        minima.peso = g.matriz_conexiones[i][j];
      }
    }
  }

  return minima;
}


pair< vector<Arista>, vector<Arista> > anillar(Grafo& g, int& peso_anillo) {
  Grafo agm = prim(g);
  Arista cierra_anillo = minima_no_incluida(g, agm);

  peso_anillo = agm.peso_total() + cierra_anillo.peso;

  // first: visitado?
  // second: predecesor
  vector< pair<bool, int> > nodos_visitados(agm.n, make_pair(false, -1));

  queue<int> nodos_pendientes;
  nodos_pendientes.push(cierra_anillo.nodo1);

  // Hago BFS para encontrar el camino de nodo1 a nodo2
  while (!nodos_pendientes.empty() && !nodos_visitados[cierra_anillo.nodo2].first) {
    int nodo = nodos_pendientes.front();
    nodos_pendientes.pop();

    nodos_visitados[nodo].first = true;

    for (int i = 0; i < (int) agm.matriz_conexiones.size(); i++) {
      if (agm.matriz_conexiones[nodo][i] != -1 && !nodos_visitados[i].first) {
        nodos_visitados[i].second = nodo;
        nodos_pendientes.push(i);
      }
    }
  }

  vector<Arista> en_el_anillo, fuera_del_anillo;
  en_el_anillo.push_back(cierra_anillo);

  int nodo = cierra_anillo.nodo2;

  // Cargo todas las aristas que forman parte del anillo
  while (nodo != cierra_anillo.nodo1) {
    Arista arista(nodo, nodos_visitados[nodo].second, -1);
    en_el_anillo.push_back(arista);

    // Saco la arista de la matriz del AGM
    agm.matriz_conexiones[nodo][nodos_visitados[nodo].second] = -1;
    agm.matriz_conexiones[nodos_visitados[nodo].second][nodo] = -1;

    nodo = nodos_visitados[nodo].second;
  }

  // Cargo las aristas que quedan
  for (int i = 0; i < agm.n; i++) {
    for (int j = i + 1; j < agm.n; j++) {
      if (agm.matriz_conexiones[i][j] != -1) {
        Arista arista(i, j, -1);
        fuera_del_anillo.push_back(arista);
      }
    }
  }

  return make_pair(en_el_anillo, fuera_del_anillo);
}

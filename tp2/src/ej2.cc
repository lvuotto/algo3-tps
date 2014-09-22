#include <iostream>
#include <cstdio>
#include <map>
#include <sstream>
#include <vector>
#include <queue>
#include "ej2.h"

using namespace std;

int main() {
  vector<Caballo> caballos;
  
  int cantidad_caballos, dimension_tablero;

  cin >> dimension_tablero >> cantidad_caballos;

  for (int i = 0; i < cantidad_caballos; i++) {
    int x, y;
    cin >> x >> y;

    Caballo c = make_pair(x - 1, y - 1);
    caballos.push_back(c);
  }
  
  pair<int, posicion> respuesta = punto_de_encuentro(caballos, dimension_tablero);
  
  if (respuesta.first == -1) {
    cout << "no" << endl;
  } else {
    cout << respuesta.first << " " <<
            (respuesta.second.first + 1) << " " <<
            (respuesta.second.second + 1) << endl;
  }

  return 0;
}

pair<int, posicion> punto_de_encuentro(vector<Caballo> caballos, int dimension_tablero) {
  vector<Tablero> tableros;

  for (auto c = caballos.begin(); c != caballos.end(); c++) {
    Tablero t(dimension_tablero);
    queue<pair<posicion, int> > casilleros;
    casilleros.push(make_pair((posicion) *c, 0));
    llenar_tablero(t, casilleros);
    tableros.push_back(t);
  }
  
  int min_i = -1;
  int min_j = -1;
  int min = -1;

  for (int i = 0; i < dimension_tablero; i++) {
    for (int j = 0; j < dimension_tablero; j++) {
      int sum = 0;

      for (auto tablero = tableros.begin(); tablero != tableros.end(); tablero++) {
        if (tablero->casilleros[i][j] == -1) {
          sum = -1;
        } else if (sum != -1) {
          sum += tablero->casilleros[i][j];
        }
      }

      if (sum != -1 && (min == -1 || sum < min)) {
        min = sum;
        min_i = i;
        min_j = j;
      }
    }
  }
  
  return make_pair(min, make_pair(min_i, min_j));
}

void llenar_tablero(Tablero& t, queue<pair<posicion, int> >& casilleros) {
  while (!casilleros.empty()) {
    posicion p = casilleros.front().first;
    int nivel = casilleros.front().second;
    casilleros.pop();

    if (t.casilleros[p.first][p.second] != -1) {
      continue;
    }

    t.casilleros[p.first][p.second] = nivel;

    if (p.first - 2 >= 0 && p.second + 1 < t.dimension && t.casilleros[p.first - 2][p.second + 1] == -1) {
      casilleros.push(make_pair(make_pair(p.first - 2, p.second + 1), nivel + 1));
    }
    if (p.first - 1 >= 0 && p.second + 2 < t.dimension && t.casilleros[p.first - 1][p.second + 2] == -1) {
      casilleros.push(make_pair(make_pair(p.first - 1, p.second + 2), nivel + 1));
    }
    if (p.first + 1 < t.dimension && p.second - 2 >= 0 && t.casilleros[p.first + 1][p.second - 2] == -1) {
      casilleros.push(make_pair(make_pair(p.first + 1, p.second - 2), nivel + 1));
    }
    if (p.first - 2 >= 0 && p.second - 1 >= 0 && t.casilleros[p.first - 2][p.second - 1] == -1) {
      casilleros.push(make_pair(make_pair(p.first - 2, p.second - 1), nivel + 1));
    }
    if (p.first + 1 < t.dimension && p.second + 2 < t.dimension && t.casilleros[p.first + 1][p.second + 2] == -1) {
      casilleros.push(make_pair(make_pair(p.first + 1, p.second + 2), nivel + 1));
    }
    if (p.first + 2 < t.dimension && p.second - 1 >= 0 && t.casilleros[p.first + 2][p.second - 1] == -1) {
      casilleros.push(make_pair(make_pair(p.first + 2, p.second - 1), nivel + 1));
    }
    if (p.first + 2 < t.dimension && p.second + 1 < t.dimension && t.casilleros[p.first + 2][p.second + 1] == -1) {
      casilleros.push(make_pair(make_pair(p.first + 2, p.second + 1), nivel + 1));
    }
    if (p.first - 1 >= 0 && p.second - 2 >= 0 && t.casilleros[p.first - 1][p.second - 2] == -1) {
      casilleros.push(make_pair(make_pair(p.first - 1, p.second - 2), nivel + 1));
    }
  }
}
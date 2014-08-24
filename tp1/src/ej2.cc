
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

enum posicion_t {IZQUIERDA, DERECHA};

enum direccion_t {HORIZONTAL, VERTICAL};

struct Punto {
  unsigned int x;
  unsigned int y;
  posicion_t posicion;

  Punto(unsigned int _x, unsigned int _y, posicion_t _posicion) {
    x = _x;
    y = _y;
    posicion = _posicion;
  }

  Punto() {
  }

  bool operator < (const Punto& otro) const {
    return x < otro.x || (x == otro.x && y < otro.y);
  }
};

vector<unsigned int> calcular_horizonte (vector<Punto>& puntos);
void                 imprimir_horizonte (vector<unsigned int>& solucion);
unsigned int         maximo             (multiset<unsigned int>& alturas);


int main () {
  unsigned int cant_edificios, izquierda, derecha, altura;

  cin >> cant_edificios;

  while (cant_edificios != 0) {
    vector<Punto> puntos;
    puntos.resize(cant_edificios * 2);

    for (unsigned int i = 0; i < cant_edificios; i++) {
      /* Para cada edificio se agregan las coordenadas de los dos puntos
         que lo definen */
      cin >> izquierda >> altura >> derecha;

      puntos[i * 2] = Punto(izquierda, altura, IZQUIERDA);
      puntos[i * 2 + 1] = Punto(derecha, altura, DERECHA);
    }

    vector<unsigned int> solucion = calcular_horizonte(puntos);
    imprimir_horizonte(solucion);

    cin >> cant_edificios;
  }

  return 0;
}

/**
 * Devuelve los puntos necesarios para formar el horizonte de los edificios.
 **/
vector<unsigned int> calcular_horizonte (vector<Punto>& puntos) {
  multiset<unsigned int> alturas;

  vector<unsigned int> solucion;
  
  sort(puntos.begin(), puntos.end());
  
  auto punto = puntos.begin();
  
  solucion.push_back(punto->x);
  solucion.push_back(punto->y);
  
  while (punto->x == solucion[0]) {
    solucion[1] = punto->y;
    alturas.insert(punto->y);
    punto++;
  }

  while (punto != puntos.end()) {
    if (punto->posicion == IZQUIERDA) {
      /**
       * 
       **/
      if (punto->y > solucion.back()) {
        if (punto->x > solucion[solucion.size() - 2]) {
          solucion.push_back(punto->x);
          solucion.push_back(punto->y);
        } else {
          solucion[solucion.size() - 1] = punto->y;
        }
      }

      alturas.insert(punto->y);
    } else {
      /**
       * 
       **/
      if (punto->y == maximo(alturas)) {
        alturas.erase(alturas.find(punto->y));

        if (punto->y > maximo(alturas)) {
          solucion.push_back(punto->x);
          solucion.push_back(maximo(alturas));
        }
      } else {
        if (!alturas.empty()) {
          alturas.erase(alturas.find(punto->y));
        }
      }
    }
    
    punto++;
  }

  return solucion;
}


/**
 * Devuelve el valor máximo de un multiset ó el número 0 si está vacío.
 **/
unsigned int maximo (multiset<unsigned int>& alturas) {
  if (alturas.empty()) {
    return 0;
  }

  return *(alturas.rbegin());
}


/**
 * Imprime los puntos requeridos para marcar el horizonte.
 **/
void imprimir_horizonte (vector<unsigned int>& solucion) {
  auto it = solucion.begin();

  cout << *it;

  for (it++; it != solucion.end(); it++) {
    cout << " " << *it;
  }

  cout << endl;
}

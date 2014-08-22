
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

enum posicion_t {IZQUIERDA, DERECHA};

enum direccion_t {HORIZONTAL, VERTICAL};

struct Coordenada {
  unsigned int x;
  unsigned int y;
  posicion_t posicion;

  Coordenada(unsigned int _x, unsigned int _y, posicion_t _posicion) {
    x = _x;
    y = _y;
    posicion = _posicion;
  }

  Coordenada() {
  }

  bool operator < (const Coordenada& otra) const {
    return x < otra.x || (x == otra.x && y < otra.y);
  }
};

vector<unsigned int> calcular_horizonte (vector<Coordenada>& coordenadas);
void                 agregar_avance     (vector<unsigned int>& avances, unsigned int x, unsigned int y, direccion_t& direccion);
void                 imprimir_avances   (vector<unsigned int>& avances);
unsigned int         maximo             (multiset<unsigned int>& alturas);


int main () {
  unsigned int cant_edificios, izquierda, derecha, altura;

  cin >> cant_edificios;

  while (cant_edificios != 0) {
    vector<Coordenada> coordenadas;
    coordenadas.resize(cant_edificios * 2);

    for (unsigned int i = 0; i < cant_edificios; i++) {
      /* Para cada edificio se agregan las coordenadas de los dos puntos
         que lo definen */
      cin >> izquierda >> altura >> derecha;

      coordenadas[i * 2] = Coordenada(izquierda, altura, IZQUIERDA);
      coordenadas[i * 2 + 1] = Coordenada(derecha, altura, DERECHA);
    }

    vector<unsigned int> avances = calcular_horizonte(coordenadas);
    imprimir_avances(avances);

    cin >> cant_edificios;
  }

  return 0;
}

/**
 * Devuelve los avances en X y en Y que deben realizarse para formar el
 * horizonte de los edificios.
 **/
vector<unsigned int> calcular_horizonte (vector<Coordenada>& coordenadas) {
  multiset<unsigned int> alturas;

  Coordenada* ultima_coordenada = NULL;

  vector<unsigned int> avances;

  direccion_t direccion_avanzar = HORIZONTAL;

  sort(coordenadas.begin(), coordenadas.end());

  for (auto coordenada = coordenadas.begin(); coordenada != coordenadas.end(); coordenada++) {
    if (ultima_coordenada == NULL) {
      ultima_coordenada = &(*coordenada);

      alturas.insert(coordenada->y);
    } else if (coordenada->posicion == IZQUIERDA) {
      /**
       * Situaciones cuando la nueva coordenada es IZQUIERDA:
       * ----------------------------------------------------------------------
       * Si la nueva es más alta y más a la derecha:
       *                  NUEVA_COORDENADA
       *                        |
       *                        |
       * ULTIMA_COORDENADA------A
       *
       * Se agrega el punto A al horizonte.
       * Y el puntero a la última ahora apunta a la nueva.
       *
       * ----------------------------------------------------------------------
       * Si la nueva es igual o menos alta:
       * ULTIMA_COORDENADA------NUEVA_COORDENADA
       * ó
       * ULTIMA_COORDENADA------A
       *                        |
       *                        |
       *                  NUEVA_COORDENADA
       *
       * Únicamente se agrega su altura al multiconjunto de alturas.
       **/
      if (coordenada->y > ultima_coordenada->y) {
        if (coordenada->x > ultima_coordenada-> x) {
          agregar_avance(avances, ultima_coordenada->x, ultima_coordenada->y, direccion_avanzar);

          agregar_avance(avances, coordenada->x, ultima_coordenada->y, direccion_avanzar);
        }

        ultima_coordenada = &(*coordenada);
      }

      alturas.insert(coordenada->y);
    } else {
      /**
       * Situaciones cuando la nueva coordenada es DERECHA:
       * ----------------------------------------------------------------------
       * Si la nueva es la única con la altura actual:
       * ALTURA_ACTUAL-----NUEVA_COORDENADA
       *                           |
       *                           |
       *                           A--------NUEVA_ALTURA_MÁXIMA
       *
       * Se agrega el punto de la nueva coordenada al horizonte.
       * Y el puntero a la última ahora apunta al punto A.
       *
       * ----------------------------------------------------------------------
       * Si la nueva es menos alta:
       * ALTURA_ACTUAL-----NUEVA_ALTURA_MÁXIMA
       *                           |
       *                           |
       *                    NUEVA_COORDENADA
       * ó si la siguiente altura máxima se mantiene
       *
       * Únicamente se elimina su altura del multiconjunto de alturas.
       **/
      if (coordenada->y == maximo(alturas)) {
        alturas.erase(alturas.find(coordenada->y));

        if (coordenada->y > maximo(alturas)) {
          agregar_avance(avances, ultima_coordenada->x, ultima_coordenada->y, direccion_avanzar);

          agregar_avance(avances, coordenada->x, coordenada->y, direccion_avanzar);

          ultima_coordenada = new Coordenada(coordenada->x, maximo(alturas), IZQUIERDA);
        }
      } else {
        if (!alturas.empty()) {
          alturas.erase(alturas.find(coordenada->y));
        }
      }
    }
  }

  /* Se agregan los avances necesarios para ir hasta la última coordenada y de
   * allí hacia el 0 final */
  agregar_avance(avances, ultima_coordenada->x, ultima_coordenada->y, direccion_avanzar);
  agregar_avance(avances, ultima_coordenada->x, 0, direccion_avanzar);

  return avances;
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
 * Agrega el avance necesario correspondiente a la coordenada X e Y.
 **/
void agregar_avance (vector<unsigned int>& avances, unsigned int x, unsigned int y, direccion_t& direccion) {
  if (direccion == HORIZONTAL) {
    avances.push_back(x);
    direccion = VERTICAL;
  } else {
    avances.push_back(y);
    direccion = HORIZONTAL;
  }
}


/**
 * Imprime los avances requeridos para realizar el horizonte.
 **/
void imprimir_avances (vector<unsigned int>& avances) {
  auto it = avances.begin();

  cout << *it;

  for (it++; it != avances.end(); it++) {
    cout << " " << *it;
  }

  cout << endl;
}

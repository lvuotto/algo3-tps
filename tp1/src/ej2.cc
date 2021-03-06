#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#include "ej2.h"
#include "tiempo.h"


#define CANTIDAD 25


using namespace std;


int main()
{
  unsigned int cant_edificios, izquierda, derecha, altura;

  cin >> cant_edificios;

  while (cant_edificios != 0) {
    vector<Vertice> vertices;
    vertices.resize(cant_edificios * 2);

    for (unsigned int i = 0; i < cant_edificios; i++) {
      /* Para cada edificio se agregan los 2 vértices que lo definen */
      cin >> izquierda >> altura >> derecha;

      vertices[i * 2] = Vertice(izquierda, altura, IZQUIERDA);
      vertices[i * 2 + 1] = Vertice(derecha, altura, DERECHA);
    }

    vector<Punto> horizonte;
    unsigned long inicio, fin, min;
    MEDIR_TIEMPO_START(inicio);
    horizonte = calcular_horizonte(vertices);
    MEDIR_TIEMPO_STOP(fin);
    min = fin - inicio;
    for (int i = 1; i < CANTIDAD; i++) {
      MEDIR_TIEMPO_START(inicio);
      horizonte = calcular_horizonte(vertices);
      MEDIR_TIEMPO_STOP(fin);
      min = fin - inicio < min ? fin - inicio : min;
    }
    cerr << cant_edificios << " " << min << endl;
    imprimir_horizonte(horizonte);

    cin >> cant_edificios;
  }

  return 0;
}

/**
 * Devuelve los puntos necesarios para formar el horizonte de los edificios.
 **/
vector<Punto> calcular_horizonte(vector<Vertice>& vertices)
{
  multiset<unsigned int> alturas;

  vector<Punto> horizonte;

  sort(vertices.begin(), vertices.end());

  auto vertice = vertices.begin();

  horizonte.push_back(Punto(vertice->x, vertice->y));
  alturas.insert(vertice->y);
  vertice++;

  while (vertice != vertices.end()) {
    if (vertice->posicion_pared == IZQUIERDA) {
      /**
       * Si es un vértice más alto, pero sobre la misma coordenada X, se
       * actualiza la altura del último punto.
       * Pero si además está más adelante en X, se carga un nuevo punto
       * para marcar el horizonte.
       **/
      if (vertice->y > horizonte.back().y) {
        if (vertice->x > horizonte.back().x) {
          horizonte.push_back(Punto(vertice->x, vertice->y));
        } else {
          horizonte[horizonte.size() - 1].y = vertice->y;
        }
      }

      alturas.insert(vertice->y);
    } else {
      alturas.erase(alturas.find(vertice->y));
      /**
       * Si es un vértice de pared derecha y es la última de su altura, se
       * carga el punto que se forma al bajar a la siguiente altura.
       **/
      if (vertice->y > maximo(alturas)) {
        horizonte.push_back(Punto(vertice->x, maximo(alturas)));
      }
    }

    vertice++;
  }

  return horizonte;
}


/**
 * Devuelve el valor máximo de un multiset ó el número 0 si está vacío.
 **/
unsigned int maximo(multiset<unsigned int>& alturas)
{
  if (alturas.empty()) {
    return 0;
  }

  return *(alturas.rbegin());
}


/**
 * Imprime los puntos requeridos para marcar el horizonte.
 **/
void imprimir_horizonte(vector<Punto>& horizonte)
{
  auto it = horizonte.begin();

  cout << it->x << " " << it->y;

  for (it++; it != horizonte.end(); it++) {
    cout << " " << it->x << " " << it->y;
  }

  cout << endl;
}

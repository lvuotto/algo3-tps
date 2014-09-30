#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include <deque>

#include "ej3.h"
#include "tiempo.h"


#define CANTIDAD 5


using namespace std;


void its_a_kind_of_poda(vector<Camion>& camiones);


int main()
{
  int cantidad_elementos;

  cin >> cantidad_elementos;
  while (cantidad_elementos != 0) {
    cin >> umbral;
    peligrosidades.resize(cantidad_elementos);

    for (auto it = peligrosidades.begin(); it != peligrosidades.end(); it++) {
      it->resize(cantidad_elementos);
    }

    for (int i = 0; i < cantidad_elementos - 1; i++) {
      peligrosidades[i][i] = 0;

      for (int j = i + 1; j < cantidad_elementos; j++) {
        cin >> peligrosidades[i][j];
        peligrosidades[j][i] = peligrosidades[i][j];
      }
    }

    deque<Elemento> elementos;
    for (int i = 0; i < cantidad_elementos; i++) {
      elementos.push_back(Elemento(i));
    }
    sort(elementos.begin(), elementos.end());

    deque<Elemento> backup_elementos = elementos;
    vector<Camion> solucion;
    unsigned long inicio, fin, min;
    MEDIR_TIEMPO_START(inicio);
    solucion = biohazard(elementos);
    MEDIR_TIEMPO_STOP(fin);
    elementos = backup_elementos;
    min = fin - inicio;
    for (int i = 0; i < CANTIDAD; i++) {
      MEDIR_TIEMPO_START(inicio);
      solucion = biohazard(elementos);
      MEDIR_TIEMPO_STOP(fin);
      elementos = backup_elementos;
      min = fin - inicio < min ? fin - inicio : min;
    }
    cerr << cantidad_elementos << " "
         << umbral << " "
         << min << endl;
    mostrar_solucion(solucion, cantidad_elementos);

    cin >> cantidad_elementos;
  }

  return 0;
}


vector<Camion> biohazard(deque<Elemento>& elementos)
{
  vector<Camion> camiones;
  /*its_a_kind_of_poda(camiones);*/
  while (!backtracking(camiones, elementos))
    camiones.push_back(Camion());
  return camiones;
}


bool backtracking(vector<Camion>& camiones, deque<Elemento>& elementos)
{
  if (elementos.empty()) {
    return true;
  }

  Elemento elemento = *elementos.begin();
  int numero_elemento = elemento.numero;
  elementos.pop_front();

  for (auto c = camiones.begin(); c != camiones.end(); c++) {
    if (c->entra(numero_elemento)) {
      c->agregar_elemento(numero_elemento);
      if (backtracking(camiones, elementos)) {
        return true;
      } else {
        c->eliminar_elemento(numero_elemento);
        /* Si sacamos y el camión está vacío, quiere decir que ya lo
         * habíamos puesto en un camión vacío. No tiene sentido seguir
         * intentando en otros camiones. Lo único que ganamos son ciclos de
         * clock. */
        if (c->elementos.empty()) break;
      }
    }
  }
  elementos.push_front(elemento);

  return false;
}


void its_a_kind_of_poda(vector<Camion>& camiones)
{
  vector<pair<int, int> > muy_peligrosos;
  for (unsigned int i = 0; i < peligrosidades.size(); i++) {
    for (unsigned int j = 0; j < peligrosidades.size(); j++) {
      if (peligrosidades[i][j] > umbral) {
        muy_peligrosos.push_back(make_pair(i, j));
      }
    }
  }

  /* Necesito al menos 1 camión. */
  camiones.push_back(Camion());

  /* Si hay pares que se pasan del umbral, necesito al menos 2 camiones. */
  if (!muy_peligrosos.empty())
    camiones.push_back(Camion());

  /* Si pasa algo mágico, puedo afirmar que necesito al menos 3 camiones. */
  /* BTW, `muy_peligrosos` está ordenado, dado el modo en el que se crea. */
  /*for (auto p = muy_peligrosos.begin(); p != muy_peligrosos.end(); p++) {
    if (p->first == (p + 1)->first) {
    }
  }*/
}


void mostrar_solucion(vector<Camion>& camiones, int cantidad_elementos)
{
  vector<int> solucion;
  solucion.resize(cantidad_elementos);

  int c = 0;
  for (auto i = camiones.begin(); i != camiones.end(); i++, c++) {
    for (auto j = i->elementos.begin(); j != i->elementos.end(); j++) {
      solucion[*j] = c;
    }
  }

  cout << camiones.size();
  for (auto it = solucion.begin(); it != solucion.end(); it++)
    cout << " " << *it + 1;
  cout << endl;
}

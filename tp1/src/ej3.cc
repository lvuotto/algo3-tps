#include <iostream>
#include <set>
#include <vector>

#include "tiempo.h"


#define CANTIDAD 5


using namespace std;


typedef vector<vector<int> > matriz;


int umbral;
matriz peligrosidades;


struct camion {
  camion() : peligrosidad_(0) {}

  void agregar_elemento(int elemento)
  {
    peligrosidad_ += calcular_peligrosidad(elemento);
    elementos.insert(elemento);
  }

  void eliminar_elemento(int elemento)
  {
    elementos.erase(elemento);
    peligrosidad_ -= calcular_peligrosidad(elemento);
  }

  bool entra(int elemento) const
  {
    return elementos.empty() ||
           (peligrosidad_ + calcular_peligrosidad(elemento) <= umbral);
  }

  int calcular_peligrosidad(int elemento) const
  {
    int suma = 0;
    for (auto el = elementos.begin(); el != elementos.end(); el++) {
      suma += peligrosidades[*el][elemento - 1];
    }

    return suma;
  }

  set<int> elementos;

private:
  int peligrosidad_;
};


vector<camion> biohazard(set<int>& elementos);
bool backtracking(vector<camion>& camiones, set<int>& elementos);
void mostrar_solucion(vector<camion>& camiones, int cantidad_elementos);


int main()
{
  int cantidad_elementos;

  cin >> cantidad_elementos;
  while (cantidad_elementos != 0) {
    cin >> umbral;
    peligrosidades.resize(cantidad_elementos - 1);

    for (auto it = peligrosidades.begin(); it != peligrosidades.end(); it++) {
      it->resize(cantidad_elementos - 1);
    }

    for (int i = 0; i < cantidad_elementos - 1; i++) {
      for (int j = 0; j < i; j++) {
        peligrosidades[i][j] = 0;
      }
      for (int j = i; j < cantidad_elementos - 1; j++) {
        cin >> peligrosidades[i][j];
      }
    }

    set<int> elementos;
    for (int i = 0; i < cantidad_elementos; i++) {
      elementos.insert(i);
    }

    set<int> backup_elementos = elementos;
    vector<camion> solucion;
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


vector<camion> biohazard(set<int>& elementos)
{
  vector<camion> camiones;
  do {
    camiones.push_back(camion());
  } while (!backtracking(camiones, elementos));
  return camiones;
}


bool backtracking(vector<camion>& camiones, set<int>& elementos)
{
  if (elementos.empty()) {
    return true;
  }

  int elemento = *elementos.begin();
  elementos.erase(elementos.begin());
  for (auto c = camiones.begin(); c != camiones.end(); c++) {
    if (c->entra(elemento)) {
      c->agregar_elemento(elemento);
      if (backtracking(camiones, elementos)) {
        return true;
      } else {
        c->eliminar_elemento(elemento);
      }
    }
  }
  elementos.insert(elemento);

  return false;
}


void mostrar_solucion(vector<camion>& camiones, int cantidad_elementos)
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

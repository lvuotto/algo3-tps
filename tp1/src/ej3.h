#include <vector>
#include <set>


using namespace std;


typedef vector<vector<int> > matriz;


int umbral;
matriz peligrosidades;


struct Camion {
  Camion() : peligrosidad_(0) {}

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
      suma += peligrosidades[*el][elemento];
    }

    return suma;
  }

  set<int> elementos;

private:
  int peligrosidad_;
};


struct Elemento {
  int numero;
  double comparador;

  Elemento(int num)
  {
    numero = num;
    int suma = 0.0;
    for (unsigned int i = 0; i < peligrosidades.size(); i++) {
      suma += peligrosidades[i][numero];
    }

#ifndef BT_PROMEDIO
    comparador = (double) suma;
#else
    comparador = suma / (double) peligrosidades.size();
#endif
  }

  bool operator<(const Elemento& otro) const
  {
#ifndef BT_ASCENDENTE
    return comparador > otro.comparador;
#else
    return comparador < otro.comparador;
#endif
  }
};


vector<Camion> biohazard(deque<Elemento>& elementos);
bool backtracking(vector<Camion>& camiones, deque<Elemento>& elementos);
void mostrar_solucion(vector<Camion>& camiones, int cantidad_elementos);

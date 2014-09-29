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
      suma += peligrosidades[*el][elemento - 1];
    }

    return suma;
  }

  set<int> elementos;

private:
  int peligrosidad_;
};


vector<Camion> biohazard(set<int>& elementos);
bool backtracking(vector<Camion>& camiones, set<int>& elementos);
void mostrar_solucion(vector<Camion>& camiones, int cantidad_elementos);

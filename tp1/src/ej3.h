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
    //cout << "Agrego elemento " << elemento << " peligrosidad anterior: " << peligrosidad_;
    peligrosidad_ += calcular_peligrosidad(elemento);
    //cout << " nueva peligrosidad: " << peligrosidad_ << " umbral: " << umbral << endl;
    elementos.insert(elemento);
  }

  void eliminar_elemento(int elemento)
  {
    //cout << "Saco el " << elemento << endl;
    elementos.erase(elemento);
    peligrosidad_ -= calcular_peligrosidad(elemento);
  }

  bool entra(int elemento) const
  {
    //cout << "Trato de ver si entra el " << elemento << endl;
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
  float comparador;

  Elemento(int num) {
    numero = num;
    comparador = 0.0;
    for (unsigned int i = 0; i < peligrosidades.size(); i++) {
      comparador += (float) peligrosidades[i][numero];
    }

    // comparador /= peligrosidades.size(); // Descomentar para usar el promedio en vez de la suma!
  }

  bool operator<(const Elemento& otro) const {
    return comparador > otro.comparador; // Descomentar para que ordene de mayor a menor!
    // return comparador < otro.comparador; // Descomentar para que ordene de menor a mayor!
  }
};


vector<Camion> biohazard(deque<Elemento>& elementos);
bool backtracking(vector<Camion>& camiones, deque<Elemento>& elementos);
void mostrar_solucion(vector<Camion>& camiones, int cantidad_elementos);

#include <iostream>
#include <set>
#include <vector>


using namespace std;


typedef vector< vector<int> > matriz;


int kMaximaPeligrosidad;
matriz matrizPeligrosidades;


struct camion {
  camion() : elementos(), peligrosidad(0) {};
  
  void agregarElemento(int& elemento) {
    elementos.insert(elemento);
    peligrosidad += calcularPeligrosidad(elemento);
  }
  
  void eliminarElemento(int& elemento) {
    elementos.erase(elemento);
    
    peligrosidad -= calcularPeligrosidad(elemento);
  }
  
  bool entra(int& elemento) const {
    return peligrosidad + calcularPeligrosidad(elemento) <= kMaximaPeligrosidad;
  }
  
  int calcularPeligrosidad(int& elemento) const {
    int suma = 0;
    
    for (auto el = elementos.begin(); el != elementos.end(); el++) {
      cout << *el << endl;
      suma += matrizPeligrosidades[elemento][*el];
    }
  
    return suma; 
  }
  
  set <int> elementos;
  
private:
  int peligrosidad;
};


vector<camion> biohazard (set<int>& elementos);
bool backtracking (vector<camion>& camiones, set<int>& elementos);
void mostrar_solucion (vector<camion>& camiones, int cantidadElementos);


int main ()
{
  int cantidadElementos;
  
  cin >> cantidadElementos;
  while (cantidadElementos != 0) {
    cin >> kMaximaPeligrosidad;
    matrizPeligrosidades.resize(cantidadElementos - 1);
    
    for (auto it = matrizPeligrosidades.begin(); it != matrizPeligrosidades.end(); it++) {
      it->resize(cantidadElementos - 1);
    }
    
    for (int i = 0; i < cantidadElementos - 1; i++) {
      for (int j = 0; j < i; j++) {
        matrizPeligrosidades[i][j] = 0;
      }
      for (int j = i; j < cantidadElementos - 1; j++) {
        cin >> matrizPeligrosidades[i][j];
      }
    }
    
    set<int> elementos;
    for (int i = 0; i < cantidadElementos; i++) {
      elementos.insert(i);
    }
    
    vector<camion> solucion = biohazard(elementos);
    mostrar_solucion(solucion, cantidadElementos);
    
    cin >> cantidadElementos;
  }
  
  return 0;
}


vector <camion> biohazard (set<int>& elementos)
{
  vector <camion> camiones;
  do {    
    camiones.push_back(camion());
  } while (!backtracking(camiones, elementos));
  return camiones;
}


bool backtracking (vector <camion>& camiones, set <int>& elementos)
{
  if (elementos.empty()) {
    return true;
  }
  int elemento = *elementos.begin();
  elementos.erase(elementos.begin());
  for (vector<camion>::iterator c = camiones.begin(); c != camiones.end(); c++) {
    if (c->entra(elemento)) {
      c->agregarElemento(elemento);
      if (backtracking(camiones, elementos)) {
        return true;
      } else {
        c->eliminarElemento(elemento);
      }
    }
  }
  elementos.insert(elemento);
  return false;
}


void mostrar_solucion (vector<camion>& camiones, int cantidadElementos) {
  vector<int> solucion;
  solucion.resize(cantidadElementos);
  
  int c = 0;
  for (auto i = camiones.begin(); i != camiones.end(); i++, c++) {
    for (auto j = i->elementos.begin(); j != i->elementos.end(); j++) {
      solucion[*j] = c;
    }
  }
  
  cout << camiones.size();
  for (auto it = solucion.begin(); it != solucion.end(); it++)
    cout << " " << *it;
  cout << endl;
}

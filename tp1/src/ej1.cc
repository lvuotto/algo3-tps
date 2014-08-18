
#include <iostream>
#include <vector>


using namespace std;


vector<int> cruzar_puente   (int salto_maximo, vector<int>& puente);
void        imprimir_saltos (vector<int>& saltos);


int main () {
  int n, c;
  
  cin >> n;
  
  while (n != 0) {
    cin >> c;
    vector<int> puente;
    puente.resize(n);
    
    for (int i = 0; i < n; i++) {
      cin >> puente[i];
    }

    vector<int> saltos = cruzar_puente(c, puente);
    imprimir_saltos(saltos);
    
    cin >> n;
  }
    
  return 0;
}


/**
 * Devuelve una lista con los tablones a los cuales se debe saltar
 * ó una lista vacía si es imposible.
 **/
vector<int> cruzar_puente (int salto_maximo, vector<int>& puente) {
  vector<int> saltos;
  
  unsigned int salto_actual;
  unsigned int posicion_actual = 0;
  
  while (posicion_actual <= puente.size()) {
    salto_actual = salto_maximo;
    
    /* Se chequea si el tablón al cual voy a saltar está ó no sano. */
    while (puente[posicion_actual + salto_actual - 1] == 1) {
      salto_actual--;
      if (salto_actual == 0) {
        return vector<int>();
      }
    }

    posicion_actual += salto_actual;
    /* Se agrega al vector de resultados el tablón al cual se puede saltar. */
    saltos.push_back(posicion_actual);
  }
  
  return saltos;
}


void imprimir_saltos (vector<int>& saltos) {
  if (saltos.empty()) {
    cout << "no" << endl;
  } else {
    cout << saltos.size();
    for (auto it = saltos.begin(); it != saltos.end(); it++) {
      cout << " " << *it;
    }
    cout << endl;
  }
}

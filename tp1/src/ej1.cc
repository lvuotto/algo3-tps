
#include <iostream>
#include <vector>


using namespace std;


vector<unsigned int> cruzar_puente   (unsigned int salto_maximo, vector<unsigned int>& puente);
bool                 posible_cruzar  (unsigned int salto_maximo, vector<unsigned int>& puente);
bool                 puede_saltar    (vector<unsigned int>& puente, unsigned int tablon);
void                 imprimir_saltos (vector<unsigned int>& saltos);


int main () {
  unsigned int n, c;

  cin >> n;

  while (n != 0) {
    cin >> c;
    vector<unsigned int> puente;
    puente.resize(n);

    for (unsigned int i = 0; i < n; i++) {
      cin >> puente[i];
    }

    vector<unsigned int> saltos = cruzar_puente(c, puente);
    imprimir_saltos(saltos);

    cin >> n;
  }

  return 0;
}


/**
 * Devuelve una lista con los tablones a los cuales se debe saltar
 * ó una lista vacía si es imposible.
 **/
vector<unsigned int> cruzar_puente (unsigned int salto_maximo, vector<unsigned int>& puente) {
  if (!posible_cruzar(salto_maximo, puente)) {
    return vector<unsigned int>();
  }

  vector<unsigned int> saltos;

  unsigned int salto_actual;
  unsigned int posicion_actual = 0;

  while (posicion_actual <= puente.size()) {
    salto_actual = salto_maximo;

    /* Se prueba desde el último para atrás hasta encontrar un lugar para saltar */
    while (!puede_saltar(puente, posicion_actual + salto_actual - 1)) {
      salto_actual--;
    }

    posicion_actual += salto_actual;
    /* Se agrega al vector de resultados el tablón al cual se puede saltar. */
    saltos.push_back(posicion_actual);
  }

  return saltos;
}


/**
 * Calcula si los tablones rotos consecutivos son siempre menores al salto
 * máximo, es decir, si se puede cruzar el puente
 **/
bool posible_cruzar (unsigned int salto_maximo, vector<unsigned int>& puente) {
  unsigned int tablones_rotos_consecutivos = 0;

  for (unsigned int i = 0; i < puente.size(); i++) {
    if (puede_saltar(puente, i)) {
      tablones_rotos_consecutivos = 0;
    } else {
      tablones_rotos_consecutivos++;
    }

    if (tablones_rotos_consecutivos >= salto_maximo) {
      return false;
    }
  }

  return true;
}


/**
 * Devuelve verdadero cuando es un tablón sano o si se terminó el puente
 **/
bool puede_saltar (vector<unsigned int>& puente, unsigned int tablon) {
  return tablon >= puente.size() || puente[tablon] == 0;
}


void imprimir_saltos (vector<unsigned int>& saltos) {
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

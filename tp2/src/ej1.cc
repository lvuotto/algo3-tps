#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

#include "ej1.h"

using namespace std;

int main () {
  string ciudad_inicial, ciudad_final, origen, destino;
  unsigned int total_vuelos, salida, llegada;
  vector<Vuelo> vuelos;

  cin >> ciudad_inicial >> ciudad_final >> total_vuelos;

  for (unsigned int i = 1; i <= total_vuelos; i++) {
    cin >> origen >> destino >> salida >> llegada;
    vuelos.push_back(Vuelo(i, origen, destino, salida, llegada));
  }

  vector<Vuelo> viaje_llega_antes = mas_temprano(ciudad_inicial, ciudad_final, vuelos);
  imprimir_vuelos(viaje_llega_antes);

  return 0;
}

vector<Vuelo> mas_temprano(string& ciudad_inicial, string& ciudad_final, vector<Vuelo>& vuelos) {
  // Mantiene el horario mínimo posible de llegada a cada ciudad
  map<string, Vuelo> min_horarios_llegada;
  vector<Vuelo> viaje_llega_antes;

  sort(vuelos.begin(), vuelos.end());

  // Carga los horarios mínimos
  for (auto vuelo = vuelos.begin(); vuelo != vuelos.end(); vuelo++) {
    if (es_posible_tomar(ciudad_inicial, min_horarios_llegada, *vuelo)) {
      auto hora_llegada_ciudad = min_horarios_llegada.find(vuelo->destino);

      // Si no hay un vuelo que llegue a la ciudad o si este llega antes, se agrega
      if (hora_llegada_ciudad == min_horarios_llegada.end() || hora_llegada_ciudad->second.llegada > vuelo->llegada) {
        min_horarios_llegada[vuelo->destino] = *vuelo;
      }
    }
  }

  // Si se puede llegar a la ciudad final va "saltando" para atrás hasta llegar a la inicial
  auto vuelo = min_horarios_llegada.find(ciudad_final);
  if (vuelo != min_horarios_llegada.end()) {
    while (vuelo->second.origen != ciudad_inicial) {
      viaje_llega_antes.push_back(vuelo->second);

      vuelo = min_horarios_llegada.find(vuelo->second.origen);
    }
    viaje_llega_antes.push_back(vuelo->second);
  }

  return viaje_llega_antes;
}

/**
 * Es posible tomar un vuelo si la ciudad origen es la inicial, o si hay otro
 * vuelo que llega a la ciudad origen 2 horas antes de su salida.
 **/
bool es_posible_tomar(string& ciudad_inicial, map<string, Vuelo>& min_horarios_llegada, Vuelo& vuelo) {
  if (vuelo.origen == ciudad_inicial) {
    return true;
  }

  auto hora_llegada_ciudad = min_horarios_llegada.find(vuelo.origen);

  if (hora_llegada_ciudad == min_horarios_llegada.end()) {
    return false;
  } else {
    return hora_llegada_ciudad->second.llegada <= vuelo.salida - 2;
  }
}

void imprimir_vuelos(vector<Vuelo>& vuelos) {
  if (vuelos.empty()) {
    cout << "no" << endl;
    return;
  }

  cout << vuelos.front().llegada << " ";
  cout << vuelos.size();

  for (auto vuelo = vuelos.rbegin(); vuelo != vuelos.rend(); vuelo++) {
    cout << " " << vuelo->id;
  }

  cout << endl;
}

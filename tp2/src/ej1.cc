#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>

#include "ej1.h"
#include <chrono>

#define CANTIDAD 100

using namespace std;
using namespace std::chrono;

int main () {
  string ciudad_inicial, ciudad_final, origen, destino;
  unsigned int total_vuelos, salida, llegada;
  vector<Vuelo> vuelos;

  cin >> ciudad_inicial >> ciudad_final >> total_vuelos;

  for (unsigned int i = 1; i <= total_vuelos; i++) {
    cin >> origen >> destino >> salida >> llegada;
    vuelos.push_back(Vuelo(i, origen, destino, salida, llegada));
  }
  
  auto backup = vuelos;
  auto inicio = high_resolution_clock::now();
  deque<Vuelo> plan = plan_de_vuelo(ciudad_inicial, ciudad_final, vuelos);
  auto fin = high_resolution_clock::now();
  auto mejor = fin - inicio;
  for (int i = 0; i < CANTIDAD; i++) {
    vuelos = backup;
    inicio = high_resolution_clock::now();
    plan = plan_de_vuelo(ciudad_inicial, ciudad_final, vuelos);
    fin = high_resolution_clock::now();
    /*min = fin - inicio < min ? fin - inicio : fin;*/
    if (fin - inicio < mejor) mejor = fin - inicio;
  }
  cerr << backup.size() << " "
       << duration_cast<microseconds>(mejor).count() << endl;

  imprimir_vuelos(plan);

  return 0;
}

deque<Vuelo> plan_de_vuelo(string& ciudad_inicial, string& ciudad_final, vector<Vuelo>& vuelos) {
  // Mantiene el horario mínimo posible de llegada a cada ciudad
  map<string, Vuelo> rutas;
  deque<Vuelo> plan;

  sort(vuelos.begin(), vuelos.end());

  // Carga los horarios mínimos
  for (auto vuelo = vuelos.begin(); vuelo != vuelos.end(); vuelo++) {
    if (rutas.find(vuelo->destino) == rutas.end() && puede_tomar(ciudad_inicial, rutas, *vuelo, vuelo->predecesor)) {
      // Si no hay un vuelo que llegue a la ciudad y se puede tomar, se lo agrega
      rutas[vuelo->destino] = *vuelo;
    }
  }

  // Si se puede llegar a la ciudad final, itera por los predecesores para armar el plan
  auto ruta = rutas.find(ciudad_final);
  if (ruta != rutas.end()) {
    Vuelo vuelo = ruta->second;
    plan.push_front(vuelo);
    while (vuelo.predecesor) {
      vuelo = *(vuelo.predecesor);
      plan.push_front(vuelo);
    }
  }

  return plan;
}

/**
 * Se puede tomar un vuelo si la ciudad origen es la inicial, o si hay otro
 * vuelo que llega a la ciudad origen 2 horas antes de su salida.
 **/
bool puede_tomar(string& ciudad_inicial, map<string, Vuelo>& rutas, Vuelo& vuelo, Vuelo*& predecesor) {
  if (vuelo.origen == ciudad_inicial) {
    return true;
  }

  auto ruta_origen = rutas.find(vuelo.origen);

  if (ruta_origen != rutas.end() && ruta_origen->second.llegada + 2 <= vuelo.salida) {
    predecesor = &ruta_origen->second;
    return true;
  }

  return false;
}

void imprimir_vuelos(deque<Vuelo>& plan) {
  if (plan.empty()) {
    cout << "no" << endl;
    return;
  }

  cout << plan.back().llegada << " ";
  cout << plan.size();

  for (auto vuelo = plan.begin(); vuelo != plan.end(); vuelo++) {
    cout << " " << vuelo->id;
  }

  cout << endl;
}

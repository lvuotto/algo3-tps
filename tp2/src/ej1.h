#include <vector>
#include <string>
#include <map>
#include <deque>

using namespace std;

struct Vuelo {
  unsigned int id, salida, llegada;

  string origen, destino;

  Vuelo* predecesor;

  Vuelo(unsigned int _id, string _origen, string _destino, unsigned int _salida, unsigned int _llegada) {
    id = _id;
    origen = _origen;
    destino = _destino;
    salida = _salida;
    llegada = _llegada;
    predecesor = NULL;
  }

  Vuelo() {

  }

  bool operator<(const Vuelo& otro) const {
    return llegada < otro.llegada;
  }
};

deque<Vuelo> plan_de_vuelo(string& ciudad_inicial, string& ciudad_final, vector<Vuelo>& vuelos);
void imprimir_vuelos(deque<Vuelo>& vuelos);
bool puede_tomar(string& ciudad_inicial, map<string, Vuelo>& rutas, Vuelo& vuelo, Vuelo*& predecesor);

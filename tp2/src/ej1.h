#include <vector>
#include <string>
#include <map>

using namespace std;

struct Vuelo {
  unsigned int id, salida, llegada;

  string origen, destino;

  Vuelo(unsigned int _id, string _origen, string _destino, unsigned int _salida, unsigned int _llegada) {
    id = _id;
    origen = _origen;
    destino = _destino;
    salida = _salida;
    llegada = _llegada;
  }

  Vuelo() {

  }

  bool operator<(const Vuelo& otro) const {
    return llegada < otro.llegada;
  }
};

vector<Vuelo> mas_temprano(string& ciudad_inicial, string& ciudad_final, vector<Vuelo>& vuelos);
void imprimir_vuelos(vector<Vuelo>& vuelos);
bool es_posible_tomar(string& ciudad_inicial, map<string, Vuelo>& min_horarios_llegada, Vuelo& vuelo);

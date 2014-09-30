#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Posicion;
typedef Posicion Caballo;

struct Tablero {
  Tablero() {}
  Tablero(int n) : dimension(n)
  {
    casilleros.resize(n);
    for (auto it = casilleros.begin(); it != casilleros.end(); it++)
      *it = vector<int>(n, -1);
  }
  
  int dimension;
  vector<vector<int> > casilleros;
};

pair<int, Posicion> punto_de_encuentro(vector<Caballo> caballos, int dimension_tablero);

void llenar_tablero(Tablero& t, Posicion inicio);

#include <vector>
#include <set>


using namespace std;


enum posicion_t {
  IZQUIERDA,
  DERECHA
};

struct Vertice {
  unsigned int x;
  unsigned int y;
  posicion_t posicion_pared;

  Vertice(unsigned int _x, unsigned int _y, posicion_t _posicion_pared)
  {
    x = _x;
    y = _y;
    posicion_pared = _posicion_pared;
  }

  Vertice() {}

  bool operator<(const Vertice& otro) const
  {
    return x < otro.x ||
           (x == otro.x &&
           (y < otro.y ||
           (y == otro.y && posicion_pared < otro.posicion_pared)));
  }
};

struct Punto {
  unsigned int x;
  unsigned int y;

  Punto(unsigned int _x, unsigned int _y)
  {
    x = _x;
    y = _y;
  }
};

vector<Punto> calcular_horizonte(vector<Vertice>& vertices);
void imprimir_horizonte(vector<Punto>& horizonte);
unsigned int  maximo(multiset<unsigned int>& alturas);



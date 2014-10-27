#include <vector>
#include <set>
#include <limits>


using namespace std;


typedef vector<vector<double> > Matriz;

struct Grafo {
  Grafo(unsigned int n);
  void agregar(unsigned int u, unsigned int v, double w);
  double peso(unsigned int u, unsigned int v);
  unsigned int cantidad_nodos();

private:
  Matriz ady_;
};

struct Particion {
  Particion(Grafo& G);
  void agregar(unsigned int v);
  void sacar(unsigned int v);
  bool vacia() const;
  double peso() const;

private:
  double costo(unsigned int v) const;

  Grafo& G_;
  set<int> vertices_;
  double peso_;
};

struct Particiones {
  Particiones(unsigned int k, Grafo& G);
  void agregar(unsigned int i, unsigned int v);
  void sacar(unsigned int i, unsigned int v);
  bool vacia(unsigned int i) const;
  unsigned int cantidad() const;
  unsigned int cantidad_nodos() const;
  vector<unsigned int> solucion() const;
  void actualizar();
  double peso() const;
  double peso_min() const;

private:
  vector<Particion> ps_;
  unsigned int cant_;
  vector<unsigned int> sol_;
  double peso_;
  vector<unsigned int> sol_opt_;
  double peso_min_;
};

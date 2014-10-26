#include <vector>
#include <set>
#include <limits>


using namespace std;


typedef vector<vector<double> > Matriz;

struct Grafo {
  Grafo(unsigned int n) : ady_(n, vector<double>(n, 0.0)) {}

  void agregar(unsigned int u, unsigned int v, double w)
  {
    ady_[u - 1][v - 1] = w;
    ady_[v - 1][u - 1] = w;
  }

  double peso(unsigned int u, unsigned int v)
  {
    return ady_[u - 1][v - 1];
  }

  unsigned int nodos()
  {
    return ady_.size();
  }

private:
  Matriz ady_;
};

struct Particion {
  Particion(Grafo& G) : G_(G), peso_(0.0) {}

  void agregar(unsigned int v)
  {
    peso_ += costo(v);
    vertices_.insert(v);
  }

  void sacar(unsigned int v)
  {
    vertices_.erase(v);
    peso_ -= costo(v);
  }

  double peso() const
  {
    return peso_;
  }

private:
  double costo(unsigned int v) const
  {
    double p = 0.0;
    for (auto it = vertices_.begin(); it != vertices_.end(); it++)
      p += G_.peso(v, *it);
    return p;
  }
 
  Grafo& G_;
  set<int> vertices_;
  double peso_;
};

struct Particiones {
  Particiones(unsigned int k, Grafo& G) :
    ps_(k, Particion(G)),
    cant_(G.nodos()),
    sol_(G.nodos(), 0),
    peso_(0.0),
    sol_opt_(G.nodos(), 0),
    peso_min_(numeric_limits<double>::infinity())
  {}

  void agregar(unsigned int i, unsigned int v)
  {
    peso_ -= ps_[i - 1].peso();
    ps_[i - 1].agregar(v);
    peso_ += ps_[i - 1].peso();
    sol_[v - 1] = i;
  }

  void sacar(unsigned int i, unsigned int v)
  {
    peso_ -= ps_[i - 1].peso();
    ps_[i - 1].sacar(v);
    peso_ += ps_[i - 1].peso();
  }

  unsigned int cantidad() const
  {
    return ps_.size();
  }

  unsigned int nodos() const
  {
    return cant_;
  }

  vector<unsigned int> solucion() const
  {
    return sol_opt_;
  }

  void actualizar()
  {
    sol_opt_ = sol_;
    peso_min_ = peso_;
  }

  double peso() const
  {
    return peso_;
  }

  double peso_min() const
  {
    return peso_min_;
  }

private:
  vector<Particion> ps_;
  unsigned int cant_;
  vector<unsigned int> sol_;
  double peso_;
  vector<unsigned int> sol_opt_;
  double peso_min_;
};

#include <iostream>
#include <vector>
#include "kpmp-exacto.h"


using namespace std;


vector<unsigned int> kpmp(Grafo& G, unsigned int k);
double backtracking(Particiones& ps, unsigned int v);

int main()
{
  unsigned int n, m, k;
  cin >> n >> m >> k;
  Grafo G(n);
  for (unsigned int i = 0; i < m; i++) {
    unsigned int u, v;
    double w;
    cin >> u >> v >> w;
    G.agregar(u, v, w);
  }

  vector<unsigned int> solucion = kpmp(G, k);
  for (auto it = solucion.begin(); it != solucion.end(); it++)
    cout << *it << " ";
  cout << endl;

  return 0;
}


vector<unsigned int> kpmp(Grafo& G, unsigned int k)
{
  Particiones p(k, G);
  backtracking(p, 1);
  return p.solucion();
}


double backtracking(Particiones& ps, unsigned int v)
{
  if (v > ps.nodos())
    return ps.peso();

  for (unsigned int i = 1; i <= ps.cantidad(); i++) {
    ps.agregar(i, v);
    if (backtracking(ps, v + 1) < ps.peso_min()) {
      ps.actualizar();
      return ps.peso();
    } else {
      ps.sacar(i, v);
    }
  }

  return ps.peso();
}

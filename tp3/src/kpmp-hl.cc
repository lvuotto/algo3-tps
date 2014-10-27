#include <iostream>
#include <vector>
#include "kpmp.h"


using namespace std;


vector<unsigned int> kpmp(Grafo& G, unsigned int k);

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
  return p.solucion();
}

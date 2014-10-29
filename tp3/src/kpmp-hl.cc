#include "kpmp.cc"

using namespace std;

Particion kpmp_hl(Particion& particion, Grafo& grafo, unsigned int cantidad_de_conjuntos);


int main()
{
  Entrada entrada = leer_entrada();
  Particion solucion_inicial = leer_solucion(entrada.grafo, entrada.cantidad_de_conjuntos);

  //Particion particion = kpmp_hl(solucion_inicial, entrada.grafo, entrada.cantidad_de_conjuntos);

  imprimir_particion(solucion_inicial);

  return 0;
}


//Particion kpmp_hl(Particion& particion, Grafo& grafo, unsigned int cantidad_de_conjuntos)
//{
  
//}

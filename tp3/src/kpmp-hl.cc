#include "kpmp.cc"

using namespace std;

void kpmp_hl(Particion& particion);


int main()
{
  Entrada entrada = leer_entrada();
  Particion particion = leer_solucion(entrada.grafo, entrada.cantidad_de_conjuntos);

  kpmp_hl(particion);

  imprimir_particion(particion);

  return 0;
}


void kpmp_hl(Particion& particion)
{
  unsigned int conjunto_viejo = 0;
  unsigned int conjunto_nuevo = 0;
  unsigned int vertice_min = 0;
  double peso_min = particion.peso();
  bool se_mejoro = false;

  do {
    se_mejoro = false;
    for (unsigned int vertice = 1; vertice <= particion.cantidad_de_vertices(); vertice++) {
      unsigned int conjunto_del_vertice = particion.conjunto_del_vertice(vertice);
      double peso_sin_vertice = particion.peso() - particion.costo(conjunto_del_vertice, vertice);

      for (unsigned int conjunto = 1; conjunto <= particion.cantidad_de_conjuntos(); conjunto++) {
        double peso = peso_sin_vertice + particion.costo(conjunto, vertice);

        if (peso < peso_min) {
          peso_min = peso;
          vertice_min = vertice;
          conjunto_nuevo = conjunto;
          conjunto_viejo = conjunto_del_vertice;
        }
      }
    }

    if (peso_min < particion.peso()) {
      se_mejoro = true;
      particion.sacar_vertice(conjunto_viejo, vertice_min);
      particion.agregar_vertice(conjunto_nuevo, vertice_min);
      peso_min = particion.peso();
    }
  } while (se_mejoro);
}

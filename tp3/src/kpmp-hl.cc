#include "kpmp-hl.h"

using namespace std;


void kpmp_hl_mover_vertice(Particion& particion)
{
  unsigned int conjunto_viejo = 0;
  unsigned int conjunto_nuevo = 0;
  unsigned int vertice_min = 0;
  double peso_min = particion.peso();
  bool se_puede_mejorar = true;

  while (se_puede_mejorar) {
    for (unsigned int vertice = 1; vertice <= particion.cantidad_de_vertices(); vertice++) {
      unsigned int conjunto_del_vertice = particion.conjunto_del_vertice(vertice);
      double peso_sin_vertice = particion.peso() - particion.costo(conjunto_del_vertice, vertice);

      for (unsigned int conjunto = 1; conjunto <= particion.cantidad_de_conjuntos(); conjunto++) {
        if (conjunto == conjunto_del_vertice) {
          continue;
        }

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
      particion.sacar_vertice(conjunto_viejo, vertice_min);
      particion.agregar_vertice(conjunto_nuevo, vertice_min);
      peso_min = particion.peso();
    } else {
      se_puede_mejorar = false;
    }
  }
}


void kpmp_hl_switch_vertices(Particion& particion)
{
  unsigned int conjunto_min1 = 0;
  unsigned int conjunto_min2 = 0;
  unsigned int vertice_min1 = 0;
  unsigned int vertice_min2 = 0;
  double peso_min = particion.peso();
  bool se_puede_mejorar = true;

  while (se_puede_mejorar) {
    for (unsigned int vertice1 = 1; vertice1 <= particion.cantidad_de_vertices(); vertice1++) {
      unsigned int conjunto_del_vertice1 = particion.conjunto_del_vertice(vertice1);

      for (unsigned int vertice2 = vertice1 + 1; vertice2 <= particion.cantidad_de_vertices(); vertice2++) {
        unsigned int conjunto_del_vertice2 = particion.conjunto_del_vertice(vertice2);

        if (conjunto_del_vertice1 == conjunto_del_vertice2) {
          continue;
        }

        double peso = particion.peso()
                    - particion.costo(conjunto_del_vertice1, vertice1)
                    - particion.costo(conjunto_del_vertice2, vertice2)
                    + particion.costo(conjunto_del_vertice1, vertice2)
                    + particion.costo(conjunto_del_vertice2, vertice1);

        if (peso < peso_min) {
          peso_min = peso;
          vertice_min1 = vertice1;
          vertice_min2 = vertice2;
          conjunto_min1 = conjunto_del_vertice1;
          conjunto_min2 = conjunto_del_vertice2;
        }
      }
    }

    if (peso_min < particion.peso()) {
      particion.sacar_vertice(conjunto_min1, vertice_min1);
      particion.sacar_vertice(conjunto_min2, vertice_min2);
      particion.agregar_vertice(conjunto_min1, vertice_min2);
      particion.agregar_vertice(conjunto_min2, vertice_min1);
      peso_min = particion.peso();
    } else {
      se_puede_mejorar = false;
    }
  }
}

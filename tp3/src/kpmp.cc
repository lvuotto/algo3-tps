#include <iostream>
#include <getopt.h>
#include <vector>
#include <string.h>
#include "kpmp.h"
#include "kpmp-exacto.h"
#include "kpmp-hg.h"
#include "kpmp-hl.h"
#include "kpmp-grasp.h"

using namespace std;


int main(int argc, char **argv)
{
  if (argc == 1) {
    imprimir_uso();
    return 1;
  }

  Algortimo algoritmo = GOLOSO;
  EstrategiaVertices estrategia_vertices = MOVER;
  EstrategiaRandomizar estategia_randomizar = NADA;
  CriterioDeTerminacion criterio_de_terminacion = MEJOR_LUEGO_DE_X_VECES;
  unsigned int repeticiones = 10;

  int c;
  while (true) {
    static struct option long_options[] =
      {
        /* These options set a flag. */
        //{"verbose", no_argument,       &verbose_flag, 1},
        //{"brief",   no_argument,       &verbose_flag, 0},
        /* These options don’t set a flag.
           We distinguish them by their indices. */
        {"algoritmo",    required_argument, 0, 'a'},
        {"exacto",       no_argument,       0, 'e'},
        {"goloso",       no_argument,       0, 'g'},
        {"local",        no_argument,       0, 'l'},
        {"grasp",        no_argument,       0, 'G'},
        {"vertices",     required_argument, 0, 'v'},
        {"randomizar",   required_argument, 0, 'r'},
        {"criterio",     required_argument, 0, 'c'},
        {"repeticiones", required_argument, 0, 'R'},
        {"help",         no_argument,       0, 'h'},
        {0, 0, 0, 0}
      };
    /* getopt_long stores the option index here. */
    int option_index = 0;

    c = getopt_long(argc, argv, "a:eglGv:r:c:R:h", long_options, &option_index);

    /* Detect the end of the options. */
    if (c == -1) {
      break;
    }

    switch (c) {
      case 0:
        /* If this option set a flag, do nothing else now. */
        if (long_options[option_index].flag != 0)
          break;
        printf ("option %s", long_options[option_index].name);
        if (optarg)
          printf (" with arg %s", optarg);
        printf ("\n");
        break;

      case 'a':
        if (strcmp(optarg, "exacto") == 0) {
          algoritmo = EXACTO;
        } else if (strcmp(optarg, "goloso") == 0) {
          algoritmo = GOLOSO;
        } else if (strcmp(optarg, "local") == 0) {
          algoritmo = LOCAL;
        } else if (strcmp(optarg, "grasp") == 0) {
          algoritmo = GRASP;
        } else {
          imprimir_uso();
          return 1;
        }
        break;

      case 'e':
        algoritmo = EXACTO;
        break;

      case 'g':
        algoritmo = GOLOSO;
        break;

      case 'l':
        algoritmo = LOCAL;
        break;

      case 'G':
        algoritmo = GRASP;
        break;

      case 'h':
        imprimir_uso();
        return 0;

      case 'v':
        if (strcmp(optarg, "mover") == 0) {
          estrategia_vertices = MOVER;
        } else if (strcmp(optarg, "intercambiar") == 0) {
          estrategia_vertices = INTERCAMBIAR;
        } else {
          imprimir_uso();
          return 1;
        }
        break;

      case 'r':
        if (strcmp(optarg, "nada") == 0) {
          estategia_randomizar = NADA;
        } else if (strcmp(optarg, "aristas") == 0) {
          estategia_randomizar = ARISTAS;
        } else if (strcmp(optarg, "conjuntos") == 0) {
          estategia_randomizar = CONJUNTOS;
        } else if (strcmp(optarg, "ambos") == 0) {
          estategia_randomizar = AMBOS;
        } else {
          imprimir_uso();
          return 1;
        }
        break;

      case 'c':
        if (strcmp(optarg, "mejor_luego_de_x_veces") == 0) {
          criterio_de_terminacion = MEJOR_LUEGO_DE_X_VECES;
        } else if (strcmp(optarg, "cuando_el_mejor_se_repita_x_veces") == 0) {
          criterio_de_terminacion = CUANDO_EL_MEJOR_SE_REPITA_X_VECES;
        } else {
          imprimir_uso();
          return 1;
        }
        break;

      case 'R':
        repeticiones = atoi(optarg);
        break;

      default:
        abort();
    }
  }

  Entrada entrada = leer_entrada();

  Particion particion(entrada.grafo, entrada.cantidad_de_conjuntos);

  switch (algoritmo) {
    case EXACTO: {
      particion = kpmp_exacto(entrada.grafo, entrada.cantidad_de_conjuntos);
      break;
    }
    case GOLOSO: {
      switch (estategia_randomizar) {
        case NADA: {
          particion = kpmp_hg(entrada.grafo, entrada.cantidad_de_conjuntos);
          break;
        }
        case ARISTAS: {
          particion = kpmp_hg_random_aristas(entrada.grafo, entrada.cantidad_de_conjuntos);
          break;
        }
        case CONJUNTOS: {
          particion = kpmp_hg_random_conjuntos(entrada.grafo, entrada.cantidad_de_conjuntos);
          break;
        }
        case AMBOS: {
          particion = kpmp_hg_random_aristas_conjuntos(entrada.grafo, entrada.cantidad_de_conjuntos);
          break;
        }
      }
      break;
    }
    case LOCAL: {
      particion = leer_solucion(entrada.grafo, entrada.cantidad_de_conjuntos);

      switch (estrategia_vertices) {
        case MOVER: {
          kpmp_hl_mover_vertice(particion);
          break;
        }
        case INTERCAMBIAR: {
          kpmp_hl_switch_vertices(particion);
          break;
        }
      }
      break;
    }
    case GRASP: {
      switch (estategia_randomizar) {
        case NADA: {
          switch (estrategia_vertices) {
            case MOVER: {
              particion = kpmp_grasp(kpmp_hg, kpmp_hl_mover_vertice, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
            case INTERCAMBIAR: {
              particion = kpmp_grasp(kpmp_hg, kpmp_hl_switch_vertices, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
          }
          break;
        }
        case ARISTAS: {
          switch (estrategia_vertices) {
            case MOVER: {
              particion = kpmp_grasp(kpmp_hg_random_aristas, kpmp_hl_mover_vertice, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
            case INTERCAMBIAR: {
              particion = kpmp_grasp(kpmp_hg_random_aristas, kpmp_hl_switch_vertices, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
          }
          break;
        }
        case CONJUNTOS: {
          switch (estrategia_vertices) {
            case MOVER: {
              particion = kpmp_grasp(kpmp_hg_random_conjuntos, kpmp_hl_mover_vertice, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
            case INTERCAMBIAR: {
              particion = kpmp_grasp(kpmp_hg_random_conjuntos, kpmp_hl_switch_vertices, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
          }
          break;
        }
        case AMBOS: {
          switch (estrategia_vertices) {
            case MOVER: {
              particion = kpmp_grasp(kpmp_hg_random_aristas_conjuntos, kpmp_hl_mover_vertice, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
            case INTERCAMBIAR: {
              particion = kpmp_grasp(kpmp_hg_random_aristas_conjuntos, kpmp_hl_switch_vertices, entrada.grafo, entrada.cantidad_de_conjuntos, criterio_de_terminacion, repeticiones);
              break;
            }
          }
          break;
        }
      }
      break;
    }
  }

  imprimir_particion(particion);

  return 0;
}

Entrada::Entrada(Grafo grafo_, unsigned int cantidad_de_conjuntos_) :
  grafo(grafo_), cantidad_de_conjuntos(cantidad_de_conjuntos_)
  {}


Entrada leer_entrada()
{
  unsigned int n, m, k;
  cin >> n >> m >> k;
  Grafo grafo(n);

  for (unsigned int i = 0; i < m; i++) {
    unsigned int vertice1, vertice2;
    double peso;
    cin >> vertice1 >> vertice2 >> peso;

    grafo.agregar_arista(vertice1, vertice2, peso);
  }

  return Entrada(grafo, k);
}


Particion leer_solucion(Grafo& grafo, unsigned int cantidad_de_conjuntos)
{
  Particion particion(grafo, cantidad_de_conjuntos);
  unsigned int conjunto;

  for (unsigned int vertice = 1; vertice <= grafo.cantidad_de_vertices(); vertice++) {
    cin >> conjunto;

    particion.agregar_vertice(conjunto, vertice);
  }

  return particion;
}


void imprimir_particion(Particion& particion)
{
  vector<unsigned int> solucion = particion_a_solucion(particion);

  for (auto it = solucion.begin(); it != solucion.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
  cerr << "Peso: " << particion.peso() << endl;
}


vector<unsigned int> particion_a_solucion(Particion& particion)
{
  vector<unsigned int> solucion(particion.cantidad_de_vertices(), 0);

  for (unsigned int conjunto = 1; conjunto <= particion.cantidad_de_conjuntos(); conjunto++) {
    for (auto vertice = particion.begin(conjunto); vertice != particion.end(conjunto); vertice++) {
      solucion[*vertice - 1] = conjunto;
    }
  }

  return solucion;
}


void imprimir_uso()
{
  cout << "Uso: kpmp [OPTIONS...]" << endl << endl;

  cout << "  h, --help\t\t\t\tImprime esta ayuda" << endl;
  cout << "  a, --algoritmo=ALGORITMO\t\tUtilizar uno de estos algoritmos: exacto, goloso, local (requiere un grafo Y una solucion inicial por STDIN), grasp" << endl;
  cout << "  e, --exacto\t\t\t\tAlgoritmo exacto" << endl;
  cout << "  g, --goloso\t\t\t\tAlgoritmo goloso" << endl;
  cout << "  l, --local\t\t\t\tAlgoritmo de búsqueda local (requiere un grafo Y una solucion inicial por STDIN)" << endl;
  cout << "  G, --grasp\t\t\t\tAlgoritmo GRASP" << endl;
  cout << "  v, --vertices=ESTRATEGIA\t\tPara búsqueda local o GRASP, una de estas estrategias para determinar vecindad: mover (por defecto), intercambiar" << endl;
  cout << "  r, --randomizar=ESTRATEGIA\t\tPara goloso o GRASP, una de estas estrategias para randomizar: nada (por defecto), aristas, conjuntos, ambos" << endl;
  cout << "  c, --criterio=CRITERIO\t\tPara GRASP, uno de estos criterios de terminacion: mejor_luego_de_x_veces (por defecto), cuando_el_mejor_se_repita_x_veces" << endl;
  cout << "  R, --repeticiones=REPETICIONES\tPara GRASP, la cantidad de repeticiones segun el criterio (por defecto 10)" << endl;

  cout << endl;
  cout << "Ejemplo: kpmp -a grasp --vertices=intercambiar --randomizar=conjuntos --criterio=cuando_el_mejor_se_repita_x_veces --repeticiones=100 < grafo.txt" << endl;
  cout << "Ejecutara el algoritmo GRASP sobre el grafo descripto en grafo.txt, ";
  cout << "randomizando en la eleccion de conjuntos del goloso y determinando la vecindad intercambiando vertices." << endl;
}

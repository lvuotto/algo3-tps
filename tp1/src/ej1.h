#include <vector>


using namespace std;


vector<unsigned int> cruzar_puente(unsigned int salto_maximo,
                                   vector<unsigned int>& puente);
bool posible_cruzar(unsigned int salto_maximo, vector<unsigned int>& puente);
bool puede_saltar(vector<unsigned int>& puente, unsigned int tablon);
void imprimir_saltos(vector<unsigned int>& saltos);

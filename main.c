#include <stdio.h>
#include <stdlib.h>
#include "arbolDeListas.h"

int main() {

    nodoAdl* adl=inicAdl();
    nodoDoble* lista=inicListaDoble();
    lista=archivo2listaDoble(lista, "consumos.dat");
    nodoDoble* respuesta=inicListaDoble();
    adl=switchMenuInicial(adl, lista);



    return 0;
}




#ifndef LISTACONSUMOS_H_INCLUDED
#define LISTACONSUMOS_H_INCLUDED
#include "consumos.h"


typedef struct _nodoDoble{
    stConsumos dato;
    struct _nodoDoble* anterior;
    struct _nodoDoble* siguiente;
}nodoDoble;


///FUNCIONES BASICAS DE LISTA DOBLE
nodoDoble* inicListaDoble();
nodoDoble* crearNodoDoble(stConsumos dato);
nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevo);
nodoDoble* agregarEnOrdenPorIdCons(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevo);
nodoDoble* borrarListaDoble(nodoDoble* lista);
///VISUALIZACION
void muestraListaConsumo(nodoDoble* lista);
void muestraListaDoble(nodoDoble* lista);
void muestraUnNodoDoble(nodoDoble* nodo);
///BUSQUEDA
nodoDoble* buscaUltimoDoble(nodoDoble* lista);
nodoDoble* buscaConsumoPorId(nodoDoble* lista, int dato);
void buscaConsumoPorFecha(nodoDoble* lista);
///PASAJE DE DATOS
nodoDoble* archivo2listaDoble(nodoDoble* lista, char archivo[]);

#endif // LISTACONSUMOS_H_INCLUDED

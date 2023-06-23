#ifndef SWITCHMENU_H_INCLUDED
#define SWITCHMENU_H_INCLUDED
#include "menu.h"

nodoAdl* switchMenuInicial(nodoAdl* adl, nodoDoble* lista);
nodoAdl* switchMenuAdl(nodoAdl* adl, nodoDoble* lista);
void switchMenuVisualizacion();
void switchMenuClientes();
void switchMenuConsumos();
void switchMenuModificaClientes();
void switchMenuBusquedaClientes(nodoAdl* adl);
void switchMenuGeneraConsumos();
void switchMenuModificaConsumos();
void switchMenuBusquedaConsumo(nodoDoble* lista);




#endif // SWITCHMENU_H_INCLUDED

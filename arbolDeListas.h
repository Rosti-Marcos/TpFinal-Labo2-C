#ifndef ARBOLDELISTAS_H_INCLUDED
#define ARBOLDELISTAS_H_INCLUDED
#include "listaConsumos.h"
#include "clientes.h"


///ESTRUCTURA DE CLIENTE

typedef struct _nodoAdl{
    stClientes dato;
    nodoDoble* listaConsumo;
    struct _nodoAdl* izq;
    struct _nodoAdl* der;
}nodoAdl;



///FUNCIONES:

///INICIALIZAR,CREAR,AGREGAR
nodoAdl* inicAdl();
nodoAdl* crearNodoAdl(stClientes dato);
nodoAdl* agregarAdl(nodoAdl* adl, nodoAdl* nuevo);
nodoAdl* CargaNuevoAdl(nodoAdl* adl);
///VISUALIZACION
void preOrden(nodoAdl* adl);
void enOrden(nodoAdl* adl);
void postOrden(nodoAdl* adl);
void preOrdenPorEstado(nodoAdl* adl, int estado);
void enOrdenPorEstado(nodoAdl* adl, int estado);
void postOrdenPorEstado(nodoAdl* adl, int estado);
void muestraAdl (nodoAdl* adl);
///BUSQUEDAS
nodoAdl* buscaNodoAdlClientePorId(nodoAdl* adl, int id);
nodoAdl* buscaNodoAdlClientePorNroCliente(nodoAdl* adl, int nro);
nodoAdl* buscaNodoAdlClientePorDni(nodoAdl* adl, char dni[]);
nodoAdl* buscaNodoAdlClientePorNombreYapellido(nodoAdl* adl, char nombre[], char apellido[]);
nodoAdl* buscaNodoAdlClientePorMovil(nodoAdl* adl, char movil[]);
nodoAdl* buscaNodoAdlClientePorEmail(nodoAdl* adl, char email[]);
///BORRAR
nodoAdl* nmi (nodoAdl* adl);
nodoAdl* nmd (nodoAdl* adl);
nodoAdl* borrarNodoAdl(nodoAdl* arbol, int id);
nodoAdl* borrarAdl(adl);
///PASAJES DE DATO
nodoAdl* array2Adl (stClientes a[], int base, int tope);
nodoAdl* cargarAdlConListas(nodoAdl* adl, char archivo[]);
nodoAdl* actualizarAdl (nodoAdl* adl);
///LIQUIDACION
datosConsumidosPorPeriodo(nodoDoble* lista, int mes, int anio);
stLiquidacion liquidarPeriodo(nodoAdl* cliente, int mes, int anio);

#endif // ARBOLDELISTAS_H_INCLUDED

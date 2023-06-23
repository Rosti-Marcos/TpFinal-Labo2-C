#include <stdio.h>
#include <stdlib.h>
#include "arbolDeListas.h"
#include "string.h"
#include "switchMenu.h"

nodoAdl* inicAdl() {
    return NULL;
}

nodoAdl* crearNodoAdl(stClientes dato) {
    nodoAdl* nuevo = (nodoAdl*)malloc(sizeof(nodoAdl));
    nuevo->dato = dato;
    nuevo->listaConsumo=inicListaDoble();
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoAdl* agregarAdl(nodoAdl* adl, nodoAdl* nuevo) {
    if(adl==NULL) {
        adl = nuevo;
    } else {
        if(nuevo->dato.id < adl->dato.id) {
            adl->izq = agregarAdl(adl->izq, nuevo);
        } else {
            adl->der = agregarAdl(adl->der, nuevo);
        }
    }

    return adl;
}

///MUESTRA ADL

void muestraAdl (nodoAdl* adl) {
    char opcion=0;
    system("cls");
    printf("\n Ingrese 1 para ver sus consumos, una tecla para ver el cliente siguiente\n\n");
    if (adl) {
        muestraUnCliente(adl->dato);
        opcion=getch();

        if (opcion=='1') {
            muestraListaConsumo(adl->listaConsumo);
        }
    }

}

void preOrden(nodoAdl* adl) {
    if(adl) {
        muestraAdl(adl);
        preOrden(adl->izq);
        preOrden(adl->der);
    }
}

void enOrden(nodoAdl* adl) {
    if(adl) {
        enOrden(adl->izq);
        muestraAdl(adl);
        enOrden(adl->der);
    }
}

void postOrden(nodoAdl* adl) {
    if(adl) {
        postOrden(adl->izq);
        postOrden(adl->der);
        muestraAdl(adl);
    }
}


void preOrdenPorEstado(nodoAdl* adl, int estado) {
    if(adl) {
        if (estado==adl->dato.estado) {
            muestraAdl(adl);
            preOrdenPorEstado(adl->izq, estado);
            preOrdenPorEstado(adl->der, estado);
        }
    }
}

void enOrdenPorEstado(nodoAdl* adl, int estado) {
    if(adl) {
        enOrdenPorEstado(adl->izq, estado);
        if (estado==adl->dato.estado) {
            muestraAdl(adl);
            enOrdenPorEstado(adl->der, estado);
        }
    }
}

void postOrdenPorEstado(nodoAdl* adl, int estado) {
    if(adl) {
        postOrdenPorEstado(adl->izq, estado);
        postOrdenPorEstado(adl->der, estado);
        if (estado==adl->dato.estado) {
            muestraAdl(adl);
        }
    }
}
///BUSQUEDA CLIENTE

nodoAdl* buscaNodoAdlClientePorId(nodoAdl* adl, int id) {
    nodoAdl* respuesta = NULL;
    if(adl) {
        if(adl->dato.id == id) {
            respuesta = adl;
        } else {
            respuesta = buscaNodoAdlClientePorId(adl->izq, id);
            if(respuesta == NULL) {
                respuesta = buscaNodoAdlClientePorId(adl->der, id);
            }
        }
    }

    return respuesta;
}

nodoAdl* buscaNodoAdlClientePorNroCliente(nodoAdl* adl, int nro) {
    nodoAdl* respuesta = NULL;
    if(adl) {
        if(adl->dato.nroCliente == nro) {
            respuesta = adl;
        } else {
            respuesta = buscaNodoAdlClientePorNroCliente(adl->izq, nro);
            if(respuesta == NULL) {
                respuesta = buscaNodoAdlClientePorNroCliente(adl->der, nro);
            }
        }
    }

    return respuesta;
}

nodoAdl* buscaNodoAdlClientePorDni(nodoAdl* adl, char dni[]) {
    nodoAdl* respuesta = NULL;
    if(adl) {
        if(strcmp(adl->dato.dni,dni)==0) {
            respuesta = adl;
        } else {
            respuesta = buscaNodoAdlClientePorDni(adl->izq, dni);
            if(respuesta == NULL) {
                respuesta = buscaNodoAdlClientePorDni(adl->der, dni);
            }
        }
    }

    return respuesta;
}

nodoAdl* buscaNodoAdlClientePorNombreYapellido(nodoAdl* adl, char nombre[], char apellido[]) {
    nodoAdl* respuesta = NULL;
    if(adl) {
        if(strcmpi(adl->dato.nombre,nombre)==0 && strcmpi(adl->dato.apellido, apellido)==0) {
            respuesta = adl;
        } else {
            respuesta = buscaNodoAdlClientePorNombreYapellido(adl->izq, nombre, apellido);
            if(respuesta == NULL) {
                respuesta = buscaNodoAdlClientePorNombreYapellido(adl->der, nombre, apellido);
            }
        }
    }

    return respuesta;
}

nodoAdl* buscaNodoAdlClientePorMovil(nodoAdl* adl, char movil[]) {
    nodoAdl* respuesta = NULL;
    if(adl) {
        if(strcmp(adl->dato.movil,movil)==0) {
            respuesta = adl;
        } else {
            respuesta = buscaNodoAdlClientePorMovil(adl->izq, movil);
            if(respuesta == NULL) {
                respuesta = buscaNodoAdlClientePorMovil(adl->der, movil);
            }
        }
    }

    return respuesta;
}

nodoAdl* buscaNodoAdlClientePorEmail(nodoAdl* adl, char email[]) {
    nodoAdl* respuesta = NULL;
    if(adl) {
        if(strcmp(adl->dato.email,email)==0) {
            respuesta = adl;
        } else {
            respuesta = buscaNodoAdlClientePorEmail(adl->izq, email);
            if(respuesta == NULL) {
                respuesta = buscaNodoAdlClientePorEmail(adl->der, email);
            }
        }
    }

    return respuesta;
}



nodoAdl* nmi (nodoAdl* adl) {
    if (adl-> der != NULL) {
        adl = nmi(adl -> der);
    }
    return adl;
}

nodoAdl* nmd (nodoAdl* adl) {
    if (adl->izq !=NULL) {
        adl= nmd(adl->izq);
    }
    return adl;
}

nodoAdl* borrarNodoAdl(nodoAdl* adl, int id) {
    if (adl!=NULL) {
        if (id==adl->dato.id) {
            if (adl->izq != NULL) {
                nodoAdl * masDer = nmd(adl->izq);
                adl->dato = masDer->dato;
                adl->izq = borrarNodoAdl(adl->izq, masDer->dato.id);
            } else if (adl->der != NULL) {
                nodoAdl * masIzq =nmi(adl->der);
                adl->dato=masIzq->dato;
                adl->der= borrarNodoAdl(adl->der, masIzq->dato.id);
            } else {
                adl->listaConsumo=borrarListaDoble(adl->listaConsumo);
                free(adl);
                adl = NULL;
            }
        } else if (id > adl->dato.id) {
            adl->der = borrarNodoAdl(adl->der, id);
        } else {
            adl ->izq = borrarNodoAdl(adl->izq, id);
        }

    } else {
        printf("\n El id del Cliente a buscar no existe");
    }
    return adl;
}

nodoAdl* borrarAdl (nodoAdl* adl) {
    if(adl) {
        borrarAdl(adl->izq);
        borrarAdl(adl->der);
        borrarListaDoble(adl->listaConsumo);
        free(adl);
        adl=NULL;
    }
    return adl;
}


nodoAdl* array2Adl (stClientes a[], int base, int tope) {
    int medio;
    int i=0;
    nodoAdl* adl=NULL;
    if(!(base>tope)) {
        medio=(base+tope)/2;
        adl=crearNodoAdl(a[medio]);
        adl->izq=array2Adl(a,base,medio-1);
        adl->der=array2Adl(a,medio+1,tope);
    }
    return adl;
}




nodoAdl* cargarAdlConListas(nodoAdl* adl, char archivo[]) {
    FILE *parchiConsumos = fopen(archivo, "rb");
    stConsumos cons;
    nodoAdl* aux = NULL;
    int i = 0;
    if(parchiConsumos) {
        while(fread(&cons, sizeof(stConsumos), 1, parchiConsumos)>0) {
            aux = buscaNodoAdlClientePorId(adl, cons.idCliente);
            aux->listaConsumo = agregarAlFinalDoble(aux->listaConsumo, crearNodoDoble(cons));
        }

    }
    fclose(parchiConsumos);

    return adl;

}

nodoAdl* cargaNuevoAdl(nodoAdl* adl) {
    stClientes *clientes;
    int validos=archivo2array(&clientes, "clientes.dat");
    adl=array2Adl(clientes, 0, validos-1);
    adl=cargarAdlConListas(adl,"consumos.dat");

    return adl;
}

nodoAdl* actualizarAdl (nodoAdl* adl) {
    adl=borrarAdl(adl);
    adl=cargaNuevoAdl(adl);
    return adl;
}

int datosConsumidosPorPeriodo(nodoDoble* lista, int mes, int anio) {
    nodoDoble* seg = lista;
    int datos =0;
    while(seg) {
        if(seg->dato.mes==mes && seg->dato.anio==anio) {
            datos = datos + seg->dato.datosConsumidos;
        }
        seg = seg->siguiente;

    }
    return datos;
}



stLiquidacion liquidarPeriodo(nodoAdl* cliente, int mes, int anio) {
    stLiquidacion liquidacion;
    static int factura=0;
    factura++;
    if(cliente) {
        strcpy(liquidacion.nombre, cliente->dato.nombre);
        strcpy(liquidacion.apellido, cliente->dato.apellido);
        liquidacion.idCliente = cliente->dato.id;
        liquidacion.periodo.mes = mes;
        liquidacion.periodo.anio = anio;
        liquidacion.datosConsumidos = datosConsumidosPorPeriodo(cliente->listaConsumo, mes, anio);
        liquidacion.factura=factura;
    }
    return liquidacion;
}

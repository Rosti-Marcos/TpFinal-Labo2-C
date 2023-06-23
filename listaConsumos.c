#include <stdlib.h>
#include <stdio.h>
#include "listaConsumos.h"


nodoDoble* inicListaDoble() {
    return NULL;
}

nodoDoble* crearNodoDoble(stConsumos dato) {
    nodoDoble* nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato = dato;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevo) {
    nuevo->siguiente = lista;
    if(lista) {
        lista->anterior = nuevo;
    }

    return nuevo;
}

nodoDoble* agregarAlFinalDoble(nodoDoble* lista, nodoDoble* nuevo) {
    if(lista == NULL) {
        lista = nuevo;
    } else {
        nodoDoble* ultimo = buscaUltimoDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }

    return lista;
}



nodoDoble* agregarEnOrdenPorIdCons(nodoDoble* lista, nodoDoble* nuevoNodo) {
    if(!lista) {
        lista=nuevoNodo;
    } else {
        if(nuevoNodo->dato.id < lista->dato.id) {
            lista = agregarAlPrincipioDoble(lista, nuevoNodo);
        } else {
            nodoDoble* anterior = lista->anterior;
            nodoDoble* seg = lista->siguiente;
            while(seg != NULL && nuevoNodo->dato.id > seg->dato.id) {
                anterior = seg->anterior;
                seg = seg->siguiente;
            }
            anterior->siguiente = nuevoNodo;
            nuevoNodo->siguiente = seg;
        }
    }

    return lista;
}

void muestraListaDoble(nodoDoble* lista) {
    nodoDoble* seg = lista;
    while(seg) {
        muestraUnNodoDoble(seg);
        seg = seg->siguiente;
    }
}

void muestraUnNodoDoble(nodoDoble* nodo) {
    muestraUnConsumo(nodo->dato);
}


void muestraListaConsumo(nodoDoble* lista) {
    char opcion=0;
    nodoDoble* seg=inicListaDoble();
    seg=lista;
    system("cls");
    printf("\n Lista de consumos\n");
    printf("\n apriente la tecla A para ver el anterior, o S para ver el siguiente\n");

    if (seg) {
        muestraUnConsumo(seg->dato);
        opcion=getch();

        if(opcion=='a') {
            if(seg->anterior!= NULL) {
                muestraListaConsumo(seg->anterior);
            } else {
                printf("\n\n\n\n no existen datos anteriores\n");
                system("pause");
                muestraListaConsumo(seg);
            }
        } else {
            if (opcion=='s') {
                if(seg->siguiente!= NULL) {
                    muestraListaConsumo(seg->siguiente);
                } else {
                    printf("\n\n\n\n No existen datos siguientes\n");
                    system("pause");
                    muestraListaConsumo(seg);

                }
            }
        }
    }
}

void muestraListaConsPorEstado(nodoDoble* lista, int estado) {
    nodoDoble* seg=lista;
    while(seg->siguiente) {
        if (estado==seg->dato.estado) {
            muestraUnConsumo(seg->dato);
        }
        seg=seg->siguiente;
    }
}

nodoDoble* buscaUltimoDoble(nodoDoble* lista) {
    nodoDoble* seg = lista;
    if(seg) {
        while(seg->siguiente!=NULL) {
            seg=seg->siguiente;
        }
    }
    return seg;
}

nodoDoble* buscaConsumoPorId(nodoDoble* lista, int dato) {
    nodoDoble* seg = lista;
    nodoDoble* respuesta=inicListaDoble();
    while(seg!=NULL) {
        if (seg->dato.id == dato) {
            respuesta=agregarAlFinalDoble(respuesta, crearNodoDoble(seg->dato));
        }
        seg = seg->siguiente;
    }
    return respuesta;
}

void buscaConsumoPorFecha(nodoDoble* lista) {
    nodoDoble* seg = lista;
    stConsumos fecha;
    fecha=busquedaFecha(&fecha);
    while(seg!=NULL) {
        if(seg->dato.anio==fecha.anio && seg->dato.mes==fecha.mes && seg->dato.dia==fecha.dia) {
            muestraUnNodoDoble(seg);
        }
        seg = seg->siguiente;
    }
    system("pause");
}


nodoDoble* archivo2listaDoble(nodoDoble* lista, char archivo[]) {
    FILE *archi = fopen(archivo, "rb");
    stConsumos e;
    if(archi) {
        while(fread(&e, sizeof(stConsumos), 1, archi)>0) {
            lista = agregarAlFinalDoble(lista, crearNodoDoble(e));
        }
        fclose(archi);
    }

    return lista;
}

nodoDoble* borrarListaDoble(nodoDoble* lista) {
    nodoDoble* proximo=NULL;
    nodoDoble* seg=NULL;

    seg = lista;
    while(seg) {
        proximo = seg->siguiente;
        free(seg);
        seg=proximo;
    }
    return seg;
}



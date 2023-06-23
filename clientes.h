#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "cliente.h"
#include <string.h>

///CARGA CLIENTE NUEVO
void nuevoCliente (char archivo[]);
///VALIDACIONES
int validaEmail(stClientes cliente);
int validaEmailChar(char eMailNew []);
int CompruebaNumCliente (int numCliente);
int cuentaRegistros(char archivo[], int tamanioSt);
void buscaRegistroEmail (char archivo [], char email []);
///MODIFICACIONES
void modificaEmail(char archivo[], char eMailNew [], char eMailActual []);
void modificaMovil(char archivo[], char movilNew [], char movilActual []);
void modificaDni(char archivo[], char dniNew [], char dniActual []);
void modificaEstado(char archivo[], int nroCliente);
///PASAJE DE DATO
int archivo2array(stClientes **arrayClientes, char archivo[]);

#endif // CLIENTES_H_INCLUDED

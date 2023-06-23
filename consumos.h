#ifndef CONSUMOS_H_INCLUDED
#define CONSUMOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "consumo.h"
#include "cliente.h"


///CARGA CONSUMO NUEVO
void nuevoConsumo (char archivo[]);
///CARGA CONSUMO RANDOM
void cargaNuevoConsumo (char archivo[], stConsumos nuevo);
int cargaDatosConsumidos (char archivo[],stConsumos nuevo);
void cargaConsumoAleatorio (char archivo []);
stConsumos busquedaFecha();
///VALIDACIONES
int compruebaIdCliente(int idCliente);
int cargaMes(stConsumos con, int dato);
int cargaDia (stConsumos con, int mes[], int dato, int dato2);
int cargaAnio(stConsumos con, int mes[]);
int anioActual();
int mesActual();
int diaActual();
///MODIFICACIONES
void modificaCons(char archivo[], int idCarga, int consNew);
void modificaEstadoCons(char archivo[], int idcarga);
void modificaFecha(char archivo[], int dato);



#endif // CONSUMOS_H_INCLUDED

#ifndef CONSUMO_H_INCLUDED
#define CONSUMO_H_INCLUDED

typedef struct {
    int id;
    int idCliente;
    int anio;
    int mes;
    int dia;
    int datosConsumidos;
    int estado;
} stConsumos;

typedef struct {
    int mes;
    int anio;
} stPeriodo;


typedef struct {
    int factura;
    int idCliente;
    char apellido[30];
    char nombre[30];
    stPeriodo periodo;
    int datosConsumidos;
} stLiquidacion;



void muestraUnConsumo (stConsumos con);
void muestraLiquidacion (stLiquidacion liquidacion);

#endif // CONSUMO_H_INCLUDED

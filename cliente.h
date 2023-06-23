#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct {
    int id;
    int nroCliente;
    char nombre[30];
    char apellido [30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char movil[12];
    int estado;
} stClientes;


void muestraUnCliente (stClientes cliente);


#endif // CLIENTE_H_INCLUDED

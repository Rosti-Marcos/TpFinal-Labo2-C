#include "cliente.h"


void muestraUnCliente (stClientes cliente) {

    printf("\n Id........................: %d", cliente.id);
    printf("\n Nro de Cliente............: %d", cliente.nroCliente);
    printf("\n Nombre....................: %s", cliente.nombre);
    printf("\n Apellido..................: %s", cliente.apellido);
    printf("\n DNI.......................: %s", cliente.dni);
    printf("\n Email.....................: %s", cliente.email);
    printf("\n Domicilio.................: %s", cliente.domicilio);
    printf("\n Movil.....................: %s", cliente.movil);
    printf("\n Situacion del cliente.....: %d", cliente.estado);
    printf("\n-------------------------------------------------------");
}


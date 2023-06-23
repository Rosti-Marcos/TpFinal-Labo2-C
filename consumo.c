#include "consumo.h"



void muestraUnConsumo (stConsumos con) {

    printf("\n Id........................: %d", con.id);
    printf("\n Id de Cliente.............: %d", con.idCliente);
    printf("\n A%co......................: %d",164, con.anio);
    printf("\n Mes.......................: %d", con.mes);
    printf("\n Dia.......................: %d", con.dia);
    printf("\n Datos consumidos..........: %d MB", con.datosConsumidos);
    printf("\n Estado....................: %d", con.estado);///0 para inactivo, 1 para activo
    printf("\n-------------------------------------------------------");

}


void muestraLiquidacion(stLiquidacion liquidacion) {
    printf("\n\n-------------------------------------------------------");
    printf("\n NUMERO DE FACTURA.........: 000%d",liquidacion.factura);
    printf("\n\n Id de Cliente.............: %d", liquidacion.idCliente);
    printf("\n Apellido..................: %s", liquidacion.apellido);
    printf("\n Nombre....................: %s", liquidacion.nombre);
    printf("\n Mes y a%co de Facturacion..: %d/%d",164, liquidacion.periodo.mes, liquidacion.periodo.anio);
    printf("\n Valor de los 100 MB ......: $43");
    printf("\n Costo de servicio.. ......: $124.89");
    printf("\n\n Total de datos consumidos.: %d MB", liquidacion.datosConsumidos);
    printf("\n\n SUBTOTAL..................: $%0.2f", liquidacion.datosConsumidos*0.43);
    printf("\n\n TOTAL A ABONAR............: $%0.2f", liquidacion.datosConsumidos*0.43+124.89);
    printf("\n-------------------------------------------------------");

}


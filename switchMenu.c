#include "switchMenu.h"


nodoAdl* switchMenuInicial(nodoAdl* adl, nodoDoble* lista) {

    char opcion=0;
    do {
        opcion=menuInicial();

        switch(opcion) {
        case '1':
            /// CLIENTES
            switchMenuClientes();
            break;
        case '2':
            /// CONSUMOS
            switchMenuConsumos();
            break;
        case '3':
            ///ARBOL DE CLIENTES CON LISTAS DE CONSUMOS
            switchMenuAdl(adl, lista);
            break;
        }

    } while (opcion!=27);
    return adl;
}

nodoAdl* switchMenuAdl(nodoAdl* adl, nodoDoble* lista) {
    int idCliente=0;
    char nombre[30];
    char apellido[30];
    char opcion=0;
    do {
        opcion=menuAdl();
        switch(opcion) {
        case '1':
            ///CARGA NUEVO ADL
            if(adl) {
                printf("\n El ADL ya esta cargado\n");
                system("pause");
            } else {
                adl=cargaNuevoAdl(adl);
            }
            break;
        case '2':
            ///VISUALIZACION
            if (adl) {
                switchMenuVisualizacion(adl);
            } else {
                printf("\n el ADL esta vacio\n");
                system("pause");
            }
            break;
        case '3':
            ///BUSQUEDAS CLIENTE
            if (adl) {
                switchMenuBusquedaClientes(adl);
            } else {
                printf("\n No existen datos que buscar\n");
                system("pause");
            }
            break;
        case '4':
            ///BUSQUEDA CONSUMO
            system("cls");
            buscaConsumoPorFecha(lista);
            break;
        case '5':
            ///ELIMINA NODO ADL
            printf("Ingrese el ID del cliente a borrar:  ");
            fflush(stdin);
            scanf("%d",&idCliente);
            adl=borrarNodoAdl(adl, idCliente );
            break;
        case '6':
            ///TODO EL ADL
            adl=borrarAdl(adl);
            break;
        case '7':
            ///ACTUALIZA ADL
            adl=actualizarAdl(adl);
            break;
        case '8':
            ///LIQUIDACION

            printf("\n Ingrese nombre del cliente: ");
            fflush(stdin);
            scanf("%s",&nombre);
            printf("\n Ingrese apellido del cliente: ");
            fflush(stdin);
            scanf("%s",&apellido);
            nodoAdl* respuesta=inicAdl();
            respuesta=buscaNodoAdlClientePorNombreYapellido(adl, nombre, apellido);
            if (respuesta) {
                printf("\n Ingrese el mes a facturar: ");
                int mes=0;
                scanf("%d",&mes);
                printf("\n Ingrese el a%co a facturar: ",164);
                int anio=0;
                scanf("%d",&anio);
                system("cls");
                stLiquidacion liquidacion=liquidarPeriodo(respuesta, mes, anio);
                if (liquidacion.datosConsumidos==0) {
                    printf("\n No se encontraron datos consumidos durante ese periodo\n");

                } else {
                    muestraLiquidacion(liquidacion);
                }
            } else {
                printf("\n El cliente no existe");
            }
            printf("\n\n\n\n");
            system("pause");
            break;
        }
    } while (opcion!=27);
    return adl;
}

void switchMenuVisualizacion(nodoAdl* adl) {
    char opcion=0;
    do {
        opcion=menuVisualizacion();
        switch(opcion) {
        case '1':
            ///PRE ORDEN
            preOrden(adl);
            break;
        case '2':
            ///EN ORDEN
            enOrden(adl);
            break;
        case '3':
            ///POST ORDEN
            postOrden(adl);
            break;
        }
    } while (opcion!=27);

}

void switchMenuClientes() {
    char opcion=0;
    do {
        opcion=menuClientes();
        switch(opcion) {
        case '1':
            nuevoCliente("clientes.dat");
            break;
        case '2':
            switchMenuModificaClientes();
            break;
        }
    } while (opcion!=27);
}

void switchMenuConsumos() {
    char opcion=0;
    do {
        opcion=menuConsumos();
        switch(opcion) {
        case '1':
            switchMenuGeneraConsumos();
            break;
        case '2':
            switchMenuModificaConsumos();
            break;
        }
    } while (opcion!=27);
}


void switchMenuModificaClientes() {

    int emailValido=0;
    char eMailActual [30];
    char eMailNew [30];
    char movilActual [30];
    char movilNew [30];
    char dniActual [30];
    char dniNew [30];
    int confirmacion=0;
    int idCarga=0;
    int consNew=0;
    int idCliente=0;
    int nroCliente=0;
    char opcion=0;


    do {
        opcion=menuModificaClientes();
        switch(opcion) {
        case '1':
            ///MODIFICA EMAIL
            printf("Ingrese Email actual:  ");
            gets(&eMailActual);
            buscaRegistroEmail("clientes.dat", eMailActual);
            do {
                printf("\n\n Ingrese nuevo Email:  ");
                gets(&eMailNew);
                emailValido=validaEmailChar(eMailNew);
                if(emailValido==0) {
                    printf("Email ingresado no es valido, Reingrese:  ");
                }
            } while (emailValido==0);
            modificaEmail("clientes.dat", eMailNew, eMailActual);
            printf("\nEl Email ha sido reemplazado con exito!");
            system("pause");

            break;

        case '2':

            ///MODIFICA MOVIL
            printf("Ingrese Nro de movil actual:  ");
            gets(&movilActual);
            buscaRegistroMovil("clientes.dat", movilActual);
            printf("\n\n Ingrese nuevo Nro de movil:  ");
            gets(&movilNew);
            modificaMovil("clientes.dat", movilNew, movilActual);
            printf("\nEl Nro de movil ha sido reemplazado con exito!");
            system("pause");
            break;

        case '3':
            ///MODIFICA DNI
            printf("Ingrese DNI actual:  ");
            gets(&dniActual);
            buscaRegistroDni("clientes.dat", dniActual);
            printf("\n\n Ingrese nuevo DNI:  ");
            gets(&dniNew);
            modificaDni("clientes.dat", dniNew, dniActual);
            printf("\nEl DNI ha sido reemplazado con exito!");
            system("pause");
            break;

        case '4':
            ///MODIFICA ESTADO
            printf("Ingrese Nro de cliente:  ");
            scanf("%d",&nroCliente);
            buscaRegistroNroCliente("clientes.dat", nroCliente);
            printf("\n\n Seguro desea modificar???? 1 (si) / 2 (no)");
            scanf("%d", &confirmacion);
            if (confirmacion==1) {
                modificaEstado("clientes.dat", nroCliente);
                printf("\n\n\nEl estado del cliente ha sido reemplazado con exito!\n\n\n");
            } else {
                printf("\n\n La modificacion se ha cancelado\n\n");
            }
            system("pause");
            break;
        }
    } while (opcion!=27);
}



void switchMenuBusquedaClientes(nodoAdl* adl) {
    nodoAdl* respuesta=inicAdl();
    int nroCliente=0;
    char nroMovil[10];
    char dni[10];
    char nombre[30];
    char apellido[30];
    char eMail[30];
    char opcion=0;
    do {
        opcion=menuBuscaClientes();
        switch(opcion) {
        case '1':
            ///BUSQUEDA POR NRO DE CLIENTE
            printf("\t\t\n Ingrese Nro de Cliente a buscar: ");
            scanf("%d",&nroCliente);
            respuesta=buscaNodoAdlClientePorNroCliente(adl, nroCliente);
            if (respuesta) {
                muestraAdl(respuesta);
                system("pause");
            } else {
                printf("\n El cliente no existe\n");
                system("pause");
            }
            break;
        case '2':
            ///BUSQUEDA POR DNI
            printf("\t\t\n Ingrese DNI a buscar: ");
            fflush(stdin);
            scanf("%s",&dni);
            respuesta=buscaNodoAdlClientePorDni(adl, dni);
            if (respuesta) {
                muestraAdl(respuesta);
                printf("\n");
                system("pause");
            } else {
                printf("\n El cliente no existe\n");
                system("pause");
            }
            break;
        case '3':
            ///BUSQUEDA POR MOVIL
            printf("\t\t\n Ingrese Nro de movil a buscar: ");
            fflush(stdin);
            scanf("%s",&nroMovil);
            respuesta=buscaNodoAdlClientePorMovil(adl, nroMovil);
            if (respuesta) {
                muestraAdl(respuesta);
                printf("\n");
                system("pause");
            } else {
                printf("\n El cliente no existe\n");
                system("pause");
            }
            break;
        case '4':
            ///BUSQUEDA POR EMAIL
            printf("\t\t\n Ingrese Email a buscar: ");
            fflush(stdin);
            scanf("%s",&eMail);
            respuesta=buscaNodoAdlClientePorEmail(adl, eMail);
            if (respuesta) {
                muestraAdl(respuesta);
                printf("\n");
                system("pause");
            } else {
                printf("\n El cliente no existe\n");
                system("pause");
            }
            break;
        case '5':
            ///BUSQUEDA POR NOMBRE Y APELLIDO
            printf("\t\t\n Ingrese nombre a buscar: ");
            fflush(stdin);
            scanf("%s",&nombre);
            printf("\t\t\n Ingrese apellido a buscar: ");
            fflush(stdin);
            scanf("%s",&apellido);
            respuesta=buscaNodoAdlClientePorNombreYapellido(adl, nombre, apellido);
            if(respuesta) {
                muestraAdl(respuesta);
                printf("\n");
                system("pause");
            } else {
                printf("\n El cliente no existe\n");
                system("pause");
            }
            break;
        }

    } while (opcion!=27);
}

void switchMenuGeneraConsumos() {
    char opcion=0;

    do {
        opcion=menuGeneraConsumos();
        switch(opcion) {
        case '1':
            ///CARGA MANUAL
            nuevoConsumo("consumos.dat");

            system("pause");
            break;
        case '2':
            ///CARGA RANDOM
            cargaConsumoAleatorio("consumos.dat");
            system("pause");
            break;
        }
    } while(opcion!=27);
}

void switchMenuModificaConsumos() {
    char opcion=0;
    int idCarga=0;
    int confirmacion=0;
    int consNew=0;

    do {
        opcion=menuModificaCons();
        switch(opcion) {
        case '1':
            ///MODIFICA ESTADO
            printf("Ingrese ID de consumo:  ");
            scanf("%d",&idCarga);
            buscaConsumoPorId("consumos.dat", idCarga);
            printf("\n\n Seguro desea modificar???? 1 (si) / 2 (no)");
            scanf("%d", &confirmacion);
            if (confirmacion==1) {
                modificaEstadoCons("consumos.dat", idCarga);
                printf("\n\n\nEl estado del consumo ha sido reemplazado con exito!\n\n\n");
            } else {
                printf("\n\n La modificacion se ha cancelado\n\n");
            }
            system("pause");
            break;
        case '2':
            ///MODIFICA FECHA
            idCarga=0;
            printf("Ingrese ID del consumo a modificar:  ");
            scanf("%d", &idCarga);
            buscaConsumoPorId("consumos.dat", idCarga);
            modificaFecha("consumos.dat", idCarga);
            printf("\nLa fecha ha sido modificada con exito!");
            system("pause");
            break;

        case '3':
            ///MODIFICA DATOS CONSUMIDOS
            printf("Ingrese ID del consumo a modificar:  ");
            scanf("%d", &idCarga);
            buscaConsumoPorId("consumos.dat", idCarga);
            printf("\n\n Ingrese nuevo consumo:  ");
            scanf("%d", &consNew);
            modificaCons("consumos.dat", idCarga, consNew);
            printf("\nEl consumo ha sido reemplazado con exito!");
            system("pause");
            break;

            break;
        }
    } while(opcion!=27);
}




#include "menu.h"

char menuInicial() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t BIENVENIDOS AL SISTEMA\n\n");
    printf("\n 1 - CLIENTES");
    printf("\n 2 - CONSUMOS");
    printf("\n 3 - ADL");
    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}

char menuAdl() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t ADL\n\n");
    printf("\n 1 - Carga nuevo ADL");
    printf("\n 2 - Visualizacion");
    printf("\n 3 - Busca cliente");
    printf("\n 4 - Busca consumo");
    printf("\n 5 - Elimina un cliente y sus consumos");
    printf("\n 6 - Borrar ADL");
    printf("\n 7 - Actualiza ADL");
    printf("\n 8 - Liquidacion");

    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}

char menuVisualizacion() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t VISUALIZA ADL\n\n");
    printf("\n 1 - Pre Orden");
    printf("\n 2 - En Orden");
    printf("\n 3 - Post Orden");

    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}


char menuClientes() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t CLIENTES\n\n");
    printf("\n 1 - Alta cliente nuevo");
    printf("\n 2 - Modifica Cliente");

    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}

char menuConsumos() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t CONSUMOS\n\n");
    printf("\n 1 - Alta de consumo nuevo");
    printf("\n 2 - Modifica Consumo");

    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}

char menuModificaClientes() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t MODIFICACIONES\n\n");
    printf("\n 1 - Modifica Email");
    printf("\n 2 - Modifica Nro de movil");
    printf("\n 3 - Modifica DNI");
    printf("\n 4 - Baja de cliente");

    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}

char menuBuscaClientes() {
    char opcion=0;

    system("cls");
    system("color 3F");
    printf("\n\t\t\t BUSQUEDA CLIENTE\n\n");
    printf("\n 1 - Busqueda por numero de cliente");
    printf("\n 2 - Busqueda por DNI");
    printf("\n 3 - Busqueda por movil");
    printf("\n 4 - Busqueda por e-mail");
    printf("\n 5 - Busqueda por nombre y apellido");

    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}
char menuGeneraConsumos() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t CARGA DE CONSUMOS\n\n");
    printf("\n 1 - Carga manual");
    printf("\n 2 - Carga random");
    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}

char menuModificaCons() {
    char opcion=0;


    system("cls");
    system("color 3F");
    printf("\n\t\t\t MODIFICACIONES!!!\n\n");
    printf("\n 1 - Baja de consumo");
    printf("\n 2 - Modifica fecha");
    printf("\n 3 - Modifica datos consumidos");

    printf("\n\n ESC para salir");
    printf("\n Elija una opcion\n\n");

    opcion=getch();

    return opcion;
}




#include <stdio.h>
#include <stdlib.h>
#include "consumos.h"

void nuevoConsumo (char archivo[]) {
    int mes[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int validacionId=0;
    int flag=0;
    char opcion=0;
    int id = cuentaRegistros("consumos.dat", sizeof(stConsumos));
    stConsumos con;
    do {
        validacionId=0;
        while(validacionId==0) {

            printf("\n Ingrese Id de Cliente................: ");
            scanf("%d", &con.idCliente);
            validacionId=compruebaIdCliente(con.idCliente);
            if(validacionId==0) {
                printf("El cliente no existe\n");
                system("pause");
                system("cls");
            }
        }
        con.anio=cargaAnio(con, mes);
        con.mes=cargaMes(con,con.anio);
        con.dia=cargaDia(con, mes, con.mes,con.anio);
        printf("\n Datos consumidos...........: ");
        scanf("%d", &con.datosConsumidos);
        flag=cargaDatosConsumidos("consumos.dat", con);
        con.estado=0;
        if (flag==1) {
            id++;
            con.id=id;
            cargaNuevoConsumo("consumos.dat", con);
        }
        printf("\n ESC para salir, otra para continuar...");
        opcion=getch();
        system("cls");

    } while(opcion!=27);

}

void cargaNuevoConsumo (char archivo[], stConsumos nuevo) {
    FILE *pArchi = fopen(archivo, "a+b");
    if(pArchi) {
        fwrite(&nuevo, sizeof(stConsumos),1, pArchi);
        fclose(pArchi);
    }
}

int cargaDatosConsumidos (char archivo[],stConsumos nuevo) {
    stConsumos viejo;
    int flag=1;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==1 && fread(&viejo, sizeof(stConsumos), 1, pArchi)>0) {

            if (viejo.idCliente== nuevo.idCliente && viejo.anio==nuevo.anio && viejo.mes==nuevo.mes && viejo.dia==nuevo.dia) {
                viejo.datosConsumidos=viejo.datosConsumidos+nuevo.datosConsumidos;
                fseek(pArchi,-1*sizeof(stConsumos), SEEK_CUR);
                fwrite(&viejo, sizeof(stConsumos),1, pArchi);
                flag=-1;
            }
        }
        fclose(pArchi);
    }
    return flag;
}

stConsumos busquedaFecha() {

    stConsumos fecha;

    printf("\n ingrese el a%co\n", 164);
    scanf("\n %d", &fecha.anio);
    printf("\n ingrese el mes\n");
    scanf("\n %d", &fecha.mes);
    printf("\n ingrese un dia\n");
    scanf("\n %d", &fecha.dia);
    system("cls");
    return fecha;
}

int compruebaIdCliente(int idCliente) {
    int flag=0;
    stClientes c;
    stConsumos con;
    FILE *archi= fopen("clientes.dat", "rb");
    if (archi) {
        while(fread(&c, sizeof(stClientes), 1, archi)>0 && flag==0) {
            if(c.id==idCliente) {
                con.idCliente=idCliente;
                flag=1;
                if(c.estado==1) {
                    flag=0;
                }
            }
        }
        fclose(archi);
    }
    return flag;
}

int cargaMes(stConsumos con, int dato) {
    int flag=0;
    int mesHoy=mesActual();
    int anioHoy=anioActual();
    while (flag==0) {
        printf("\n Ingrese el mes.......................: ");
        scanf("%d", &con.mes);
        if (con.mes>=1 && con.mes <=12) {
            flag=1;
            if (dato==anioHoy) {
                if (con.mes<= mesHoy) {
                } else {
                    printf("\n Usted ingreso un mes mayor al vigente\n\n");
                    system("pause");
                    system("cls");
                    flag=0;
                }
            }
            if (dato!=anioHoy) {
                flag=1;
            }

        } else {
            printf(" El mes ingresado no es valido\n\n");
            system("pause");
            system("cls");
        }
    }
    return con.mes;
}

int cargaDia (stConsumos con, int mes[], int dato, int dato2) {
    int i=dato;
    int mesHoy=mesActual();
    int anioHoy=anioActual();
    int diaHoy=diaActual();
    int flag=0;

    while(flag==0) {
        printf("\n Dia.......................: ");
        scanf("%d", &con.dia);
        if (con.dia <= mes[i-1] && con.dia>0) {
            flag=1;
            if (dato2==anioHoy && dato==mesHoy) {
                if (con.dia <=diaHoy) {
                } else {
                    printf("\n Usted ingreso un dia mayor al vigente\n\n");
                    system("pause");
                    system("cls");
                    flag=0;
                }

            }
            if (dato2!=anioHoy) {
                flag=1;
            }
        } else {
            printf("\n Usted ingreso un numero mayor a lo que trae el mes.\n\n");
            system("pause");
            system("cls");
        }
    }
    return con.dia;
}

int cargaAnio(stConsumos con, int mes[]) {
    int flag=0;
    int anioHoy=anioActual();
    while(flag==0) {
        printf("\n Ingrese el a%co: \n", 164);
        scanf("%d",&con.anio);
        if(con.anio<=anioHoy && con.anio>1900) {
            flag=1;
        } else {
            printf("El a%co ingresado no es valido.\n", 164);
            system("pause");
            system("cls");
        }
        if(con.anio%4==0 && con.anio % 100 != 0 || con.anio % 400 == 0) {
            mes[1]=29;
        }
    }
    return con.anio;
}

int anioActual() {
    time_t ahora = time(NULL);
    struct tm* ahoralocal = localtime(&ahora);
    return ahoralocal->tm_year+1900;
}

int mesActual() {
    time_t ahora = time(NULL);
    struct tm* ahoralocal = localtime(&ahora);
    return ahoralocal->tm_mon +1;
}

int diaActual() {
    time_t ahora = time(NULL);
    struct tm* ahoralocal = localtime(&ahora);
    return ahoralocal->tm_mday;
}


void modificaCons(char archivo[], int idCarga, int consNew) {
    stConsumos con;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&con, sizeof(stConsumos), 1, pArchi)>0) {
            if(con.id==idCarga) {
                con.datosConsumidos=consNew;
                pos=ftell(pArchi)-sizeof(stConsumos);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&con, sizeof(stConsumos), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

void modificaEstadoCons(char archivo[], int idcarga) {
    stConsumos con;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&con, sizeof(stConsumos), 1, pArchi)>0) {
            if(con.id==idcarga) {
                if(con.estado==1) {
                    con.estado=0;
                } else {
                    con.estado=1;
                }
                pos=ftell(pArchi)-sizeof(stConsumos);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&con, sizeof(stConsumos), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

void modificaFecha(char archivo[], int dato) {
    stConsumos c;
    int mes[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int anioHoy=anioActual();
    int mesHoy=mesActual();
    int diaHoy=diaActual();
    int flag=0;
    FILE *pArchi = fopen(archivo, "r+b");

    if(pArchi) {
        while(flag ==0 && fread(&c, sizeof(stConsumos), 1, pArchi)>0) {
            if(c.id==dato) {
                c.anio=cargaAnio(c, mes);
                c.mes=cargaMes(c, c.anio);
                c.dia=cargaDia(c, mes, c.mes, c.anio);
                fseek(pArchi,-1 * sizeof (stConsumos),SEEK_CUR);
                fwrite(&c, sizeof(stConsumos), 1, pArchi);
                //fseek(pArchi, sizeof (stConsumos),1,SEEK_CUR);
                flag=1;
            }
        }
        fclose(pArchi);
    }
}



void cargaConsumoAleatorio (char archivo []) {
    int cliente=cuentaRegistros("clientes.dat", sizeof(stClientes));
    int diasDelMes=0;
    int id=cuentaRegistros("consumos.dat",sizeof(stConsumos));
    int mes[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int anioHoy=anioActual();
    int mesHoy=mesActual();
    int diaHoy=diaActual();
    stConsumos con;
    int idCliente=1;
    int flag=0;
    do {
        for( int i=0; i<10; i++) {
            con.idCliente=rand()%(50)+1;
            con.anio=anioHoy;
            con.mes=rand()%(mesHoy)+1;
            diasDelMes=mes[con.mes];
            if (con.mes==mesHoy) {
                con.dia=rand()%(diaHoy)+1;
            } else {
                con.dia=rand()%(diasDelMes)+1;
            }
            con.datosConsumidos=rand()%(1000)+100;
            flag=cargaDatosConsumidos("consumos.dat", con);

            if (flag==1) {
                con.estado=0;
                id++;
                con.id=id;
                cargaNuevoConsumo("consumos.dat", con);
            }
        }
        idCliente++;
    } while(idCliente<=cliente);
}


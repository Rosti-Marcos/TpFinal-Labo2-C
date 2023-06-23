#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

void nuevoCliente(char archivo[]) {
    int emailValido=0;
    char opcion=0;
    int id = cuentaRegistros("clientes.dat", sizeof(stClientes));
    stClientes cliente;
    FILE *pClientes = fopen(archivo,"ab");
    if (pClientes!= NULL) {
        do {
            do {

                printf("\n Nro de Cliente............: ");
                scanf("%d", &cliente.nroCliente);
                if (CompruebaNumCliente(cliente.nroCliente)==1) {
                    printf("El numero de clientes ingresado ya existe-Ingrese otro");
                }
            } while(CompruebaNumCliente(cliente.nroCliente)==1);

            printf("\n Nombre....................: ");
            fflush(stdin);
            gets(&cliente.nombre);
            printf("\n Apellido..................: ");
            fflush(stdin);
            gets(&cliente.apellido);
            printf("\n DNI.......................: ");
            fflush(stdin);
            gets(&cliente.dni);
            do {
                printf("\n Email.....................: ");
                fflush(stdin);
                gets(&cliente.email);
                emailValido=validaEmail(cliente);
                if(emailValido==0) {
                    printf("Email ingresado no es valido, Reingrese");
                }
            } while (emailValido==0);
            printf("\n Domicilio.................: ");
            fflush(stdin);
            gets(&cliente.domicilio);
            printf("\n Movil.....................: ");
            fflush(stdin);
            gets(&cliente.movil);
            cliente.estado=0;
            id++;
            cliente.id = id;

            fwrite(&cliente, sizeof(stClientes), 1, pClientes);
            printf("\n ESC para salir, otra para continuar...");
            opcion=getch();
            system("cls");
        } while(opcion!=27);
        fclose(pClientes);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
}

int validaEmail(stClientes cliente) {
    int flag=0;
    char caracter = '@';
    char caracterEnCadena[] = {caracter, '\0'};

    if (strstr(cliente.email, caracterEnCadena) != NULL) {
        flag=1;
    }

    return flag;
}

int validaEmailChar(char eMailNew []) {
    int flag=0;
    char caracter = '@';
    char caracterEnCadena[] = {caracter, '\0'};

    if (strstr(eMailNew, caracterEnCadena) != NULL) {
        flag=1;
    }

    return flag;
}

int CompruebaNumCliente (int numCliente) {
    int flag = 0;
    stClientes cliente;
    FILE *pCliente=fopen("clientes.dat","rb");
    if (pCliente) {
        while(flag==0 && fread(&cliente,sizeof(stClientes),1,pCliente)>0) {
            if (cliente.nroCliente==numCliente) {
                flag=1;
                return flag;
            }
        }
        fclose(pCliente);
    }
    return flag;
}


int cuentaRegistros(char archivo[], int tamanioSt) {

    int cantidadRegistros = 0;
    FILE *pArchi = fopen(archivo, "rb");

    if(pArchi) {
        fseek(pArchi, 0, SEEK_END);
        cantidadRegistros=ftell(pArchi)/tamanioSt;
        fclose(pArchi);
    }

    return cantidadRegistros;
}


void modificaEmail(char archivo[], char eMailNew [], char eMailActual []) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(strcmp(cliente.email, eMailActual)==0) {
                strcpy(cliente.email, eMailNew);
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

void modificaMovil(char archivo[], char movilNew [], char movilActual []) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(strcmp(cliente.movil, movilActual)==0) {
                strcpy(cliente.movil, movilNew);
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

void modificaDni(char archivo[], char dniNew [], char dniActual []) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(strcmp(cliente.dni, dniActual)==0) {
                strcpy(cliente.dni, dniNew);
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

void modificaEstado(char archivo[], int estado) {
    stClientes cliente;
    int flag=0;
    int pos=0;
    FILE *pArchi = fopen(archivo, "r+b");
    if(pArchi) {
        while(flag==0 && fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {
            if(cliente.estado==estado) {
                if(cliente.estado==1) {
                    cliente.estado=0;
                } else {
                    cliente.estado=1;
                }
                pos=ftell(pArchi)-sizeof(stClientes);
                fseek(pArchi,pos,SEEK_SET);
                fwrite(&cliente, sizeof(stClientes), 1, pArchi);
                flag=1;
            }
        }
    }
    fclose(pArchi);
}

int archivo2array(stClientes **arrayClientes, char archivo[]) {
    int val=cuentaRegistros(archivo, sizeof(stClientes));
    stClientes e;
    int i=0;

    (*arrayClientes)=(stClientes*)malloc(sizeof(stClientes)*val);
    FILE *archi = fopen(archivo, "rb");
    if(archi) {
        while(fread(&e, sizeof(stClientes), 1, archi)>0) {
            (*arrayClientes)[i] = e;
            i++;
        }
        fclose(archi);
    }
    return val;
}

void buscaRegistroNroCliente (char archivo [], int nroCliente) {
    int flag=0;
    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(cliente.nroCliente == nroCliente) {
                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }
}

void buscaRegistroMovil (char archivo [], char nroMovil []) {
    int flag=0;
    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(strcmp(cliente.movil,nroMovil)==0) {
                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }
}

void buscaRegistroDni (char archivo [], char dni []) {
    int flag=0;
    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(strcmp(cliente.dni,dni)==0) {
                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }
}

void buscaRegistroEmail (char archivo [], char email []) {
    int flag=0;

    stClientes cliente;
    FILE *pArchi = fopen(archivo, "rb");
    if(pArchi) {
        while(fread(&cliente, sizeof(stClientes), 1, pArchi)>0) {

            if(strcmp(cliente.email,email)==0) {

                muestraUnCliente(cliente);
                flag=1;
            }
        }
        fclose(pArchi);
    } else {
        printf("/n ERROR DE APERTURA DE ARCHIVO ");
    }
    if(flag==0) {
        printf("\nNo existe");
    }

}

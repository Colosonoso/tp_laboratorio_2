#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define TAM 3
#define FLUSH  while(getchar() != '\n')
/* ESTRUCTURA DE LOS DATOS QUE VOY A USAR */
struct modelo
    {
    char codigo[5]
    char descripcion[30];
    float precio;
    int stock;
    };

/* DEFINICION DE PROTOTIPOS */
    void Menu();
    void ValidarCodigo(char[]);
    void ValidarCadena(char[]);
    void altaEmpleado(struct modelo []);
    void BajaEmpleado(struct modelo []);
    void MuestraDatos(struct modelo []);
    void ModificaDatos(struct modelo []);

/* ACA ESTA EL MAIN */
    int main ()
        {
        /* DECLARACIOM DE VARIABLES */
        int i, opc1=9;
        struct modelo datos[TAM];
        /* PUESTA EN CERO DEL VECTOR DE CODIGOS */
        for(i=0;i<TAM;i++)
        strcpy(datos[i].codigo, "0000");
        /* MENU PRINCIPAL */
        while (opc1!=5)
        {
        Menu();
        /* LEE OPCION*/
        scanf("%d", &opc1);
        switch (opc1)
            {
            /* OPCION ALTA DE PRODUCTOS*/
            case 1:
                altaEmpleado(datos);
                break;
            /* OPCION QUE DA DE BAJA UN ARTICULO */
            case 2:
                BajaEmpleado(datos);
                break;
            /* OPCION MUESTRA EN PANTALLA */
            case 3:
                MuestraDatos(datos);
                break;
            /* OPCION DE MODIFICACION DE ARTICULOS */
            case 4:
                ModificaDatos(datos);
                break;
            case 5:
                system("cls");
                printf("Fin del programa\n");
                system("pause>>null");
                break;
            default:
                printf("Opcion incorrecta");
                system("pause>>null");
                break;
            }
        }
    return 0;
    }
/* DEFINICION DE LAS FUNCIONES*/
void Menu()
    {
    system("cls");
    printf("Menu principal\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Muestra en pantalla\n");
    printf("4 - Modificacion\n");
    printf("5 - Salir\n");
    printf("Elija opcion: ");
    }

void ValidarCadena(char cadena[])
    {
    char aux[2000];
    FLUSH;
    fgets(aux, 2000, stdin);
    while (strlen(aux)<1 || strlen(aux)>30)
        {
        printf("\nReingrese descripcion, maximo 30: ");
        scanf("%s", aux);
        }
    strcpy(cadena, aux);
    return;
    }

void ValidarCodigo(char codigo[])
    {
    char aux [50];
    // FLUSH;
    scanf("%s", aux);
    while (strlen(aux)!=4)
        {
        printf("Reingrese codigo (4 caracteres): ");
        scanf("%s", aux);
        }
    strcpy(codigo, aux);
    }

void altaEmpleado(struct modelo datos[])
    {
    int i;
    float tempfloat;
    system("cls");
    printf("ALTA DE EMPLEADO\n");
    printf("-----------------\n");
    /* BUSCA UN LUGAR VACIO PARA GUARDAR*/
    for(i=0;i<TAM;i++)
        {
        if(strcmp(datos[i].codigo, "0000")==0)
            {
            /* INGRESA CODIGO */
            printf("Ingrese codigo: ");
            ValidarCodigo(datos[i].codigo);
            /* INGRESA DESCRIPCION */
            printf("Ingrese Descripcion: ");
            ValidarCadena(datos[i].descripcion);
            /* INGRESA PRECIO */
            printf("Ingrese Precio: ");
            scanf("%f", &tempfloat);
            datos[i].precio=tempfloat;
            /* INGRESA STOCK */
            printf("Ingrese Stock: ");
            scanf("%d", &datos[i].stock);
            break;
            }
        }
        /* SI RECORRE TODO EL VECTOR DICE SI NO QUEDA ESPACIO O SI FUE GUARDADO*/
        if(i==TAM)
            printf("No queda memoria suficiente para seguir guardar datos\n");
            else
            printf("\nEl dato fue guardado exitosamente");
    printf("\nPresione ENTER para continuar...");
    system("pause>>null");
    return;
    }

void BajaEmpleado(struct modelo datos[])
    {
    int a;
    char aux[30];
    system("cls");
    printf("BAJA DE ARTICULOS\n");
    printf("-----------------\n");
    /* INGRESA CODIGO */
    printf("Ingrese codigo del articulo que quiere dar de baja: ");
    FLUSH;
    gets(aux);

    /*VALIDA CODIGO A DAR DE BAJA A LA TERCERA VEZ VUELVE A MENU PRINCIPAL*/
    while (strlen(aux)!=4)
        {
        printf("Reingrese codigo que quiere dar de baja (rango 4): ");
        FLUSH;
        gets(aux);
        }
    /* BUSCA EN EL VECTOR SI LO ENCUENTRA PONE CODIGO A CERO*/
    for(a=0;a<TAM;a++)
        {
        if(strcmp(aux, datos[a].codigo)==0)
            {
            strcpy(datos[a].codigo, "0000");
            break;
            }
        }
    /* COMPRUEBA SI RECCORIO TODO EL VECTOR NO LO ENCONTRO, SINO YA ESTA BORRADO*/
    if (a==TAM)
        printf("\nCodigo de articulo no encontrado.");
        else
        printf("\nArticulo borrado exitosamente");

    printf("\nPresione ENTER para continuar...");
    system("pause>>null");
}
void MuestraDatos(struct modelo datos[])
    {
    int i;
    system("cls");
    printf("LISTADO DE ARTICULOS\n");
    printf("--------------------\n");
    printf("Codigo  Descripcion                   Precio  Stock\n");
    printf("------  ----------------------------  ------  -----\n");
    /* LISTA TODO EL VECTOR CON SUS DISTINTOS TIPOS DE DATOS (EL -29 ES PARA QUE LOS CARACTERES SE PONGAN A LA IZQUIERDA)*/
    for(i=0;i<TAM;i++)
        {
        if(strcmp(datos[i].codigo, "0000")!= 0)
            {
            printf("%6s  %-29s %6.2f %6d\n", datos[i].codigo, datos[i].descripcion, datos[i].precio, datos[i].stock);
            }
        }
    printf("\nPresiones ENTER para continuar...");
    system("pause>>null");
    }

void ModificaDatos(struct modelo datos[])
    {
    int a, modificar=9;
    float tempfloat;
    char aux[30];

    system("cls");
    printf("MODIFICACION DE ARTICULOS\n");
    printf("-------------------------\n");
    /* INGRESAS EL CODIGO A MODIFICAR */
    printf("Ingrese codigo de articulo: ");
    FLUSH;
    gets(aux);
    /* VALIDA */
    while (strlen(aux)!=4)
        {
        printf("Reingrese codigo (4 caracteres): ");
        FLUSH;
        gets(aux);
        }
    /* RECORRE TODO EL VECTOR EN SU BUSQUEDA */
    for(a=0;a<TAM;a++)
        {
        if(strcmp(aux, datos[a].codigo)==0)
            {
            system("cls");
            /* MUESRTA SUBMENU DE OPCIONES */
            printf("MODIFICAR ARTICULO numero %s\n", aux);
            printf("------------------------------\n");
            printf("1 - Modificar descripcion (Actualmente: %s)\n", datos[a].descripcion);
            printf("2 - Modificar precio (Actualmente: %.2f)\n", datos[a].precio);
            printf("3 - Modificar Stock (Actualmente: %d)\n", datos[a].stock);
            printf("4 - Volver al menu principal\n");
            printf("Elija opcion: ");
            /* LEE LA OPCION SELECCIONADA */
            scanf("%d", &modificar);
            switch(modificar)
                {
                case 1:
                    system("cls");

                    /* INGRESA NUEVA DESCRIPCION */
                    printf("Ingrese nueva descripcion: ");
                    FLUSH;
                    gets(aux);

                    /* LA VALIDA */
                    while(strlen(aux)<1 || strlen(aux)>29)
                        {
                        printf("Reingrese nueva descripcion (valor maximo 29 caracteres): ");
                        FLUSH;
                        gets(aux);
                        }
                    /* LE ASIGNA EL NUEVO VALOR */
                    strcpy(datos[a].descripcion, aux);
                    printf("%s a sido asignado exitosamente.", datos[a].descripcion);
                    system("pause>>null");
                    break;

                case 2:
                    system("cls");

                    /* LEE NUEVO PRECIO Y LO ASIGNA */
                    printf("Ingrese nueva precio: ");
                    scanf("%f", &tempfloat);
                    datos[a].precio=tempfloat;
                    printf("%s ahora vale %.2f.", datos[a].descripcion, datos[a].precio);
                    system("pause>>null");
                    break;
                case 3:
                    system("cls");

                    /* LEE NUEVO PRECIO Y LO ASIGNA */
                    printf("Ingrese nueva cantidad de stock: ");
                    scanf("%d", &datos[a].stock);
                    printf("%s ahora tiene %d articulos en el sistema.",datos[a].descripcion, datos[a].stock);
                    system("pause>>null");
                    break;
                case 4:
                    system("cls");
                    break;
                }
            break;
            }
        }

        /* SI NO ENCONTRO EL CODIGO MUESTRA UNA LEYENDA */
        if (a==TAM)
            {
            printf("\nCodigo de articulo no encontrado.");
            }

     printf("\nPresione ENTER para continuar...");
     system("pause>>null");
    }

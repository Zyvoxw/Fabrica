#include <stdio.h>
#include <string.h>
#include "Funciones.h"

void ingresarProductoRecursos(char productos[5][50],  int *numProductos,  char recursos[45][50],  int disponibles[45], int *numRecursos){
    *numProductos = 0;
    *numRecursos = 0;
    char opc;

    do {
        printf("------- INGRESO DE PRODUCTOS -------\n");
        printf("Nombre del producto %d:\n", *numProductos + 1);
        fgets(productos[*numProductos], 50, stdin);
        int len = strlen(productos[*numProductos]);
        productos[*numProductos][len - 1] = '\0';

        (*numProductos)++;
        if (*numProductos >= 5) 
        break;

        printf("Desea ingresar otro producto? (s/n): ");
        scanf(" %c", &opc);
        while(getchar() != '\n');
    } while(opc == 's' || opc == 'S');

    do {
        printf("----- INGRESO DE RECURSOS -----\n");
        printf("Nombre del recurso %d:\n", *numRecursos + 1);
        fgets(recursos[*numRecursos], 50, stdin);
        int len = strlen(recursos[*numRecursos]);
        recursos[*numRecursos][len - 1] = '\0';

        int cantidad;
        do {
            printf("Cantidad disponible de %s: ", recursos[*numRecursos]);
            scanf("%d", &cantidad);
            while(getchar() != '\n');

            if(cantidad < 0) {
                printf("Cantidad invalida. Debe ser 0 o mayor.\n");
            }
        } while(cantidad < 0);

        disponibles[*numRecursos] = cantidad;
        (*numRecursos)++;

        if(*numRecursos >= 45) 
        break;

        printf("Desea ingresar otro recurso? (s/n): ");
        scanf(" %c", &opc);
        while(getchar() != '\n');
    } while(opc == 's' || opc == 'S');

    printf("\n------- PRODUCTOS INGRESADOS -------\n");
    for(int i = 0; i < *numProductos; i++){
        printf("%d - %s\n", i+1, productos[i]);
    }

    printf("\n------- RECURSOS INGRESADOS -------\n");
    for(int i = 0; i < *numRecursos; i++){
        printf("%d - %s - cantidad disponible: %d\n", i+1, recursos[i], disponibles[i]);
    }
}

void registrarTiempoProcesos(char nombreProductos[][50],char nombreRecursos[][50],int *numProductos,int *numRecursos,int recursosNecesarios[][5], int tiempoProducto[])
{
    printf("---- REGISTRO DE PROCESOS ----\n");

    for (int i = 0; i < *numProductos; i++)
    {
        printf("\nProducto: %s\n", nombreProductos[i]);

        for (int j = 0; j < *numRecursos; j++)
        {
            int cantidad;
            do {
                printf("Ingrese la cantidad necesaria del recurso '%s' para producirlo: \n ",nombreRecursos[j]);
                scanf("%d", &cantidad); 

                if (cantidad < 0) {
                    printf("No se permiten valores negativos.\n");
                }

            } while (cantidad < 0); 
            recursosNecesarios[i][j] = cantidad;  
        }

        int tiempo;
        do {
            printf("Ingrese el tiempo de fabricación (minutos) del producto '%s': ",nombreProductos[i]);
            scanf("%d", &tiempo);          
            if (tiempo < 0) {
                printf("El tiempo no puede ser negativo.\n");
            }
        } while (tiempo < 0);
        tiempoProducto[i] = tiempo;         
    }
}











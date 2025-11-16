#include <stdio.h>
#include <string.h>
#include "Funciones.h"

void ingresarProductoRecursos(char productos[5][50], int cantidadesProductos[5], int *numProductos, char recursos[45][50], int disponibles[45], int *numRecursos){
    *numProductos = 0;
    *numRecursos = 0;
    char opc;
    int cantidad;
    
    do {
        printf("------- INGRESO DE PRODUCTOS -------\n");
        printf("Nombre del producto %d:\n", *numProductos + 1);
        fgets(productos[*numProductos], 50, stdin);
        int len = strlen(productos[*numProductos]);
        if (len > 0 && productos[*numProductos][len - 1] == '\n') {
            productos[*numProductos][len - 1] = '\0';
        }

        (*numProductos)++;
        if (*numProductos >= 5) break;

        printf("Desea ingresar otro producto?(s/n): ");
        scanf(" %c", &opc);
        while (getchar() != '\n'); 

    } while (opc == 's' || opc == 'S');

    
    do {
        printf("----- INGRESO DE RECURSOS -----\n");
        printf("Nombre del recurso %d:\n", *numRecursos + 1);
        fgets(recursos[*numRecursos], 50, stdin);
        int len = strlen(recursos[*numRecursos]);
        if (len > 0 && recursos[*numRecursos][len - 1] == '\n') {
            recursos[*numRecursos][len - 1] = '\0';
        }
            int num;
            
        do {
            int num;

            printf("Cantidad disponible de %s (>=0): ", recursos[*numRecursos]);
            scanf("%d", &num);
            while (getchar() != '\n');  

            if (num < 0) {
                printf("Cantidad inválida. Debe ser 0 o mayor.\n");
            }
        } while (num < 0);

        disponibles[*numRecursos] = num;

        (*numRecursos)++;

        if (*numRecursos >= 100) 
        break;

        printf("Desea ingresar otro recurso?(s/n): ");
        scanf(" %c", &opc);
        while (getchar() != '\n');

    } while (opc == 's' || opc == 'S');

    printf("------- PRODUCTOS INGRESADOS -------\n");
    for (int i = 0; i < *numProductos; i++) {
        printf("%d - %s \n", i + 1, productos[i]);
    }

    printf("------- RECURSOS INGRESADOS -------\n");
    for (int i = 0; i < *numRecursos; i++) {
        printf("%d - %s - cantidad disponible: %d\n", i + 1, recursos[i], disponibles[i]);
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










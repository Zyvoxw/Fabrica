#include <stdio.h>
#include <string.h>
#include "Funciones.h"

void ingresarProductosYRecursos(char productos[5][50], int *numProductos, char recursos[100][50], int disponibles[100], int *numRecursos)
{
    char opc;
    *numProductos = 0;
    *numRecursos = 0;

    printf("¿Cuántos productos desea ingresar? (1-5): ");
    scanf("%d", numProductos);
    fgets(productos[0], 50, stdin);

    printf("------Ingreso de productos------\n");

    for (int i = 0; i < *numProductos; i++) {

        printf("Nombre del producto %d:\n", i + 1);
        fgets(productos[i], 50, stdin);
        int len = strlen(productos[i]) - 1;
        productos[i][len] = '\0';
    }

    printf("--------Ingreso de recursos-------\n");

    do {

        printf("Nombre del recurso %d: ", *numRecursos + 1);

        fgets(recursos[*numRecursos], 50, stdin);
        int len = strlen(recursos[*numRecursos]) - 1;
        recursos[*numRecursos][len] = '\0';

        printf("Cantidad disponible de %s: ", recursos[*numRecursos]);
        scanf("%d", &disponibles[*numRecursos]);
        fgets(recursos[*numRecursos], 50, stdin);

        (*numRecursos)++;

        printf("¿Desea ingresar otro recurso? (s/n): ");
        scanf(" %c", &opc);

    } while ((opc == 's' || opc == 'S') && *numRecursos < 100);

    printf("\nProductos y recursos ingresados correctamente.\n");
}



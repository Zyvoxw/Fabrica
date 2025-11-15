#include <stdio.h>
#include "Funciones.h"

int main()
{
    char productos[5][50];
    char recursos[100][50];
    int disponibles[100];

    int numProductos;
    int numRecursos;

    ingresarProductosYRecursos(productos, &numProductos, recursos, disponibles, &numRecursos);

    printf("--- Productos ingresados ---\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%d. %s\n", i + 1, productos[i]);
    }

    printf("--- Recursos ingresados ---\n");
    for (int i = 0; i < numRecursos; i++) {
        printf("%d. %s (Cantidad: %d)\n", i + 1, recursos[i], disponibles[i]);
    }

    return 0;
}

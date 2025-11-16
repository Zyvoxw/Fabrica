#include <stdio.h>
#include <string.h>

void ingresarProductoRecursos(char productos[5][50], int cantidadesProductos[5], int *numProductos, char recursos[100][50], int disponibles[100], int *numRecursos){
    *numProductos = 0;
    *numRecursos = 0;
    char opc;

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

    

    do {
        int cantidad; //DUDADAR
        
        printf("Cantidad disponible de %s:\n", recursos[*numRecursos]);
        scanf("%d", &cantidad);
        while (getchar() != '\n'); 

        if (cantidad < 0) {
            printf("Cantidad inválida. Debe ser 0 o mayor.\n");
        }
    } while (cantidad < 0);

    disponibles[*numRecursos] = cantidad;

    (*numRecursos)++;
    if (*numRecursos >= 100) break;

    printf("Desea ingresar otro recurso?(s/n): ");
    char opc;
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
#include <stdio.h>
#include <string.h>
#include "Funciones.h"

int main() {
    char productos[5][50];
    int cantidadesProductos[5];      
    char recursos[100][50];
    int disponibles[100];             
    int numProductos = 0, numRecursos = 0;

    int opcionMenu;

    do {
        printf("\n------------ MENU --------\n");
        printf("1. Ingresar productos del catalogo e inventario\n");
        printf("2. Editar Datos\n");
        printf("3. Eliminar Datos\n");
        printf("4. Solicitud del cliente\n");
        printf("5. Salir\n");   
        printf("Ingrese la opcion que desea: ");
        scanf(" %d", &opcionMenu);
        while(getchar() != '\n'); // limpiar buffer

        switch (opcionMenu) {
            case 1:
                
                ingresarProductoRecursos(productos, cantidadesProductos, &numProductos, recursos, disponibles, &numRecursos);
                break;
            case 2:
               
                break;
            case 3:
               
                break;
            case 4:
                
                break;
            case 5:
                printf("Saliendo...\n"); 
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcionMenu != 5);

    // Mostrar resumen final
    printf("\n========= RESUMEN FINAL =========\n");

    printf("------- PRODUCTOS INGRESADOS -------\n");
    if (numProductos == 0) {
        printf("No se ingresaron productos.\n");
    } else {
        for (int i = 0; i < numProductos; i++) {
            printf("%d - %s - cantidad: %d\n", i + 1, productos[i], cantidadesProductos[i]);
        }
    }

    printf("------- RECURSOS INGRESADOS -------\n");
    if (numRecursos == 0) {
        printf("No se ingresaron recursos.\n");
    } else {
        for (int i = 0; i < numRecursos; i++) {
            printf("%d - %s - cantidad disponible: %d\n", i + 1, recursos[i], disponibles[i]);
        }
    }

    printf("\nTotal de productos ingresados: %d\n", numProductos);
    printf("Total de recursos ingresados: %d\n", numRecursos);

    return 0;
}








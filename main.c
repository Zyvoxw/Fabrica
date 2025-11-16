#include <stdio.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    char Productos[5][50];
    int tiempo[5];
    int recursosNecesarios[5][5];
    char productos[5][50];
    int cantidadesProductos[5];      
    char recursos[45][50];
    int disponibles[45];             
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
                printf("Saliendo...FIN DEL PROGRAMA\n"); 
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcionMenu != 5);

    printf("-----RESUMEN FINAL-----\n");

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



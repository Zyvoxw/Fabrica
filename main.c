#include <stdio.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    int tiempo[5];
    int recursosNecesarios[5][5];
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
        while(getchar() != '\n'); 
         switch (opcionMenu)
        {
        case 1:
            ingresarProductoRecursos(productos, &numProductos, recursos, disponibles, &numRecursos);
            
            break;
        case 2:
            registrarTiempoProcesos(productos,recursos, &numProductos,&numRecursos,recursosNecesarios,tiempo);
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            printf("Saliendo...\n"); 
            break;
        
        default:
            printf("Opcion invalida. Intente de nuevo.\n");
            break;
        }
    } while (opcionMenu != 6);

    return 0;
}









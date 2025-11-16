#include <stdio.h>
#include <string.h>
#include "Funciones.h"

int main()
{
    char nombreProducto[5][50];
    int cantR=0;
    char nombreRecursos[10];
    int numRecursos;
    
    int opcionMenu;
    do{
        printf("------------MENU--------\n");
        printf("1. Ingresar productos del catalogo e inventario\n");
        printf("2. Editar Datos\n");
        printf("3. Eliminar Datos\n");
        printf("4. Solicitud del cliente\n");
        printf("5. Salir\n");   
        printf(">> \n");
        printf("Ingrese la opcion que desea: \n");
        scanf(" %d",&opcionMenu);
        switch (opcionMenu)
        {
        case 1:
            do{
                printf("Ingrese el nombre del producto (1-5): ");
                leercadena(nombreProducto,50);
            }while ();
        
            printf("Ingrese el nombre del producto (1-5): ");

            
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
            break;
        }
    } while (opcionMenu!=6);
    

    return 0;
}

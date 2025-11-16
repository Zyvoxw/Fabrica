#include <stdio.h>
#include <string.h>
#include "Funciones.h"

void leerCadena(char *cadena, int n){
    fgets(cadena, n, stdin);
    int len = strlen(cadena)-1;
    cadena[len]='\0';
}

void ingresarProductoRecursos(char productos[5][50], int *numProductos, int *numRecursos, int disponibles[100], char recursos[100][50]){

    *numProductos=0;
    *numRecursos=0;
    char opc;

do {
    printf("-------INGRESO DE PRODUCTOS------\n");
    printf("Nombre del producto %d:\n", *numProductos + 1);
    leerCadena(productos[*numProductos], 50);
    (*numProductos)++;


    printf("Desea ingresar otro producto?(s/n): ");
    scanf(" %c", &opc);
    
    if(*numProductos >= 5) 
    break;

} while(opc == 's' || opc == 'S');
do{
    printf("-----INGRESO DE RECURSOS-----\n");
    printf("Nombre del recurso %d:\n", *numRecursos + 1);
    leerCadena(recursos[*numRecursos], 50);

    printf("Cantidad disponible de %s:\n", recursos[*numRecursos]);
    scanf("%d", &disponibles[*numRecursos]);

    (*numRecursos)++;

    if(*numRecursos >= 100)
    break;

    printf("Desea ingresar otro recurso?(s/n)");
    leerCadena(&opc, 2);

}while(opc == 's' || opc == 'S');

        printf("-------PRODUCTOS INGRESADOS------\n");
        for(int i = 0; i < *numProductos; i++){
        printf("\t%d\n-\t%s\n", i + 1, productos[i]);

    }

        printf("-------RECURSOS INGRESADOS------\n");
        for(int i = 0; i < *numRecursos; i++){
        printf("\t%d\n-\t%s\n-\tcantidad disponible: %d\n", i + 1, recursos[i], disponibles[i]);

    }
}

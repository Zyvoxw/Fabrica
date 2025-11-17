#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leerCadena(char *cadena, int tam)
{
    fflush(stdin);
    fgets(cadena, tam, stdin);
    int len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n')
        cadena[len - 1] = '\0';
}

void ingresoProductos(char productos[][30],int pantallas[], int chips[],int tarjetas[], int sensores[],int tiempo[],int indice)
{
    int valor;

    printf("Nombre del producto [%d]: ", indice);
    leerCadena(productos[indice], 30);

    // Pantallas
    do {
        printf("Cantidad de pantallas que usa el producto: ");
        scanf("%d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    pantallas[indice] = valor;

    // Chips
    do {
        printf("Cantidad de chips que usa el producto: ");
        scanf("%d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    chips[indice] = valor;

    // Tarjetas
    do {
        printf("Cantidad de tarjetas que usa el producto: ");
        scanf("%d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    tarjetas[indice] = valor;

    // Sensores
    do {
        printf("Cantidad de sensores que usa el producto: ");
        scanf("%d", &valor);
        if (valor < 0)
            printf("La cantidad no puede ser negativa.\n");
    } while (valor < 0);
    sensores[indice] = valor;

    // Tiempo
    do {
        printf("Tiempo de produccion (en minutos) por unidad: ");
        scanf("%d", &valor);
        if (valor < 0)
            printf("El tiempo no puede ser negativo.\n");
    } while (valor < 0);
    tiempo[indice] = valor;

    // Limpio el buffer después de los scanf
    while (getchar() != '\n');
}

void imprimirProductos(char productos[][30],int pantallas[],int chips[],int tarjetas[],int sensores[],int tiempo[],int cont)
{
    if (cont == 0) {
        printf("No hay productos registrados.\n");
        return;
    }

    printf("\n#\tProducto\t\tPantallas\tChips\t\tTarjetas\t\tsensores\t\tTiempo\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < cont; i++) {
        printf("%d\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,productos[i],pantallas[i], chips[i],tarjetas[i],sensores[i],tiempo[i]);
    }
}

int leerIndiceValido(int cont)// venta
{
    int indice;
    do {
        printf("Ingrese el numero del producto (0 a %d): ", cont - 1);
        scanf("%d", &indice);
        if (indice < 0 || indice >= cont)
            printf("opcion invalida.\n");
    } while (indice < 0 || indice >= cont);

    // Limpio buffer
    while (getchar() != '\n');

    return indice;
}










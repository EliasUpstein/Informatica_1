/* Desarrollar programa que permita pedir por pantalla una cantidad de metros cuadrados y
luego el costo del metro cuadrado. La cantidad de metros debe estar entre 1 y 100,
mientras que el costo del metro cuadrado debe estar entre $100 y $5.000. Imprima el
total aplicando un 5% de descuento sobre el neto (cantidad * costo) */

#include <stdio.h>

int main(void)
{
    float m2, costo;

    printf("Ingrese la cantidad de metros cuadrados: ");
    fflush(stdin);
    scanf("%f", &m2);

    while (m2 < 1 || m2 > 100)
    {
        printf("\nIngrese una cantidad válida (1 - 100): ");
        fflush(stdin);
        scanf("%f", &m2);
    }
    
    printf("\nIngrese el costo del metro cuadrado: ");
    fflush(stdin);
    scanf("%f", &costo);

    while (costo < 100 || costo > 5000)
    {
        printf("\nIngrese un costo válido ($100 - $5.000): ");
        fflush(stdin);
        scanf("%f", &costo);
    }

    printf("Costo total: $%f\n", ((m2 * costo) * 0.95));        //Total con descuento aplicado

    return 0;
}
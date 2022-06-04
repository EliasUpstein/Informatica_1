/* Desarrollar programa que permita pedir por pantalla el costo de una compra y luego el
monto con el que cancelará. Valide que el costo esté entre $100 y $100.000, mientras
que el monto con el que cancelará no debe ser menor que el costo digitado. Imprima:
costo, monto y vuelto (en caso de existir). */

#include <stdio.h>

int main(void)
{
    float costo, pago;

    printf("Ingrese el costo de la compra: ");
    fflush(stdin);
    scanf("%f", &costo);

    while (costo < 100 || costo > 100000)
    {
        printf("\nIngrese un costo válido: ");
        fflush(stdin);
        scanf("%f", &costo);
    }
    
    printf("\nIngrese el monto de pago: ");
    fflush(stdin);
    scanf("%f", &pago);

    while (pago < costo)
    {
        printf("\nIngrese un pago mayor al costo: ");
        fflush(stdin);
        scanf("%f", &pago);
    }

    printf("Costo de la compra: %f\nMonto de pago: %f\nVuelto: %f\n", costo, pago, (pago-costo));

    return 0;
}
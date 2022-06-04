/* Desarrollar programa que permita pedir por pantalla el costo neto de un producto,
calcule el iva (21% * neto) y luego determine el total (neto + iva). Valide que el costo
neto sea mayor o igual que $10.000. Imprima todos los valores */

#include <stdio.h>

int main(void)
{
    float costo;

    printf("Introduzca el costo del producto: \n"); 
    fflush(stdin);
    scanf("%f", &costo);

    while(costo < 10000)
    { 
        printf("Por favor ingrese un costo válido: "); 
        fflush(stdin);
        scanf("%f", &costo);
    }

    printf("El costo neto es: %f\nEl valor del iva es: %f\nEl costo total es: %f\n", costo, costo * 0.21, costo * 1.21);

    return 1;
}
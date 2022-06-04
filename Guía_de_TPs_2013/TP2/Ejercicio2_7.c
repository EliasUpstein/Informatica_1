/* Escribir un programa que calcule la superficie de un círculo cuyo radio se ingresa
por teclado. */

#include <stdio.h>

#define PI 3.14

int main(void)
{
    float radio, superficie;

    printf("Ingrese el radio del círculo:\n");
    fflush(stdin);
    scanf("%f", &radio);

    superficie = PI * radio * radio;     //pi por radio al cuadrado

    printf("La superficio del círculo es: %f\n", superficie);

    return 0;
}
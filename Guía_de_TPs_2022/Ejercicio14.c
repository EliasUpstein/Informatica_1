/* Escribí un programa que solicite al usuario un número y le reste el 15%, almacenando todo en
una única variable. A continuación, mostrar el resultado final en pantalla. */

#include <stdio.h>

int main(void)
{
    float numero;

    printf("Ingrese el número: ");
    fflush(stdin);
    scanf("%f", &numero);

    numero = numero * 0.85;

    printf("\nNúmero - 15 porciento: %f\n", numero);

    return 0;
}
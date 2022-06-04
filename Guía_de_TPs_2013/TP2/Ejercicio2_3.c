/* Escribir un programa donde ingresan por teclado dos valores que son
almacenados en las variables A y B del mismo tipo. El programa deberá
intercambiar los valores de las mismas y mostrar por pantalla los valores
ingresados y luego del intercambio. */

#include <stdio.h>

int main(void)
{
    float A, B, aux;

    printf("Ingrese el valor A:\n");
    fflush(stdin);
    scanf("%f", &A);

    printf("Ingrese el valor B:\n");
    fflush(stdin);
    scanf("%f", &B);

    printf("El valor ingresado de A es: %f\n", A);
    printf("El valor ingresado de B es: %f\n", B);

    aux = B;
    B = A;
    A = aux;

    printf("El valor intercambiado de A es: %f\n", A);
    printf("El valor intercambiado de B es: %f\n", B);

    return 0;
}
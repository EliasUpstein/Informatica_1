/* Escribir un programa que calcule la diferencia de dos números enteros e informe
por medio de un mensaje en pantalla, si la misma es positiva o negativa. */

#include <stdio.h>

int main()
{
    int A, B;

    printf("Ingrese el primer número:\n");
    fflush(stdin);
    scanf("%d", &A);
    
    printf("Ingrese el segundo número:\n");
    fflush(stdin);
    scanf("%d", &B);

    if ((A - B) > 0)
        printf("La diferencia entre el primer y el segundo número es positiva\n");
    else
        printf("La diferencia entre el primer y el segundo número es negativa\n");

    return 0;
}
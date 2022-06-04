/* Escribir un programa que calcule la diferencia de dos números enteros e informe
si la misma es positiva, negativa o cero. */

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
    else if ((A - B) == 0)
        printf("La diferencia entre el primer y el segundo número es nula\n");
    else
        printf("La diferencia entre el primer y el segundo número es negativa\n");

    return 0;
}
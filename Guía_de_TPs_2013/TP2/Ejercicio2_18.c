/* Modificar el programa anterior para que informe del ingreso de un valor nulo o
negativo */

#include <stdio.h>

int main()
{
    float A, B, C;

    printf("Ingrese el primer lado:\n");
    fflush(stdin);
    scanf("%f", &A);

    while (A <= 0)
    {
        printf("Ingrese un valor válido:\n");
        fflush(stdin);
        scanf("%f", &A);
    }
    
    printf("Ingrese el segundo lado:\n");
    fflush(stdin);
    scanf("%f", &B);

    while (B <= 0)
    {
        printf("Ingrese un valor válido:\n");
        fflush(stdin);
        scanf("%f", &B);
    }

    printf("Ingrese el tercer lado:\n");
    fflush(stdin);
    scanf("%f", &C);

    while (C <= 0)
    {
        printf("Ingrese un valor válido:\n");
        fflush(stdin);
        scanf("%f", &C);
    }

    if ((A == B) && (A == C))
        printf("El triángulo es equilátero.\n");
    else if ((A != B) && (A != C) && (B != C))
        printf("El triángulo es escaleno.\n");
    else
        printf("El triángulo es isósceles.\n");

    return 0;
}
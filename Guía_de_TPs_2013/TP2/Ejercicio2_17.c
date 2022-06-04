/* Escribir un programa que reciba tres valores reales, correspondientes a las
longitudes de los lados de un triángulo, y luego informe si el triángulo ingresado
es equilátero, isósceles o escaleno. */ 

#include <stdio.h>

int main()
{
    float A, B, C;

    printf("Ingrese el primer lado:\n");
    fflush(stdin);
    scanf("%f", &A);
    
    printf("Ingrese el segundo lado:\n");
    fflush(stdin);
    scanf("%f", &B);

    printf("Ingrese el tercer lado:\n");
    fflush(stdin);
    scanf("%f", &C);

    if ((A == B) && (A == C))
        printf("El triángulo es equilátero.\n");
    else if ((A != B) && (A != C) && (B != C))
        printf("El triángulo es escaleno.\n");
    else
        printf("El triángulo es isósceles.\n");

    return 0;
}
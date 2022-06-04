/* Modificar el programa anterior para determinar si el triángulo es rectángulo e
indique cual de los datos es la hipotenusa. */

#include <stdio.h>
#include <math.h>

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

    if (A+B < C)        //No se cumple la desigualdad triangular
        printf("Los datos ingresados no corresponden a un triángulo\n");
    else
    {
        if ((A == B) && (A == C))
            printf("El triángulo es equilátero.\n");
        else if ((A != B) && (A != C) && (B != C))
            printf("El triángulo es escaleno.\n");
        else
            printf("El triángulo es isósceles.\n");

        //Si A es el lado mayor (hipotenusa) y su cuadrado es igual a la suma de los cuadrados de los catetos B y C
        if((A > B && A > C) && (pow(A,2) == pow(B,2) + pow(C,2)))       
            printf("El triángulo es rectángulo y su hipotenusa es %f.\n", A);
        else if ((B > A && B > C) && (pow(B,2) == pow(A,2) + pow(C,2)))
            printf("El triángulo es rectángulo y su hipotenusa es %f.\n", B);
        else if ((C > A && C > B) && (pow(C,2) == pow(A,2) + pow(B,2)))
            printf("El triángulo es rectángulo y su hipotenusa es %f.\n", C);
    }
    return 0;
}
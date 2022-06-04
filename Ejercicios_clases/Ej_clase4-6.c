/* Realizar el estructograma y la codificación en C de:
Un programa que solicita 5 números y luego los imprime en orden inverso
Un programa que pregunta los cof de un polinomio de grado 5
Y finalmente evalúe el polinomio desde:
x = -10 a x = 10 en pasos de a 1 entero. */

#include <stdio.h>
#include <stdlib.h>

#define N1 5
#define GP 6

int main()
{
    //Item 1

    float item1[N1];

    for (int i = 0; i < N1; i++)
    {
        printf("Ingrese número %d\n", i+1);
        fflush(stdin);
        scanf("%f", &item1[i]);
    }

    printf("Orden invertido:\n");

    for (int i = (N1-1); i >= 0; i--)
    {
        printf("%.2f\t", item1[i]);
    }
    
//-------------------------------------------------------------------------------------------------
    //Item 2
    printf("\n");

    float cof[GP];

    for (int i = 0; i < GP; i++)
    {
        printf("Ingrese el coeficiente a%d\n", i);
        fflush(stdin);
        scanf("%f", &cof[i]);
    }

    printf("El polinomio es: %.2f + %.2fx + %.2fx^2 + %.2fx^3 + %.2fx^4 + %.2fx^5\n", cof[0], cof[1], cof[2], cof[3], cof[4], cof[5]);

    for (int x = -10; x < 11; x++)
    {
        float polx = ((cof[0]) + (cof[1] * x) + (cof[2] * x*x) + (cof[3] * x*x*x) + (cof[4] * x*x*x*x) + (cof[5] * x*x*x*x*x));

        printf("\nEl polinomio evaluado en %d = %.2f\n", x, polx);
    }

    system("pause");
    return 0;
}


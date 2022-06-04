/* Escriba un programa donde se ingresa un valor entero y positivo, e informe si el
valor es par o impar. */

#include <stdio.h>

int main()
{
    int a;

    printf("Ingrese un valor entero y positivo:\n");
    fflush(stdin);
    scanf("%d", &a);

    while (a <= 0)
    {
        printf("Ingrese un valor entero y positivo:\n");
        fflush(stdin);
        scanf("%d", &a);
    }

    if (a % 2 == 0)
        printf("El número %d es par.\n",a);
    else
        printf("El número %d es impar.\n",a);
        
    return 0;
}
/* Escribir un programa que, dado un número N entero y positivo, calcule el
factorial de N. */

#include <stdio.h>

int main()
{
    int n, fact = 1;

    printf("Ingrese un número entero y positivo:\n");
    fflush(stdin);
    scanf("%d", &n);

    while (n <= 0)
    {
        printf("Ingrese un número válido:\n");
        fflush(stdin);
        scanf("%d", &n);
    }
    
    for (int i = n; i > 0; i--)
    {
        fact = fact * i;
    }

    printf("El factorial del número %d es : %d\n", n, fact);

    return 0;
}
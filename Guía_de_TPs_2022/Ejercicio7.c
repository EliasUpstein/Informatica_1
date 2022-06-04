/* Desarrollar programa que permita pedir por pantalla dos valores numéricos y luego
identificar cuál de ellos es mayor o si son iguales. Valide que los dos valores sean
mayores a cero. */

#include <stdio.h>

int main(void)
{
    float numero[2];

    for (int i = 0; i < 2; i++)
    {
        printf("Ingrese el valor %d: ", (i+1));
        fflush(stdin);
        scanf("%f", &numero[i]);

        while (numero[i] <= 0)
        {
            printf("\nIngrese un valor mayor que 0: ");
            fflush(stdin);
            scanf("%f", &numero[i]);
        }
    }

    if (numero[0] > numero[1])
        printf("\nEl primer número es mayor: %f > %f\n", numero[0], numero[1]);
    else if (numero[0] < numero[1])
        printf("\nEl segundo número es mayor: %f > %f\n", numero[1], numero[0]);
    else    //Son iguales
        printf("\nAmbos números son iguales: %f = %f\n", numero[0], numero[1]);

    return 0;
}
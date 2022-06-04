/* Modificar el programa 2.7. de manera tal que si el dato ingresado no es positivo,
presente por pantalla el mensaje “Dato NO Válido”. */

#include <stdio.h>

#define PI 3.14

int main(void)
{
    float radio, superficie;

    printf("Ingrese el radio del círculo:\n");
    fflush(stdin);
    scanf("%f", &radio);

    if (radio <= 0)
        printf("Dato no válido\n");
    else
    {
        superficie = PI * radio * radio;     //pi por radio al cuadrado
        printf("La superficio del círculo es: %f\n", superficie);
    }

    return 0;
}
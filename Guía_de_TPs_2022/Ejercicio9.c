/* Desarrollar programa que permita pedir por pantalla la cantidad de personas que
asistieron a un recital y luego la cantidad de entradas vendidas en la preventa.
Identifique si fueron todas las personas al recital o si dejaron de asistir. Valide que la
que la cantidad de entradas vendidas no sean menores a la cantidad de personas que
asistieron. */

#include <stdio.h>

int main(void)
{
    int asistentes, entradas;

    printf("Ingrese la cantidad de asistentes al recital: ");
    fflush(stdin);
    scanf("%d", &asistentes);

    while (asistentes < 0)
    {
        printf("\nIngrese una cantidad de asistentes válida: ");
        fflush(stdin);
        scanf("%d", &asistentes);
    }
    
    printf("\nIngrese la cantidad de entradas vendidas: ");
    fflush(stdin);
    scanf("%d", &entradas);

    while (entradas < asistentes)
    {
        printf("\nError. La cantidad de entradas no puede ser menor que la de asistentes: ");
        fflush(stdin);
        scanf("%d", &entradas);
    }

    if (entradas == asistentes)
        printf("\nTodas las personas asistieron al recital\n");
    else
        printf("\n%d personas no asistieron al recital\n", (entradas - asistentes));

    return 0;
}
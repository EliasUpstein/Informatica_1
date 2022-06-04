/* Desarrollar programa que permita calcular la edad aprox. De una persona. Para ello es
necesario conocer el año actual en curso, junto con el año de nacimiento de dicha
persona y restarlos. Considere validar que el año de nacimiento esté entre 1900 y 2017,
mientras que el año actual se entiende que es 2022. Al terminar imprima el resultado
obtenido */

#include <stdio.h>

int main() 
{
    int ano;

    printf("Introduzca el año de nacimiento: ");
    fflush(stdin);
    scanf("%d", &ano);

    while(2017 < ano || ano < 1900)
    {
        printf("\nPor favor introduzca una fecha válida: "); 
        fflush(stdin);
        scanf("%d", &ano);
    }

    printf("\nLa edad de la persona ingresada es: %d\n", 2022-ano);

    return 0;
}
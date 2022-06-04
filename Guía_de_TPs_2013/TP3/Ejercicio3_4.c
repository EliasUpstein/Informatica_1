/* Escribir una función que simule una mano de truco para la cantidad de jugadores
indicada en su argumento (2, 3, 4 ó 6 jugadores). Sólo se pide repartir las
cartas. */
#include <stdlib.h>
#include <stdio.h>

void repartirCartas(int cantjugadores)
{
    printf("Cartas:\n");

    for (int i = 0; i < (cantjugadores *3); i++)
    {
        printf("%d", ((rand() % 12) + 1));
    }
}
/* Escribir una función que convierta un número que representa una cantidad de
segundos, a su equivalente en horas, minutos y segundos. */

#include <stdio.h>

void dividirTiempo(int segundos);

int main()
{
    int seg;

    printf("Ingrese la cantidad de segundos:\n");
    fflush(stdin);
    scanf("%d", &seg);

    dividirTiempo(seg);

    return 0;
}

void dividirTiempo(int segundos)
{
    int horas, minutos;

    horas = (int) segundos / 3600;     //Calculo las horas totales (si n < 3600 => horas = 0)
    segundos -= 3600 * horas;          //Le resto a n las horas en segundos
    minutos = (int) segundos / 60;     //Calculo la cantidad de minutos 
    segundos -= 60 * minutos;          //Le resto a n los minutos en segundos
                                       //Lo que queda en segundos son los segundos restantes
    printf("Horas: %d\nMinutos: %d\nSegundos:%d\n", horas, minutos, segundos);
}
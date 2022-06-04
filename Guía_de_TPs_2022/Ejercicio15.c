/* Escribí un programa que le solicite al usuario ingresar una fecha formada por 8 números,
donde los primeros dos representan el día, los siguientes dos el mes y los últimos cuatro el año
(DDMMAAAA). Este dato debe guardarse en una variable con tipo int (número entero).
Finalmente, mostrar al usuario la fecha con el formato DD / MM / AAAA. */

#include <stdio.h>

int main(void)
{
    int fecha, dia, mes, ano;

    printf("Ingrese la fecha como DDMMAAAA: ");
    fflush(stdin);
    scanf("%d", &fecha);

    dia = fecha/1000000;
    mes = (fecha/10000) - (dia*100); //DDMM - DD00 (los 0 salen del casteo como entero)
    ano = fecha - (dia*1000000) - (mes*10000); //DDMMAAAA - DD000000 - 00MM0000

    if (dia > 31 || dia < 1 || mes > 12 || mes < 1 || ano > 9999)
        printf("Error, fecha inválida.\n");
    else
        printf("\nFecha ingresada: %d/%d/%d\n", dia, mes, ano);

    return 0;
}
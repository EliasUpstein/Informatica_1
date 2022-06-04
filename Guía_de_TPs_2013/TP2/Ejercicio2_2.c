/* Escribir un programa donde ingresa por teclado una temperatura expresada en
grados Celsius. Calcula su valor en grados Kelvin, y muestra por pantalla el valor
en ºC y su equivalente en ºK. (Recordar ºC=ºK - 273) */

#include <stdio.h>

int main(void)
{
    float gradosC, gradosK;

    printf("Ingrese la temperatura en grados Celsius:\n");
    fflush(stdin);
    scanf("%f", &gradosC);

    gradosK = gradosC + 273;

    printf("Temperatura en grados Celsius: %f\nTemperatura en grados Kelvin: %f\n", gradosC, gradosK);

    return 0;
}
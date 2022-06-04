/* Hacer un programa que involcando una funcion permita ingresar un valor
en farenheit, calcule su equivalente a Celsius

Pasaje:  - F= 9.0/5 +32
         - C= (F-32)*5.0/9

Realizar el programa y las funciones en archivos separados */

#include <stdio.h>
#include "Lib_clase14-05.h"

int main(void)
{
    float tempF;

    printf("Ingrese la temperatura en grados F:\n");
    fflush(stdin);
    scanf("%f", &tempF);

    printf("La temperatura convertida a grados Celsius es: %f°C\n", convertFtoC(tempF));

    return 0;
}
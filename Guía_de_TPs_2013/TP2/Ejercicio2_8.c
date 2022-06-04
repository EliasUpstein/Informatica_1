/* Escribir un programa que calcule el tiempo de muestreo de una señal de 250 Hz.
Para ello se aplica el teorema de Nyquist: N=1/[2*f], en donde N es tiempo de
muestreo en segundos y f (frecuencia en Hz.)) */

#include <stdio.h>

int main(void)
{
    int senal = 250;
    float N = (float) 1/(2*senal);

    printf("Tiempo de muestreo: %f\n", N);

    return 0;
}
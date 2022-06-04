/* Modifique el problema 2.4. para que pueda calcular con esos datos, la resistencia
total de un circuito en paralelo. (Recordar Rp = 1/[1/R1 + 1/R2 + 1/R3]). La
salida deberá aparecer con dos decimales. */

#include <stdio.h>

int main(void)
{
    float r1 = 56;
    float r2 = 33;
    float r3 = 15;

    float rt = (float) 1/((1/r1) + (1/r2) + (1/r3));
    
    printf("La resistencia total del circuito es: %.2f\n", rt);

    return 0;
}
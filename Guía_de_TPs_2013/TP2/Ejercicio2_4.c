/* Suponga que debe escribir un programa para calcular la resistencia total de un
circuito en serie. En tal circuito la resistencia total es la suma de todos los
valores individuales de las resistencias. Suponer que el circuito consiste en una
cantidad de 3 resistores de 56, 33 y 15 Ω respectivamente. */

#include <stdio.h>

int main(void)
{
    int r1 = 56;
    int r2 = 33;
    int r3 = 15;

    int rt = r1 + r2 + r3;
    
    printf("La resistencia total del circuito es: %d\n", rt);

    return 0;
}
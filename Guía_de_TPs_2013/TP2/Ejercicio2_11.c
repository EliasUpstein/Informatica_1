/* Pruebe el algoritmo escrito, usando la siguiente muestra de datos: 47KΩ, 680Ω
y 2,2MΩ. */

#include <stdio.h>

int main(void)
{
    int r1 = 47000;
    int r2 = 680;
    int r3 = 2200000;

    int rt = r1 + r2 + r3;
    
    printf("La resistencia total del circuito es: %d\n", rt);

    return 0;
}
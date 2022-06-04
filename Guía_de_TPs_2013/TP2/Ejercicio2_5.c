/* Con los datos del problema 2.4. Haga un programa que calcule el promedio de
las resistencias. */

#include <stdio.h>

int main(void)
{
    int r1 = 56;
    int r2 = 33;
    int r3 = 15;

    float promedio = (float) (r1 + r2 + r3) / 3;
    
    printf("El promedio de los resistores del circuito es: %f\n", promedio);

    return 0;
}
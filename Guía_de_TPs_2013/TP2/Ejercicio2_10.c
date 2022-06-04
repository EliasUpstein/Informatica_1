/* Modifique el problema 2.4. para que pueda calcular la resistencia total de un
circuito en serie con los siguientes datos. El circuito consiste en una cantidad de
7 resistores de 56 Ω, 5 de 33 Ω y 9 de 15 Ω.
Responda además, las siguientes preguntas:
a) ¿Cuántas salidas requiere este problema de programación?
b) ¿Cuántos datos de entrada tiene el problema? */ 

#include <stdio.h>

int main(void)
{
    int r1 = 56;
    int r2 = 33;
    int r3 = 15;

    int rt = (7 * r1) + (5 * r2) + (9 * r3);
    
    printf("La resistencia total del circuito es: %d\n", rt);

    return 0;
}

//a)Este programa posee una única salida, la resistencia total
//b)El problema posee 3 datos de entrada, que son multiplicados por la cantidad de veces que aparecen
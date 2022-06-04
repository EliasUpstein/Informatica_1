/* Escribir una función que simule el tiro de un dado. */

#include <stdlib.h>

int dado()
{
    return ((rand() % 6) + 1);       //Resto de 0 a 5, sumando uno de 1 a 6
}
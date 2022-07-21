#include <stdio.h>
#include <ctype.h>

int main()
{
    int numero = 2;
    char ascii = '2';

    printf("La variable número es %d\n", isdigit(numero));
    printf("La variable número casteada es %d\n", isdigit((char) numero));
    printf("La variable ascii es %d\n", isdigit(ascii));

    return 0;
}
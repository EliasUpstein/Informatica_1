/*Escribir una función que reciba como argumento puntero a char, la asuma como
una secuencia en ASCII terminada en '\0' (NULL) y devuelva la secuencia
invertida.
void string_reverse (char *) ;*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20

void string_reverse (char *c)
{
    for (int i = strlen(c)-1; i >= 0; i--)
    {
        printf("%c", c[i]);
    }
    printf("\n");
}

int main()
{
    char str[N];

    printf("Ingrese secuencia:\n");
    fflush(stdin);
    fgets(str, N, stdin);

    string_reverse(str);

    system("pause");
    return 0;
}
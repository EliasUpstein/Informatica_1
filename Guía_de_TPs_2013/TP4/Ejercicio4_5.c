/*Escribir una función que reciba como argumento puntero a una secuencia de
bytes, la asuma como una secuencia en ASCII terminada en '\0' (NULL), calcule
su longitud y la retorne de acuerdo al siguiente prototipo:
int my_strlen (const char *) ;*/

#include <stdio.h>
#include <stdlib.h>

#define N 20

int my_strlen(const char *);

int main()
{
    char str[N];

    printf("Ingrese secuencia:\n");
    fflush(stdin);
    fgets(str, N, stdin);

    printf("Longitud del String: %d\n", my_strlen(str));

    system("pause");
    return 0;
}

int my_strlen(const char *string)
{
    int i = 0;

    while (string[i] != NULL)   //Mientras el caracter sea distinto del fin del string
        i++;
    
    return i;   //Contabiliza el \n
}
/* Escribir un programa que lea una cadena de caracteres ingresada por stdin y la
imprima por stdout. Para ello utilizar las funciones de biblioteca scanf() con
formato "%s", gets() y fgets(). Comparar los resultados y explicar la
conveniencia de utilizar cada una de ellas, y bajo qué circunstancias. */

#include <stdio.h>
#include <string.h>

#define N 50

int main()
{
    char texto[N];

    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%s", texto);

    printf("%s", texto);

    fflush(stdin);
    setbuf(stdin, NULL);
    gets(texto);

    puts("texto");

    fflush(stdin);
    setbuf(stdin, NULL);
    fgets(texto, N, stdin);

    fputs(texto, stdout);

    return 0;
}
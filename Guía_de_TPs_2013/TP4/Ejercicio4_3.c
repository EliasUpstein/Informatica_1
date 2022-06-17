/* Escribir una función que determine si una a una secuencia de bytes recibida
como parámetro está vacía o no. A tal fin, la asumirá como una secuencia en
ASCII terminada en '\0' (NULL). El tipo de retorno debe ser bool, conforme al
siguiente prototipo:
bool emptyString (const char *) ; */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define N 20

bool emptyString (const char *); 

int main()
{
    char str[N];

    printf("Ingrese secuencia:\n");
    fflush(stdin);
    fgets(str, N, stdin);

    printf("%s\n", emptyString(str)? "True":"False");

    system("pause");
    return 0;
}

//Si la cadena está vacía su primer caracter sera el NULL
bool emptyString(const char *string)
{                  //'\0'
    if (string[0] == NULL || string[0] == '\n')
        return true;
    else
        return false;
}
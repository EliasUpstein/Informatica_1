/*Escribir una función que convierta a minúsculas una cadena de caracteres
recibida como argumento.
Prototipo: void strlwr (char *); */

#include <stdio.h>
#include <string.h>
#define N 20

void my_strlwr(char *s);

int main()
{
    char s[N];

    printf("Introduzca la cadena de caracteres: \n");
    fflush(stdin);
    fgets(s,N,stdin);

    my_strlwr(s);
    printf("El string en minúsculas es:\n");
    fputs(s,stdout);

    return 0;
}

void my_strlwr(char *s)
{
    for(int i=0; i < strlen(s); i++)
    {
        if (s[i]>='A' && s[i]<='Z')  //Si el caractér está entre el abecedario mayúsculo del ASCII
            s[i] += 32;          //Se desplaza el mismo caracter 32 posiciones adelante (minúscula)(ver tabla)
    }
}
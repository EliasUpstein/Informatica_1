/* Escribir una función que convierta a mayúsculas una cadena de caracteres
recibida como argumento.
Prototipo: void strupr(char *); */

#include <stdio.h>
#include <string.h>
#define N 20

void my_strupr(char *s);

int main()
{
    char s[N];

    printf("Introduzca la cadena de caracteres: \n");
    fflush(stdin);
    fgets(s,N,stdin);

    my_strupr(s);
    printf("El string en mayúsculas es:\n");
    fputs(s,stdout);

    return 0;
}

void my_strupr(char *s)
{
    for(int i=0; i < strlen(s); i++)
    {
        if (s[i]>='a' && s[i]<='z')  //Si el caractér está entre el abecedario minúsculo del ASCII
            s[i] -= 32;              //Se desplaza el mismo caracter 32 posiciones atras (mayúscula)(ver tabla)
    }
}
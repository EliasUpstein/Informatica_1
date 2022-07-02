/*Escribir una función que reciba una cadena de caracteres y determine si es un
palíndromo (capicúa) o no, retornando el resultado por el nombre. Considerar el
caso de longitudes de cadena par e impar.
Prototipo: bool es_palindromo (const char *) ; */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 20

bool es_palindromo(const char *);

int main(){

    char s[N];
    
    printf("Ingrese palabra:\n");
    fflush(stdin);
    fgets(s, N, stdin);

    if (es_palindromo(s) == true)
        printf("La palabra es palindromo\n");
    else
        printf("La palabra no es palindromo\n");

    return 0;
}

bool es_palindromo(const char *s)
{
    int i = 0;
    //Si alguna de las letras es distinta devuelve 0
    //Compara el caracter contra el del final(menos el \n) (-2 porque es base 0 + '\n') restado el valor de i
    for (i = 0; i < strlen(s)-1; i++)
    {
        if (s[i] != s[strlen(s)-2-i])
            return false;
    }
    return true;
}   
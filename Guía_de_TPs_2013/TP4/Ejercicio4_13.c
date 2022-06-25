/* Escribir una función que reciba una cadena de caracteres como argumento, y la
convierta a minúsculas o mayúsculas, de acuerdo a un argumento "format", cuyo
tipo es case, un tipo enumerativo compuesto por los tokens UPPERCASE y
LOWERCASE:
typedef enum { UPPERCASE, LOWERCASE } case ;
Prototipo de la función pedida: void change_case (char * , case ) ;
Nota: Implemente esta función invocando a las dos funciones de los ejercicios previos. */

#include <stdio.h>
#include <string.h>
#define N 20

typedef enum {UPPERCASE, LOWERCASE} caso;       //case es palabra clave

void change_case (char *s, caso format);
void my_strupr(char *s);
void my_strlwr(char *s);

int main()
{
    char s[N];
    caso formato;
    int seleccion = 0;

    printf("Introduzca la cadena de caracteres: \n");
    fflush(stdin);
    fgets(s,N,stdin);

    printf("Seleccione operación a realizar:\n1)Convertir a mayúsculas\n2)Convertir a minúsculas\n");
    fflush(stdin);
    scanf("%d", &seleccion);

    while (seleccion != 1 && seleccion != 2)
    {
        printf("Operación inválida. Reingrese operación a realizar:\n");
        fflush(stdin);
        scanf("%d", &seleccion);
    }

    if (seleccion == 1)
        formato = UPPERCASE;
    else if (seleccion == 2)
        formato = LOWERCASE;

    change_case(s, formato);
    printf("El string convertido es:\n");
    fputs(s,stdout);
    printf("\n");

    return 0;
}

void change_case (char *s, caso format)
{
    if (format == UPPERCASE)
        my_strupr(s);
    else if (format == LOWERCASE)
        my_strlwr(s);
}

void my_strupr(char *s)
{
    for(int i=0; i < strlen(s); i++)
    {
        if (s[i]>='a' && s[i]<='z')  //Si el caractér está entre el abecedario minúsculo del ASCII
            s[i] -= 32;              //Se desplaza el mismo caracter 32 posiciones atras (mayúscula)(ver tabla)
    }
}

void my_strlwr(char *s)
{
    for(int i=0; i < strlen(s); i++)
    {
        if (s[i]>='A' && s[i]<='Z')  //Si el caractér está entre el abecedario mayúsculo del ASCII
            s[i] += 32;          //Se desplaza el mismo caracter 32 posiciones adelante (minúscula)(ver tabla)
    }
}
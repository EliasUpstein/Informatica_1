/* Escribir una función que reciba como argumentos dos punteros a char “t” y “s”,
que apunta cada uno a una secuencia de bytes terminados en '/0', y realice la
concatenación de la secuencia “s” a continuación de la secuencia “t”, terminando
la secuencia de bytes resultante con el caracter '\0' (Función strcat() de la
biblioteca <string.h>).
El prototipo de la función pedida es:
void my_strcat (char *t, const char *s) ;
Nota: ¿Donde deben tomarse los recaudos para que el puntero destino posea la memoria necesaria?. Si no es
en su función especifique donde y como se debe salvar esta situación, mediante un comentario en el
encabezado de su programa fuente. */

#include <stdio.h>
#include <string.h>

#define N 20
#define M 25

void my_strcat (char *t, const char *s);

int main()
{
    char s[N];
    char t[M];

    printf("Ingrese primer secuencia:\n");
    fflush(stdin);
    fgets(s, N, stdin);

    printf("Ingrese secuencia secuencia:\n");
    fflush(stdin);
    fgets(t, N, stdin);

    my_strcat(t, s);

    printf("El valor de s es:\n");
    fputs(s, stdout);
    printf("El nuevo valor de t es:\n");
    fputs(t, stdout);

    return 0;
}

//Probar después de corregir el 6
void my_strcat (char *t, const char *s)
{   
    // //Si el largo del vector apuntado es menor a la longitud de la cadena t + la cadena s
    // if (sizeof(t) < (strlen(t) + strlen(s)))
    //     printf("Los Strings tienen diferente tamaño\n");
    // else
    // {
        int ta = strlen(t);
        int sa = strlen(s);
        char a = s[3];

        for (int i = strlen(t)-1; i < strlen(s) + strlen(t); i++)  //Copia sobreescribiendo el \0 de t (en strlen(t))
            t[i] = s[i-strlen(t)];      //Guardo el valor desplazado, 0-1-2-3-etc
    // }
}
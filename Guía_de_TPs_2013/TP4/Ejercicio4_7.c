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

//No se puede conocer el tamaño del vector en la fucnion ya que es pasado como puntero
//Para evitar el error se deben declarar ambos vectores de igual longitud o modificar el prototipo para
//pasarle a la función el tamaño del vector


#include <stdio.h>
#include <string.h>

#define N 20
#define M 25

void my_strcat (char *t, const char *s);
int my_strlen(const char *);

int main()
{
    char s[N];
    char t[M];

    printf("Ingrese secuencia:\n");
    fflush(stdin);
    fgets(s, N, stdin);

    my_strcat(t, s);

    printf("El valor de s es:\n");
    fputs(s, stdout);
    printf("El nuevo valor de t es:\n");
    fputs(t, stdout);

    return 0;
}

void my_strcat (char *t, const char *s)
{
    int aux = my_strlen(t);
    //Si el largo del vector apuntado es menor a la longitud de la cadena t + la cadena s
    // if (sizeof(t) < (strlen(t) + strlen(s)))
    //     printf("Los Strings tienen diferente tamaño\n");
    // else
    // {
        for (int i = aux; i < my_strlen(s); i++)  //Copia sobreescribiendo el \0 de t (en strlen(t))
            t[i] = s[i-aux];      //Guardo el valor desplazado, 0-1-2-3-etc
    // }
}

int my_strlen(const char *string)
{
    int i = 0;

    while (string[i] != NULL)   //Mientras el caracter sea distinto del fin del string
        i++;
    
    return i;   //Contabiliza el \n
}


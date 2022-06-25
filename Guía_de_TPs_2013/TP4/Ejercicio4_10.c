/* Escribir una función que reciba como argumento dos punteros a caracter “t” y
“s”, y una variable entera "n", y copie los primeros "n" caracteres de la cadena
“s” sobre la cadena “t”, sin terminar la secuencia resultante con el caracter nulo.
(Función strncpy () de la biblioteca <string.h>).
El prototipo de la función pedida es:
int my_strncpy (char *t, const char *s, int n) ;
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

char *my_strncpy (char *t, const char *s, int n);

int main()
{
    char s[N];
    char t[M];
    int n = 0;

    printf("Ingrese secuencia:\n");
    fflush(stdin);
    fgets(s, N, stdin);

    printf("Ingrese la cantidad de caracteres a copiar\n");
    fflush(stdin);
    scanf("%d", &n);

    //Si se quieren copiar más caracteres que los que se tienen o más que los que acepta el vector
    while (n > strlen(s)-1 || n > sizeof(t))
    {
        printf("Cantidad inválida. Ingrese un valor menor a la cantidad de caracteres:\n");
        fflush(stdin);
        scanf("%d", &n);
    }

    my_strncpy(t, s, n);

    printf("El valor de s es:\n");
    fputs(s, stdout);
    printf("El nuevo valor de t es:\n");
    fputs(t, stdout);
    printf("\n");

    return 0;
}

char *my_strncpy (char *t, const char *s, int n)
{
    for (int i = 0; i < n; i++)            //Copia hasta que i llega a n
        t[i] = s[i];

    return t;                              //Devuelve el puntero a vector
}
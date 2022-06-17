/* Escribir una función que reciba un puntero a caracter "s" y un puntero a caracter
"t", y copie la “s” en “t”, terminando la cadena con el caracter '\0' (Función
strcpy () de la biblioteca <string.h>). El prototipo de la función pedida es:
void my_strcpy (char *t, const char *s);
Nota: ¿Donde deben tomarse los recaudos para que el puntero destino posea la memoria necesaria?. Si no es
en su función especifique donde y como se debe salvar esta situación, mediante un comentario en el
encabezado de su programa fuente. */

//No se puede conocer el tamaño del vector en la fucnion ya que es pasado como puntero
//Para evitar el error se deben declarar ambos vectores de igual longitud o modificar el prototipo para
//pasarle a la función el tamaño del vector

#include <stdio.h>

#define N 20
#define M 25

void my_strcpy (char *t, const char *s);

int main()
{
    char s[N];
    char t[M];

    printf("Ingrese secuencia:\n");
    fflush(stdin);
    fgets(s, N, stdin);

    // printf("%d\n", sizeof(s));
    // printf("%d\n", sizeof(t));

    my_strcpy(t, s);

    printf("El valor de s es:\n");
    fputs(s, stdout);
    printf("El nuevo valor de t es:\n");
    fputs(t, stdout);

    return 0;
}

void my_strcpy (char *t, const char *s)
{
    //Devuelve el sizeof del puntero, no del vector
    // printf("%d\n", sizeof(s));
    // printf("%d\n", sizeof(t));

    // char se[] = s;
    // char te[] = t;

    // if (sizeof(t) != sizeof(s))
    //     printf("Los Strings tienen diferente tamaño\n");
    // else
    // {
        for (int i = 0; i != NULL; i++)     //Copia toda la cadena
            t[i] = s[i];
    //}
}

/* Error:  (Presentacion clase 6, diapositiva: columna 1 fila 7)
char string[32] = "hello, world";
char *ptr = string;

sizeof (string)
Devuelve: 32
sizeof (ptr) // Si estamos en una máquina de 64bits (con punteros de 8 bytes)
Devuelve: 8 */
/* Escribir un programa que genere un archivo de texto con los caracteres que el
operador ingrese por stdin.
Sugerencia: Revise que secuencia de teclas representa EOF para stdin. */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define N 100

int main()
{
    char texto[N][N];
    int i = 0, j = 0;

    while (texto[i][j])
    {
        fflush(stdin);
        setbuf(stdin, NULL);
        fgets(texto[i], N, stdin);

        
    }
    

    return 0;
}

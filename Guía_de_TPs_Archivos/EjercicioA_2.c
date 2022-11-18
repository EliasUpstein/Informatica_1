/* Realizar un programa que indique el tamaño de un archivo. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 30

int main()
{
    int fd;
    char nombre[N];

    // Ingreso del nombre de archivo
    printf("Ingrese el nombre del archivo: \n");
    fflush(stdin);
    setbuf(stdin, NULL);
    fgets(nombre, N, stdin);
    nombre[strlen(nombre) - 1] = '\0';

    // Validación de la extensión
    if (strstr(nombre, ".txt") == NULL)
        strcat(nombre, ".txt");

    if ((fd = open(nombre, O_RDONLY)) != -1)
    {
        printf("Tamaño del archivo: %d\n", (int)lseek(fd, 0, SEEK_END));
        close(fd);
    }
    else
        printf("Error abriendo el archivo\n");

    return 0;
}

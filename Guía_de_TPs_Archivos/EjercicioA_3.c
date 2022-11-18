/* Realizar un programa que copie un archivo(usando malloc). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 50

int main()
{
    int fd, tam, aux;
    char nombre[N];
    char *contenido;

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
        tam = lseek(fd, 0, SEEK_END);
        lseek(fd, 0, SEEK_SET); // Reposiciona el cursor
        contenido = (char *)malloc(sizeof(char) * tam);
        memset(contenido, '\0', sizeof(contenido));

        if ((aux = read(fd, contenido, tam)) != 0)
        {
            close(fd);
            strcpy(&nombre[strlen(nombre)-4], "_copia.txt");
            fd = open(nombre, O_CREAT | O_WRONLY);
            if((aux = write(fd, contenido, tam)) != 0)
                printf("¡Copia completa!\n");
            else
                printf("Error copiando el archivo\n");

            close(fd);
        }
    }
    else
        printf("Error abriendo el archivo\n");

    return 0;
}
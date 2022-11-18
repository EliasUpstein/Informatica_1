/* Realizar un programa que cuente cuantos renglones el archivo tiene. */

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
    int fd, count=1, aux;
    char nombre[N];
    char caracter[2];

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
        while ((aux = read(fd, caracter, 1)) != 0)
        {
            if(caracter[0] == '\n') count++;
        }
        printf("El archivo contiene %d renglones\n", count);

        close(fd);   
    }
    else
        printf("Error abriendo el archivo\n");

    return 0;
}
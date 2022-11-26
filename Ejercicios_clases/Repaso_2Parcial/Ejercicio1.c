/* Escribir una función llamada load_filenames() que tome un nombre de archivo (como cadena), lo abra y devuelva el
string que toma del archivo.
El archivo tendrá el siguiente formato: ARCHIVOS=arch01.txt,arch02.txt,...
No se sabe cuantos archivos vienen, pero a los fines de esta función es una cadena de máximo 1024 caracteres */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

char *load_filenames(char* file)
{
    int fd, aux = 1;
    char contenido[1024];

    if(fd = open(file, O_RDONLY) != -1)
    {
        for (int i = 0; i < 1024 && aux != 0; i++)
            aux = read(fd, &contenido[i], 1);

        close(fd);
    }

    return contenido;
}
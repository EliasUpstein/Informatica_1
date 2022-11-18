/* Realizar un programa que levante de un archivo binario y lo lleve a un array de
estructuras. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 5

struct persona
{
    char nombre[30];
    int edad;
};


int main()
{
    int fd;
    struct persona gente[N];
    
    fd = open("estructuras.dat", O_RDONLY);

    for (int i = 0; i < N; i++)
    {
        read(fd, &gente[i], sizeof(struct persona));
    }
    
    close(fd);

    return 0;
}
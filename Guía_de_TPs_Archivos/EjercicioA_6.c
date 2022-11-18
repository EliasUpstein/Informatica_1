/* Realizar un programa que vuelque a un archivo binario el contenido de un
array de estructuras. */

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

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre de la persona:\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        fgets(gente[i].nombre, N, stdin);
        gente[i].nombre[strlen(gente[i].nombre) - 1] = '\0';

        printf("Ingrese el nombre de la persona:\n");
        fflush(stdin);
        setbuf(stdin, NULL);
        scanf("%d", &gente[i].edad);
    }
    
    fd = open("estructuras.dat", O_CREAT);

    for (int i = 0; i < N; i++)
    {
        write(fd, &gente[i], sizeof(struct persona));
    }
    
    close(fd);

    return 0;
}

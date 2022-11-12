#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd = open("diodo.txt", O_RDONLY);
    int tam;

    tam = lseek(fd, 0 , SEEK_END);

    printf("Tamaño del archivo: %d\n", tam);

    return 0;
}

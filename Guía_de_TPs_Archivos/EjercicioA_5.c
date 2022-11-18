/* Realizar un programa que genere un archivo txt con la tabla de ASCII. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[10];

    fd = open("ascii.txt", O_CREAT | O_WRONLY);

    for (int i = 0; i < 256; i++)
    {
        sprintf(buf, "%d - %c\n", i, i);
        write(fd, buf, strlen(buf));
    }
    
    close(fd);

    return 0;
}
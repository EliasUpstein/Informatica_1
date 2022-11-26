/* Realizar una función TransferFilesData() que recibirá un entero representando un socket, un vector de string y
un entero con su tamaño. La función deberá abrir cada archivo dentro del vector y transferir su contenido. Una vez
transferidos todos los archivos finalizará. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void TransferFilesData(int sockfd, char* strings[], int tam)
{
    int fd, aux;
    char c[2];

    for (int i = 0; i < tam; i++)
    {
        if((fd = open(string[i], O_RDONLY)) != -1)
        {
            while((aux = read(fd, c, 1)) != 0)
                write(sockfd, c, 1);
            
            close(fd);
        }
    }
}
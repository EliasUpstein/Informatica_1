/* Realizar un conjunto de programas (1 cliente, 1 servidor), que permita el envío
recepción y visualización del contenido de un archivo, se sugiere enviar una
estructura que tenga tamaño, nombre y los bytes del archivo
transmitido/recibido. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sock-lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

struct archivo
{
    char nombre[30];
    int tamano;
};

int main(void)
{
    int sockfd, newsockfd, fd;
    struct archivo datos;
    struct sockaddr_in my_addr;

    sockfd = Open_conection(&my_addr);
    newsockfd = Aceptar_pedidos(sockfd);

    read(newsockfd, &datos, sizeof(datos));

    char buff[datos.tamano];

    read(newsockfd, buff, datos.tamano);

    printf("%s\n", buff);

    fd = open("prueba2.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
    write(fd, buff, datos.tamano);

    close(fd);
    close(newsockfd);
    close(sockfd);
    
    return 0;
}
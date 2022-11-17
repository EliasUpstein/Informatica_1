/* Realizar un conjunto de programas (1 cliente, 1 servidor), que permita el envío
recepción procesamiento y respuesta del contenido de un archivo.
a. El cliente le enviará un archivo de texto ascii al servidor.
b. El servidor, lo recibe, pasa a mayúsculas todas las letras, y le devuelve
el archivo.*/

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

int main(void)
{
    int sockfd, newsockfd, tamano;
    struct sockaddr_in my_addr;
    char *buff;

    sockfd = Open_conection(&my_addr);
    newsockfd = Aceptar_pedidos(sockfd);

    read(newsockfd, &tamano, sizeof(tamano));

    buff = (char *)calloc(tamano, sizeof(char));

    read(newsockfd, buff, tamano);

    for (int i = 0; i < tamano; i++)
    {
        buff[i] = toupper(buff[i]);
    }
    
    write(newsockfd, buff, tamano);

    close(newsockfd);
    close(sockfd);
    free(buff);
    
    return 0;
}
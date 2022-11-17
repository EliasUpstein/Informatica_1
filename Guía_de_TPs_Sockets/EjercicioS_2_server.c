/* Realizar un conjunto de programas (1 cliente, 1 servidor), que permita el envío
recepción y visualización de una estructura del tipo
struct persona {
    char nombre [30]
    int edad;
}; */

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

struct persona
{
    char nombre[30];
    int edad;
};

int main(void)
{
    int sockfd, aux, newsockfd;
    struct sockaddr_in my_addr;
    struct persona datos;

    // Establecimiento de la conexión
    sockfd = Open_conection(&my_addr);
    newsockfd = Aceptar_pedidos(sockfd);

    // Recepción de datos
    aux = read(newsockfd, &datos, sizeof(datos));

    // Impresión de la información recibida
    if (aux != 0)
    {
        printf("Nombre: ");
        fputs(datos.nombre, stdout);
        printf("\n");

        printf("Edad: %d\n", datos.edad);
    }

    // Cierre del socket
    close(newsockfd);
    close(sockfd);

    return 0;
}
/* Realizar 1 programa cliente, que dada una IPv4, intente realizar conexiones
contra todos los puertos TCP (si se pudiera conectar a un puerto, se cerrará la
conexión sin realizar nada), indicando en cual pudo conectarse y en cual no. */

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

#define PORTS_TCP 65536

//Copia modificada de la función conectar de la librería
int main()
{
    int sockfd;
    struct hostent *he;            /* Se utiliza para convertir el nombre del host a su dirección IP */
    struct sockaddr_in their_addr; /* dirección del server donde se conectará */

    /* Convertimos el nombre del host a su dirección IP */
    if ((he = gethostbyname("127.0.0.1")) == NULL)
    {
        herror("Error en gethostbyname");
        exit(1);
    }

    /* Creamos el socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error en creación de socket");
        exit(1);
    }

    /* Establecemos their_addr con la direccion del server */
    their_addr.sin_family = AF_INET;
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    bzero(&(their_addr.sin_zero), 8);

    for (int port = 0; port < PORTS_TCP; port++)
    {
        their_addr.sin_port = htons(port);

        /* Intentamos conectarnos con el servidor */
        if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
            printf("PUERTO %d: SIN CONEXIÓN\n", port);
        else
        {
            printf("PUERTO %d: CONEXIÓN EXITOSA\n", port);
            sleep(2);   //Tiempo de visualización
        }

    }

    close(sockfd);

    return 0;
}

// char args[3][12] = {{},{"127.0.0.1"}, {}};

// for (port = 0; port < PORTS_TCP; port++)
    // {
    //     sprintf(args[3], "%d", port);
    //     sockfd = conectar(3, args);

    //     if (sockfd != 0)
    //     {
    //         printf("Puerto %d: CONEXIÓN ESTABLECIDA\n", port);
    //         break;
    //     }
    //     else
    //         printf("Puerto %d: SIN CONEXIÓN\n", port);
    // }
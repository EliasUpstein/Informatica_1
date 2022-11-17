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

int main(int argc, char *argv[])
{
    int sockfd;
    struct persona datos;

    // Conexión con el servidor
    sockfd = conectar(argc, argv);

    // Ingreso de datos
    printf("Ingrese el nombre de la persona:\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    fgets(datos.nombre, 30, stdin);

    printf("Ingrese la edad:\n");
    fflush(stdin);
    setbuf(stdin, NULL);
    scanf("%d", &datos.edad);

    // Escritura de la estructura
    write(sockfd, &datos, sizeof(datos));

    // Cierre del socket
    close(sockfd);

    return 0;
}
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

int main(int argc, char *argv[])
{
    if (argc < 3)
        printf("Introduzca <IP> <PUERTO> <Archivo.txt> por linea de comando\nCERRANDO SESION\n");
    else
    {
        int sockfd, fd;
        char *buff;
        struct archivo datos;

        sockfd = conectar(argc, argv); // Establece la conexión

        fd = open(argv[3], O_RDONLY); // Apertura del archivo

        strcpy(datos.nombre, argv[3]);
        datos.tamano = lseek(fd, 0, SEEK_END); // Cálculo del tamaño del archivo

        write(sockfd, &datos, sizeof(datos)); // Envía estructura de datos

        lseek(fd, 0, SEEK_SET); //Reposiciono el cursor
        buff = (char*) calloc(datos.tamano, sizeof(char));
        
        read(fd, buff, datos.tamano); // Lee el archivo
        write(sockfd, buff, datos.tamano); // Envía contenido del archivo

        close(fd);
        close(sockfd);
        free(buff);
    }
    return 0;
}
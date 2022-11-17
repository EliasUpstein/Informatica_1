/* Realizar un conjunto de programas (1 cliente, 1 servidor), que permita el envío
recepción procesamiento y respuesta del contenido de un archivo.
a. El cliente le enviará un archivo de texto ascii al servidor.
b. El servidor, lo recibe, pasa a mayúsculas todas las letras, y le devuelve
el archivo. */

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

int main(int argc, char *argv[])
{
    if (argc < 3)
        printf("Introduzca <IP> <PUERTO> <Archivo.txt> por linea de comando\nCERRANDO SESION\n");
    else
    {
        int sockfd, fd, tamano;
        char *buff;

        sockfd = conectar(argc, argv); // Establece la conexión

        fd = open(argv[3], O_RDONLY);    // Apertura del archivo
        tamano = lseek(fd, 0, SEEK_END); // Cálculo del tamaño del archivo

        write(sockfd, &tamano, sizeof(tamano)); // Envía estructura de datos

        lseek(fd, 0, SEEK_SET); // Reposiciono el cursor
        buff = (char *)calloc(tamano, sizeof(char));

        read(fd, buff, tamano);      // Lee el archivo
        write(sockfd, buff, tamano); // Envía contenido del archivo

        close(fd);

        fd = open("mayusc.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
        read(sockfd, buff, tamano);
        write(fd, buff, tamano);

        close(fd);
        close(sockfd);
        free(buff);
    }
    return 0;
}
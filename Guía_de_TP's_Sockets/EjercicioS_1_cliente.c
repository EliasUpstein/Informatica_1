/* Realizar un conjunto de programas (1 cliente, 1 servidor), que permita el envío
, recepción y visualización de mensajes del tipo chat de 1 usuario contra 1
usuario.(los usuarios se turnaran para transmitir o recibir secuencialmente) */

#include "sock-lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define N 1000

int main (int argc, char*argv[])
{
    int sockfd, flag=1, i;
    char buff[N];
    char lectura[N];
    sockfd = conectar(argc,argv);
    printf("Introduzca un mensaje para el servidor:\n");
    do
    {
        printf("Cliente: ");
        setbufstdin,NULL);
        fgets(buff,N,stdin);
        for(i=0, i<strlen(buff)-1, i++)
        {
            toupper(buff[i]);
        }
        if(strstr("CHAU",buff) != NULL)
        {
            flag = 0;
        }
        write(sockfd, buff, strlen(buff)-1);
        if(flag)
        {
            while(read(sockfd, lectura, N) == 0) {}    
            printf("\nServer:%s\n",lectura); 
        }
    } while (flag);
    close(sockfd);
}
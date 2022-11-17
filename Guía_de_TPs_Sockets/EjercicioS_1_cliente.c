/* Realizar un conjunto de programas (1 cliente, 1 servidor), que permita el envío
, recepción y visualización de mensajes del tipo chat de 1 usuario contra 1
usuario.(los usuarios se turnaran para transmitir o recibir secuencialmente) */

#include "sock-lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define N 6000

int main (int argc, char*argv[])
{
    int sockfd, flag=1, i;
    char buff[N];

    sockfd = conectar(argc,argv);

    printf("Introduzca un mensaje para el servidor:\n");

    while (flag)
    {
        printf("Cliente: ");
        setbuf(stdin,NULL);
        memset(buff, '\0', sizeof(buff));
        fgets(buff,N,stdin);

        for(i=0; i<strlen(buff)-1; i++)
        {
            buff[i] = toupper(buff[i]);
        }

        //Encontró la palabra "CHAU" en el mensaje
        if(strstr(buff,"CHAU") != NULL)
            flag = 0;
        
        write(sockfd, buff, strlen(buff)-1);
        
        if(flag)
        {
            memset(buff, '\0', sizeof(buff));
            while(read(sockfd, buff, N) == 0) {}    
            printf("\nServer:%s\n",buff); 
        }
    }

    close(sockfd);

    return 0;
}
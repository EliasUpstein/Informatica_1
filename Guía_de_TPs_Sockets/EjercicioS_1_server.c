/* Realizar un conjunto de programas (1 cliente, 1 servidor), que permita el envío
, recepción y visualización de mensajes del tipo chat de 1 usuario contra 1
usuario.(los usuarios se turnaran para transmitir o recibir secuencialmente) */

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

#define N 6000

int main(void)
{
	int sockfd, aux, newsockfd, flag = 1;
	char buff[N];
	struct sockaddr_in my_addr;

	sockfd = Open_conection (&my_addr);
	newsockfd = Aceptar_pedidos (sockfd);

    while (flag)
    {
        aux = read(newsockfd, buff, N-1);

        if(aux != 0)
        {
            printf("Cliente: ");
            fputs(buff, stdout);
            printf("\n");

            //Sale del chat cuando el mensaje es unicamente "CHAU"
            if (strstr(buff,"CHAU") != NULL)
                flag = 0;
            else
            {
                printf("Server: ");
                fflush(stdin);
                setbuf(stdin, NULL);
                memset(buff, '\0', sizeof(buff));
                fgets(buff, N, stdin);
                printf("\n");

                for(int i=0; i<strlen(buff)-1; i++)
                {
                    buff[i] = toupper(buff[i]);
                }

                aux = write(newsockfd,buff,strlen(buff)-1);
                memset(buff, '\0', sizeof(buff));
            }
        }
    }
	
	close(newsockfd);
	close(sockfd);

	return 0;
}
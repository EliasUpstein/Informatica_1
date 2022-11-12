#include <stdio.h>
#include <string.h>
#include "sock-lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <pthread.h>

#define N 6000
#define CANT_CLIENTES 2

pthread_t tid[CANT_CLIENTES];	// Vector con los descriptores de cada thread
int sockfd;

void *charlaCliente()
{
	pthread_t id = pthread_self();

	if(pthread_equal(id,tid[0])) 
	{
		int fd1, newsockfd1, aux1, n1;
		char buff1[N];
		char nombre1[N];

        newsockfd1 = Aceptar_pedidos (sockfd);

		aux1 = read(newsockfd1, nombre1, N-1);
		strcat(nombre1, ".txt");

		aux1 = read(newsockfd1, buff1, N-1);
		if(aux1 != 0)
		{
			fd1 = open(nombre1, O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
			while(aux1 != 0)
			{
				n1 = write(fd1,buff1,aux1);
				aux1 = read(newsockfd1, buff1, N-1);
			}
		}
		close(fd1);
		close(newsockfd1);
    } 
	else 
	{
        int fd2, newsockfd2, aux2, n2;
		char buff2[N];
		char nombre2[N];

        newsockfd2 = Aceptar_pedidos (sockfd);

		aux2 = read(newsockfd2, nombre2, N-1);
		strcat(nombre2, ".txt");

		aux2 = read(newsockfd2, buff2, N-1);
		if(aux2 != 0)
		{
			fd2 = open(nombre2, O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
			while(aux2 != 0)
			{
				n2 = write(fd2,buff2,aux2);
				aux2 = read(newsockfd2, buff2, N-1);
			}
		}
		close(fd2);
		close(newsockfd2);
    }

    return NULL;
}


int main(void)
{
	struct sockaddr_in my_addr;
	sockfd = Open_conection (&my_addr);

	int *ptr[2];	// Puntero a los valores de retorno del thread

	for (int i = 0; i < CANT_CLIENTES; i++)
	{
		int err = pthread_create(&(tid[i]), NULL, &charlaCliente, NULL);
        if (err != 0)
            printf("\nError creando el thread: [%s]", strerror(err));
	}

	pthread_join(tid[0], (void**)&(ptr[0]));
    pthread_join(tid[1], (void**)&(ptr[1]));
	
	close(sockfd);

	return 0;
}

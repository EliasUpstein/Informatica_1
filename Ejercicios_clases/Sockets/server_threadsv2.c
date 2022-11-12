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
int fd[CANT_CLIENTES];
char nombres[CANT_CLIENTES][N];
char buff[CANT_CLIENTES][N];
int aux[CANT_CLIENTES];
int n[CANT_CLIENTES];

void *charlaCliente(void* argumentos)
{
    int *args = (int *) argumentos;

    aux[args[0]] = read(args[1], nombres[args[0]], N-1);
    strcat(nombres[args[0]], ".txt");

    aux[args[0]] = read(args[1], buff[args[0]], N-1);
    if(aux[args[0]] != 0)
    {
        fd[args[0]] = open(nombres[args[0]], O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
        while(aux[args[0]] != 0)
        {
            n[args[0]] = write(fd[args[0]], buff[args[0]], aux[args[0]]);
            aux[args[0]] = read(args[1], buff[args[0]], N-1);
        }
    }
    close(fd[args[0]]);

    return NULL;
}

int main(void)
{
	struct sockaddr_in my_addr;
    int sockfd;
    int newsockfd[CANT_CLIENTES];
    int parametros[2];
    
	sockfd = Open_conection (&my_addr);

	for (int nCliente = 0; nCliente < CANT_CLIENTES; nCliente++)
	{
        newsockfd[nCliente] = Aceptar_pedidos (sockfd);

        parametros[0] = nCliente;
        parametros[1] = newsockfd[nCliente];

		int err = pthread_create(&(tid[nCliente]), NULL, &charlaCliente, (void*) parametros);
        if (err != 0)
            printf("\nError creando el thread: [%s]", strerror(err));
	}

    for (int i = 0; i < CANT_CLIENTES; i++)
    {
        pthread_join(tid[i], NULL);
        close(newsockfd[i]);
    }
	
	close(sockfd);
    
	return 0;
}
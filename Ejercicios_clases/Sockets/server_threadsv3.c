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

struct argumentos 
{
    pthread_t tid;
    int fd;
    char nombre[N];
    char buff[N];
    int aux;
    int n;
    int nCliente;
    int newsock;
};

// pthread_t tid[CANT_CLIENTES];	// Vector con los descriptores de cada thread
// int fd[CANT_CLIENTES];
// char nombres[CANT_CLIENTES][N];
// char buff[CANT_CLIENTES][N];
// int aux[CANT_CLIENTES];
// int n[CANT_CLIENTES];

void *charlaCliente(void* argumentos)
{
    int aux = ((struct argumentos*) argumentos) -> aux;
    int fd = ((struct argumentos*) argumentos) -> fd;
    int nCliente = ((struct argumentos*) argumentos) -> nCliente;
    int newsock = ((struct argumentos*) argumentos) -> newsock;
    int n = ((struct argumentos*) argumentos) -> n;
    char *name = ((struct argumentos*) argumentos) -> nombre;
    char *buff = ((struct argumentos*) argumentos) -> buff;

    aux = read(nCliente, name, N-1);
    strcat(name, ".txt");

    aux = read(newsock, buff, N-1);
    if(aux != 0)
    {
        fd = open(name, O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
        while(aux != 0)
        {
            n = write(fd, buff, aux);
            aux = read(newsock, buff, N-1);
        }
    }
    close(fd);

    return NULL;
}

int main(void)
{
	struct sockaddr_in my_addr;
    int sockfd;
    int newsockfd[CANT_CLIENTES];
    struct argumentos args[CANT_CLIENTES];
    
	sockfd = Open_conection (&my_addr);

	for (int nCliente = 0; nCliente < CANT_CLIENTES; nCliente++)
	{
        newsockfd[nCliente] = Aceptar_pedidos (sockfd);

        args[nCliente].nCliente = nCliente;
        args[nCliente].newsock = newsockfd[nCliente];

		int err = pthread_create(&(args[nCliente].tid), NULL, &charlaCliente, (void*) (&args[nCliente]));
        if (err != 0)
            printf("\nError creando el thread: [%s]", strerror(err));
	}

    for (int i = 0; i < CANT_CLIENTES; i++)
    {
        pthread_join(args[i].tid, NULL);
        close(args[i].newsock);
    }
	
	close(sockfd);
    
	return 0;
}
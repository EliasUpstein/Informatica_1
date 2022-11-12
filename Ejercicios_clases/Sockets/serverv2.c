#include <stdio.h>
#include <string.h>
#include "sock-lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#define N 6000

int main(void)
{
	int sockfd, n, aux, fd, newsockfd;
	char buff[N];
	struct sockaddr_in my_addr;
	sockfd = Open_conection (&my_addr);
	newsockfd = Aceptar_pedidos (sockfd);
	aux = read(newsockfd, buff, N-1);
	if(aux != 0)
	{
		fd = open("destino.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IWUSR);
		while(aux != 0)
		{
			n = write(fd,buff,aux);
			aux = read(newsockfd, buff, N-1);
		}
	}
	close(fd);
	close(newsockfd);
	close(sockfd);
	return 0;
}

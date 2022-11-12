#include <stdio.h>
#include <string.h>
#include "sock-lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#define N 6000

/*struct sockaddr_in {
    short int          sin_family;    // familia de direcciones, AF_INET
    unsigned short int sin_port;      // Número de puerto
    struct in_addr     sin_addr;      // Dirección de Internet
    unsigned char      sin_zero[8];   // Relleno para preservar el tamaño
                                      // original de struct sockaddr
};*/



int main(void)
{
	int sockfd, n, aux, fd, newsockfd, tam;
	char buff[N];
	struct sockaddr_in my_addr;
	//printf("F0\n");                                             'printfs para debuguear'
	sockfd = Open_conection (&my_addr);
	//printf("F1\n");
	newsockfd = Aceptar_pedidos (sockfd);
	//printf("F2\n");

	aux = read(newsockfd, tam, sizeof(tam));

	if (aux != 0)
	{
		fd = open("destino.txt", O_CREAT | O_WRONLY, S_IWUSR);

		//Forma 1 (más iteraciones, menos carga en memoria)
		for (int i = 0; i < tam; i++)
		{
			aux = read(newsockfd, buff, 1);
			n = write(fd,buff,aux);		
		}

		//Forma 2 (menos iteraciones, más carga en memoria)
		// aux = read(newsockfd, buff, tam);
		// n = write(fd,buff,aux);	
		
	}

	// if(aux != 0)
	// {
	// 	//printf("F3\n");
	// 	fd = open("destino.txt", O_CREAT | O_WRONLY, S_IWUSR);
	// 	//printf("F4\n");
	// 	while(aux != 0)
	// 	{
	// 		n = write(fd,buff,aux);
	// 		aux = read(newsockfd, buff, N-1);
	// 	}
	// 	//printf("F5\n");
	// }
	close(fd);
	close(newsockfd);
	close(sockfd);
	return 0;
}

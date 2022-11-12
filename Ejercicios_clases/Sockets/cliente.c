#include <stdio.h>
#include <string.h>
#include "sock-lib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define N 1000

int main(int argc, char*argv[])
{
	if(argc < 3)
	{
		printf("Introduzca <IP> <Puerto> <Archivo.txt> por linea de comando\nCERRANDO SESION\n");
		return 0;
	}
	else
	{
		int sockfd, n, fd, aux, tam;
		char buff[N];

		fd = open(argv[2], O_RDONLY);
		tam = lseek(fd, 0 , SEEK_END);

		sockfd = conectar(argc, argv);
		// aux = read(fd, buff, 1);

		// while(aux != 0)
		// {
		// 	n = write(sockfd, buff, aux);
		// 	if (n < 0)
		// 	{
		// 		printf("ERROR writing to socket");
		// 		break;
		// 	}
		// 	aux = read(fd, buff, N);
		// }

		//Le mando al servidor la cantidad de datos a escribir
		if (write(sockfd, (int*) tam, sizeof(tam)) < 0)
			printf("ERROR writing to socket\n");
		else
		{
			//Forma 1 (más iteraciones, menos carga en memoria)
			for (int i = 0; i < tam; i++)
			{
				read(fd, buff, 1);
				//n = write(sockfd, buff, aux);
				if (write(sockfd, buff, 1) < 0)
				{
					printf("ERROR writing to socket\n");
					break;
				}
			}		

			//Forma 2 (menos iteraciones, más carga en memoria)
			// read(fd, buff, tam);

			// if (write(sockfd, buff, tam) < 0)
			// {
			// 	printf("ERROR writing to socket");
			// 	break;
			// }

			close(fd);
			close(sockfd);
		}
	}
	return 0;
}		

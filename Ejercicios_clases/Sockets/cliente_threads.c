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
		printf("Introduzca <IP> <PUERTO> <Archivo.txt> por linea de comando\nCERRANDO SESION\n");
		return 0;
	}
	else
	{
		int sockfd, n, fd, aux;
		char buff[N];
		char nombre[N];

		printf("Ingrese su nombre:\n");
		fflush(stdin);
		setbuf(stdin, NULL);
		fgets(nombre, N, stdin);

		sockfd = conectar(argc,argv);

		n = write(sockfd, nombre, (strlen(nombre)-1));

		if (n < 0)
		{
			printf("ERROR escribiendo el socket\n");
			close(sockfd);
			return 0;
		}

		fd = open(argv[3], O_RDONLY);
		
		aux = read(fd, buff, N);
		while(aux != 0)
		{
			n = write(sockfd, buff, aux);
			if (n < 0)
			{
				printf("ERROR writing to socket\n");
				break;
			}
			aux = read(fd, buff, N);
		}
		close(fd);
		close(sockfd);
	}
	return 0;
}		

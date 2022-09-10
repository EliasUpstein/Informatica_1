/* Escriba un programa que lea el archivo de texto que recibe por línea de
comandos y determine:
 Cantidad total de palabras
 Cantidad de veces que aparece la palabra “diodo” */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define N 100

int main()
{
    char texto[N];
    char *p;
    int aux = 0;
    int countp = 1, countd = 0;

    int fd = open("archivo2.txt", O_RDONLY);
    
	aux = read(fd, texto, N);
    do
    {
		texto[aux-1]=0;
		printf("%s\n",texto);

        for (int i = 0; i < strlen(texto); i++)
        {
            if(texto[i] == ' ' && texto[i+1] != ' ')
                countp++;
        }

        p = strstr(texto, "diodo");	

        while (p != NULL)
        {
			printf("aca\n");
            countd++;
            p = strstr(p+1, "diodo");
        }

		aux = read(fd, texto, N);
    } while (aux != 0);
    
    printf("Cantidad de palabras: %d\n", countp);
    printf("Cantidad de \"diodo\": %d\n", countd);

    close(fd);

    return 0;
}
/* Cuando es necesario enviar muchos parámetros por línea de comandos,
generalmente es más cómodo contenerlos en un archivo de configuración.
Realizar la siguiente función:
int read_parameters( char * filename, char ** );
La función recibe el nombre del archivo que contiene todos los parámetros (uno
por cada línea), y un char ** donde se cargará la dirección inicial del vector de
punteros (“argv”). El valor de retorno será la cantidad de parámetros leídos del
archivo (“argc”).
Al retornar de la función, el uso de esos parámetros (mediante argc y argv)
deberá poderse realizar de la misma forma que al leer los parámetros de línea de
comandos. */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define N 100

int read_parameters( char * filename, char ** arguments)
{
    char buf[N];
    char * aux[N];
	int cant;
    int parameters = 0;
    int fd = open("arguments.txt", O_RDONLY);

    //cant=read(fd, buf, N);

    do 
    {
        cant=read(fd, buf, N);

        //Busca los espacios y guarda el puntero a la palabra siguiente. Cuenta tambíen los argumentos
        for (int i = 0; i < strlen(buf); i++)
        {
            if(texto[i] == ' ' && texto[i+1] != ' ' && texto[i+1] != '\0')
            {
                aux[parameters] = texto[i+1];
                parameters++;
            }
        }
	
        //Por cada argumento encontrado lo copia al vecto
        for(int i = 0; i < parameters; i++)
        {
            strcpy(arguments[i], aux[i]);
        }

	} while (cant!=0);

    close(fd);

    return parameters;
}
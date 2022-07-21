/*5) Realizar un programa que permita extraer el nombre de usuario que lo ejecutó a un nuevo string, 
que se forme de la siguiente manera: “El usuario <nombre> ejecuto este programa”, 
donde el campo <nombre> es el nombre de usuario extraido de la variable de entorno. 
Finalmente, imprimir este nuevo string en pantalla.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200

int main(int argc,char *argv[],char *envp[])
{
	int i;
	char *contenido;
	contenido = (char *)calloc(N,sizeof(char));
	char *nombre;
	char *p = "=";
	for(i=0;envp[i]!=NULL;i++)
	{
		if(strstr(envp[i],"LOGNAME")!=NULL)
		{
			strcpy(contenido,envp[i]);
			nombre = strtok(contenido,p);
			nombre = strtok(NULL,p);
		}
	}
	printf("El usuario <%s> ejecuto este programa",nombre);
	printf("\n");
	free(contenido);
	return 0;
}

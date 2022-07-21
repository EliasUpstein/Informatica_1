/*Realizar una función que reciba una cadena de caracteres en ASCII de hasta 8192 caracteres. 
La función deberá leer la cadena y determinar (ignorando la diferencia entre mayusculas y minusculas)
la cantidad de veces que se repite cada caracter del abecedario. 
El programa terminará mostrando por pantalla (de la A a la Z sin la ñ)
que cantidad de ocurrencias de cada letra se encontró dentro de la cadena de caracteres recibida.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 8192


void cstr(char *str)
{	
	int cant,i; 
	char caux; 
	int *v = NULL;

	cant = 'z'-'a'+1;
	v = (int*) calloc(cant, sizeof(int)); //calloc para inicializar en 0

	if(v != NULL)
	{
		for(i=0;i<strlen(str); i++)
		{
			caux = (char) tolower((int)str[i]); //int porque la función trabaja así 
			v[caux-'a'] +=1;
		}

		for(i=0; i<cant; i++)
		{
			printf("%c: %d\n", 'a'+i, v[i]);
		}

		free(v);
	}
	else
		printf("Error en la reserva de memoria.\n");
}

int main(void)
{
	char str[SIZE];
	printf("Introduzca una frase: ");
	setbuf(stdin,NULL);
	fgets(str,SIZE,stdin);
	cstr(str);
	return 0;
}
	

/*2)Realizar una función con el siguiente prototipo:

int reemplazo(char *str1,char *str2, char car)
char *str1 es un puntero a char que contiene la dirección de inicio de una cadena de caracteres, 
char *str2 es un puntero a char que contiene la dirección de inicio de una cadena de caracteres, 
char car es un variable que contiene el caracter a reemplazar por 'X'
* 
Retorna: 1 si se pudo reemplazar en la cadena de caracteres str1 el caracter dado 
y se guardó la información en la segunda cadena de caracteres, y 0 en caso contrario en un int*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 40
#define T 256

int reemplazo (char *str1, char *str2, char car)
{
	int i,cont=0;
	for(i=0;i<strlen(str1);i++)
	{
		if(str1[i] == car)
		{
			str2[i]='X';
			cont++;
		}
		else 
		{
			str2[i]=str1[i];
		}
	}
	str2[i]=0;
	return cont;
}

int main (void)
{	
	char str1[N], str2[N], basura[T];
	char car;	
	int resultado;	
	
	printf("ingrese un valor para Str1: \n");
	setbuf(stdin,NULL);
	fgets(str1,N,stdin);
	fgets(basura,T,stdin);
	
	printf("ingrese un valor para caracter a cambiar por la 'X':\n");
	scanf(" %c",&car);
	
	resultado = reemplazo(str1,str2,car);
	
	printf("String con los cambios realizados: %s\n",str2);	
	printf("Cantidad de cambios: %d\n",resultado);
	return 0;
}
		
		

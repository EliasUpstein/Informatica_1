/* Escribir 3 funciones que, recibiendo una cadena de caracteres como
argumento, permitan determinar si la cadena es válida como dirección IP, como
dirección de correo electrónico, y como número de tarjeta de crédito. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 40

int IP(char *s);

int main(void)
{
	char s[N];
	printf("Introduzca una dirección de IP, una dirección de correo electrónico o la serie de números de una tarjeta de crédito:\n");
	setbuf(stdin,NULL);
	fgets(s,N,stdin);

	

	return 0;
}

int IP(char *s)     //Revisar
{
	int i;
	char p[2] = ".";
	int token[4];
	if(strchr(s,' ') == NULL) //Verifica que la cadena no tenga espacios con la funcion (strchr)
	{	
		token[0] = atoi(strtok(s,p));
		for(i = 1; i < 4; i++)
		{
			token[i] = atoi(strtok(NULL,p));
		}
		i=0;
		for(i = 0; i < 4; i++)
		{
			if(token[i]<0 || token[i]>=256)
				return 0;
		}
		return 1;
	}
	return 0;
}

int Correo(char *s)
{
	if(strchr(s,'@') != NULL && strchr(s,'.') != NULL) //verifico que la cadena tenga un @ y un .
        return 1;
	
    return 0;
}
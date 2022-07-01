/*Escribir una función que reciba como parámetro una cadena de caracteres que
comienza con espacios en blanco, y los elimine desplazando los caracteres útiles
hacia la izquierda. (operación "left-trim").
Prototipo: void left_trim (char *) ;*/

#include <stdio.h>
#include <string.h>
#define N 50

void my_left_trim (char *s);

int main(void)
{
	char s[N];

	printf("Introduzca una frase: \n");
	setbuf(stdin,NULL);
	fgets(s,N,stdin);

	my_left_trim(s);

	printf("Frase desplazada a la izquierda: %s\n",s);

	return 0;
}

void my_left_trim (char *s)
{
	int i,j=0;
	for(i=0;i<strlen(s);i++)
	{
		//Para cada posición distinta del espacio en blanco o que es un espacio pero que separa palabras (sintáctico)
		if(s[i]!=(' ') || (s[i]==(' ') && s[i-1]!=(' ') && s[i+1]!=(' ')))
		{
			s[j]=s[i];							//Desplaza la frase
			j++;								//j se mantiene en 0 hasta encontrar la primera letra
		}
	}											//La función también elimina si tiene espacios intermedios
	s[j]='\0';
}
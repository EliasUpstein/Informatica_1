/* Escribir una función que reciba como parámetro una cadena de caracteres que
finaliza con espacios en blanco, y los elimine desplazando los caracteres útiles
hacia la izquierda. (operación "right-trim").
Prototipo: void right_trim (char *) ; */

#include <stdio.h>
#include <string.h>

#define N 50

void my_right_trim (char *);

int main(void)
{
	char s[N];
	printf("Introduzca una frase: \n");
	setbuf(stdin,NULL);
	fgets(s,N,stdin);

	my_right_trim(s);

	printf("Frase con espacios en blanco eliminados: %s\n",s);

	return 0;
}

void my_right_trim (char *s)
{
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==(' ') && s[i+1]==(' '))
			s[i]='\0';
	}
}
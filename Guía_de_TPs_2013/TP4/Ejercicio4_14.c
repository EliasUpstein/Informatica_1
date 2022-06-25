/* Escribir una función que responda al siguiente prototipo:
void replace (char *s, char nuevo, char viejo) ;
y reemplace en la cadena "s" todas las apariciones del caracter "viejo" por el
carácter "nuevo". */

#include <stdio.h>
#include <string.h>

#define N 30

void my_replace (char *s, char nuevo, char viejo);

int main(void)
{
	char s[N];
	char nuevo,viejo;

	printf("Ingrese una cadena:\n");
	setbuf(stdin,NULL);
	fgets(s,N,stdin);

	printf("Ingrese el caracter de la cadena a reemplazar:\n");
	setbuf(stdin,NULL);
	scanf(" %c", &viejo);

	printf("\nIngrese el caracter a colocar en la cadena:\n");
	scanf(" %c", &nuevo);

	my_replace(s,nuevo,viejo);
    printf("\nLa cadena reemplazada es: %s\n",s);

	return 0;
}

void my_replace (char *s, char nuevo, char viejo)
{
	for(int i=0; i < strlen(s); i++)
	{
		if(s[i] == viejo)
			s[i] = nuevo;
	}
}
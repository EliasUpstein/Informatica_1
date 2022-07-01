/* Escribir una función que reciba dos cadenas de caracteres denominadas "s1" y
"s2" respectivamente, y verifique la existencia de la cadena s2 como subcadena
integrante de la s1, retornando un token del tipo enumerativo bool por el nombre
de la función (ver función strstr() de la biblioteca <string.h>).
Prototipo: bool my_strstr (char *big, char *sub) ; */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 50

bool my_strstr(char *big, char *sub);

int main()
{
	char grande[N];
	char buscada[N];

	printf("Introduzca una frase: \n");
	setbuf(stdin,NULL);
	fgets(grande,N,stdin);

    printf("Ingrese la secuencia a buscar en la frase:\n");
    fflush(stdin);
    fgets(buscada, N, stdin);

    while (strlen(buscada) > strlen(grande))
    {
        printf("La cadena buscada es más grande que la original. Reingrese secuencia a buscar: \n");
        fflush(stdin);
        fgets(buscada, N, stdin);
    }

	if (my_strstr(grande, buscada) == true)
        printf("Cadena encontrada.\n");
    else
        printf("No se pudo encontrar la cadena buscada.\n");
    
	return 0;
}

/* Itera a lo largo del string b mientras que no se exceda la longitud del string sub
A medida que va coincidiendo la cadena aumenta j, si no coinciden o deja de coincidir antes de terminar lo reinicia*/
bool my_strstr(char *big, char *sub)
{
    int a = strlen(sub);
    int j = 0;
    for (int i = 0; i < strlen(big) && j < strlen(sub)-1; i++)      //Resta 1 para corregir el índice desplazado
    {
        if (big[i] == sub[j])
            j++;
        else
            j = 0;
    }
    if (j == (strlen(sub) - 1))
        return true;

    return false;
}
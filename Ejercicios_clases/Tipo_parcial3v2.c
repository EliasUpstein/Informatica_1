/* 3) El programa recibe un “mensaje a moderar” por línea de comandos. 
Ejemplo: $ nombre_programa Hola mundo!! ¿Que tal?, donde Hola Mundo!! ¿Que tal? es el mensaje a moderar.
Ni bien se carga en memoria, el programa ejecutará la siguiente secuencia de operaciones:
3.1. Requerirá al usuario el ingreso de hasta 10 palabras prohibidas por teclado.
El ingreso finaliza cuando una cadena se compone solo de '\0', es decir cuando el usuario pulsó solo ENTER,
o cuando se alcanza el valor máximo de 10 palabras. Así armará un arreglo de hasta 10 palabras prohibidas.
3.2. A continuación (es decir, una vez ingresada la lista completa de palabras prohibidas) el programa
buscará en el mensaje a moderar, cada una de las palabras que componen la black list, y de encontrarla
reemplazará cada uno de sus caracteres por una “X”. Considerar que una palabra prohibida puede aparecer
más de una vez en el mensaje a moderar.
3.3. Una vez completada esta tarea imprimirá por pantalla el “mensaje moderado”, y en la siguiente línea
una leyenda que informe la cantidad de caracteres reemplazados por “X” */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200

int main(int cantArg, char *args[])
{
    char palabras[10][N];
    char* mensaje = (char*) calloc(N,sizeof(char));
    int contador = 0;
    int count = 0;

    if (cantArg > 1 && mensaje != NULL)
    {
        //Concateno todas las palabras del mensaje en una frase
        for (int i = 1; i < cantArg; i++)
        {
            strcat(mensaje, args[i]);
            strcat(mensaje, " ");
        }
        
        //Ingreso de palabras a la lista
        for(int i = 0; i < 10; i++)
		{
			printf("Introduzca la palabra nº%d para la Black List: ",i+1);
			setbuf(stdin,NULL);
			fgets(palabras[i],N,stdin);

			if(palabras[i][0] == '\n')
			{
				palabras[i][0]=0;
				break;
			}
			if(palabras[i][strlen(palabras[i])-1] == '\n')
				palabras[i][strlen(palabras[i])-1] = '\0';

			contador++;
		}

        //Para cada palabra del arreglo "palabras" busca la existencia dentro del mensaje
        for (int i = 0; i < contador; i++)
        {
            char* aux = strstr(mensaje, palabras[i]);
            //Si encuentra la palabra en el mensaje
            if (aux != NULL)
            {
                //Para cada posición de la palabra en el mensaje escribe la X
                for (int j = 0; j < strlen(palabras[i]); j++)
                {
                    aux[j] = 'X';
                    count++;
                }
                i--;       //Retrocedo una posición en i para que si la palabra se repite, la vuelva a buscar
            }
        }
        
        printf("Mensaje moderado:\n");
        fputs(mensaje, stdout);
        printf("\nCantidad de caracteres reemplazados: %d\n", count);

        free(mensaje);
    }
    else
        printf("No se ha ingresado ningún mensaje.\n");

    return 0;
}
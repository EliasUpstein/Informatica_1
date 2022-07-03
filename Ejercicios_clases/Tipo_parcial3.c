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

#define N 1024

int main(int cantArg, char *args[])
{
    char palabras[N];
    char *direcciones[10];
    int count = 0;
    int cantpalabras = 0;

    if (cantArg > 1)
    {
        //Con espacios
        printf("Ingrese 10 palabras prohibidas:\n");
        fflush(stdin);
        fgets(palabras, N, stdin);  //¿Cómo controlo que ingrese realmente 10 palabras? (me lo corta el for)
        if( palabras[strlen(palabras) - 1] == '\n')     //Borro el \n final para poder hacer la comparación
            palabras[strlen(palabras) - 1] = '\0';

        //Guardo en direcciones el puntero a cada string
        direcciones[0] = strtok(palabras," ");
        if (direcciones[0] != NULL)
        {
            cantpalabras++;
            for (int i = 1; i < 10; i++)
            {
                direcciones[i] = strtok(NULL," ");  
                if (direcciones[i] == NULL)
                    break;
                cantpalabras++;
            }
        }
        //Otra forma con scanf
        // printf("Ingrese 10 palabras prohibidas:\n");
        // fflush(stdin);
        // scanf("%s %s %s %s %s %s %s %s %s %s", direcciones[0],direcciones[1],direcciones[2],direcciones[3],direcciones[4],direcciones[5],direcciones[6],direcciones[7],direcciones[8],direcciones[9],)  

        //Con enter's
        // printf("Ingrese 10 palabras prohibidas:\n");
        // for (int i = 0; i < 10; i++)
        // {
        //     fflush(stdin);
        //     fgets(direcciones[i], N, stdin);
        //     //Si se ingresó solo un enter
        //     if (strcmp(direcciones[i],"\n") == 0)
        //         break; 
        // }
        for (int i = 1; i < cantArg; i++)           //Para cada string pasado como argumento
        {
            for (int j = 0; j < 10 && j < cantpalabras; j++)//Para cada palabra ingresada como prohibida
            {
                if (strcmp(args[i], direcciones[j]) == 0)       //Si los string son iguales
                {
                    for (int k = 0; k < strlen(args[i]); k++)   //Para cada letra del sting escribe X
                    {
                        args[i][k] = 'X';
                        count++;
                    }
                }
            }
        }

        printf("Mensaje moderado:\n");
        for (int i = 1; i < cantArg; i++)
        {
            fputs(args[i], stdout);
            printf(" ");
        }
        printf("\nCantidad de caracteres reemplazados: %d\n", count);
    }
    else
        printf("No se ha ingresado ningún mensaje.\n");
    
    return 0;
}
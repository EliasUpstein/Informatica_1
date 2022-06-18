/* Escribir un programa que rebiba como argumento del main una IP
y separe cada una de sus cuatro números.
Debe verificar que cada uno sea un número de 0 a 255 y guardarlo en un 
vector de 4 enteros. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP 4

int main(int cantArg, char *args)
{
    char caracter[2] = ".";
    char *direc[IP];
    int direcent[IP];
    int i = 0;

    if(cantArg > 1)
    {
        if (strlen(args) < 9 && strlen(args) > 0)   //Validación cantidad de números
        {    
            direc[i] = strtok(args, caracter);  //Guardo la dirección de los primero 3 digitos

            for (i = 1; i < IP; i++)
            {
                direc[i] = strtok(NULL, caracter);   //Guardo la dirección del resto de dígitos
                direcent[i] = atoi(direc[i]);        //Guardo el dato como entero en el otro vector     
            }

            for (int j = 0; j < IP; j++)
            {
                printf("La dirección IP es:\n");

                if (direcent[j] >= 0 && direcent[i] <= 255)
                {
                    printf("%d.", &direcent[j]);
                }
                else
                    printf("Dirección inválida\n");
                
            }
        }
        else
            printf("Dirección inválida\n");
    }
    else
        printf("No se ha especificado una dirección IP\n");

    return 0;
}
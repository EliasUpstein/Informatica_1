/* Escribir un programa que rebiba como argumento del main una IP
y separe cada una de sus cuatro números.
Debe verificar que cada uno sea un número de 0 a 255 y guardarlo en un 
vector de 4 enteros. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP 4

int main(int cantArg, char *args[])
{
    char caracter[2] = ".";
    char *direc[IP];
    int direcent[IP];
    int i = 0;

    if(cantArg > 1)
    {
        if (strlen(args[1]) < 15 && strlen(args[1]) > 0)   //Validación cantidad de números (12 num + 3 .)
        {    
            direc[i] = strtok(args[1], caracter);  //Guardo la dirección de los primero 3 digitos
            direcent[i] = atoi(direc[i]);    //Convierto a entero el string de la direccion
                                            //strtok escribe en el token \0
            for (i = 1; i < IP; i++)
            {
                direc[i] = strtok(NULL, caracter);   //Guardo la dirección del resto de dígitos
                direcent[i] = atoi(direc[i]);    //Convierto a entero el string de la direccion
            }

            for (int j = 0; j < IP; j++)
            {
                printf("La dirección IP es:\n");

                if (direcent[j] >= 0 && direcent[i] <= 255)
                    printf("%d.", direcent[j]);
                else
                {
                    printf("Dirección inválida\n");
                    break;
                }
            }
        }
        else
            printf("Dirección inválida\n");
    }
    else
        printf("No se ha especificado una dirección IP\n");

    system("pause");
    return 0;
}
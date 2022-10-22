/* Modificar el ejercicio anterior para que el formato de salida pueda ser informado
al programa por medio de comandos en línea de órdenes (sysdate). */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 30

int main(int cantArg, char *args[])
{
    if (cantArg > 1)
    {
        time_t tiempo = time(NULL);     //Guarda la fecha actual
        struct tm tiempoLocal = *localtime(&tiempo);    //Convierte la variable de tiempo en una estructura

        char fecha[N];

        if (strcmp(args[1], "AAAAMMDD") == 0 && strcmp(args[2], "HhmmSS") != 0)
        {
            strftime(fecha, sizeof(fecha), "&Y-%m-%d", &tiempoLocal);
            fputs(fecha, stdout);
        }
        else if (strcmp(args[1], "AAAAMMDD") == 0 && strcmp(args[2], "HhmmSS") == 0)
        {
            strftime(fecha, sizeof(fecha), "&Y-%m-%d %H:%M:%S", &tiempoLocal);
            fputs(fecha, stdout);
        }
        else if (strcmp(args[1], "HH:mm:SS") == 0 && strcmp(args[2], "del") == 0 && strcmp(args[3], "DD/MM/AAAA"))
        {
            strftime(fecha, sizeof(fecha), "&Y-%m-%d %H:%M:%S", &tiempoLocal);
            fputs(fecha, stdout);
        }
        else
            printf("El formato recibido no es correcto\n");
    }
    else
        printf("No se recibió el formato de salida\n");
    
    return 0;
}
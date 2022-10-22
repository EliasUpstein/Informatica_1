/*Escribir un programa invocable por línea de órdenes que obtenga la fecha actual
del sistema y la presente por stdout para los siguientes formatos:
a) AAAAMMDD
b) AAAAMMDD HhmmSS
c) HH:mm:SS del DD/MM/AAAA
Ayuda: usar la biblioteca <time.h>*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

int main()
{
    time_t tiempo = time(NULL);     //Guarda la fecha actual
    struct tm tiempoLocal = *localtime(&tiempo);    //Convierte la variable de tiempo en una estructura

    char fecha[N];

    //a) AAAAMMDD
    strftime(fecha, sizeof(fecha), "&Y-%m-%d", &tiempoLocal);
    fputs(fecha, stdout);

    //b) AAAAMMDD HhmmSS
    strftime(fecha, sizeof(fecha), "&Y-%m-%d %H:%M:%S", &tiempoLocal);
    fputs(fecha, stdout);

    //c) HH:mm:SS del DD/MM/AAAA
    strftime(fecha, sizeof(fecha), "%H:%M:%S del &d/%m/%Y", &tiempoLocal);
    fputs(fecha, stdout);

    return 0;
}
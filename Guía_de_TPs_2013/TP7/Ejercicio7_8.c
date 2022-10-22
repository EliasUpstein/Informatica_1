/* Definir una estructura de datos que permita representar el Tiempo, es decir
horas, minutos y segundos.
Desarrollar las funciones de manipulación del Tiempo tales como
a) CreaTime: genera un estructura del tipo Tiempo inicializado en 0 horas, 0
minutos y 0 segundos.
b) ShowTime: imprime las horas, minutos y segundos en el siguiente formato
hh:mm:ss
c) SetTime: Recibe las horas minutos y segundos como argumentos y setea los
valores en los campos de la estcrutura */

#include <stdio.h>

struct Tiempo
{
    int horas;
    int minutos;
    int segundos;
};

struct Tiempo CreaTime()
{
    struct Tiempo nueva;

    nueva.horas = 0;
    nueva.minutos = 0;
    nueva.segundos = 0;

    return nueva;
}

void ShowTime(struct Tiempo estructura)
{
    printf("%d:%d:%d\n", estructura.horas, estructura.minutos, estructura.segundos);
}

//Asumo recibe también el puntero a la estructura
void SetTime(struct Tiempo *estructura, int hora, int minuto, int segundo)
{
    estructura -> horas = hora;
    estructura -> minutos = minuto;
    estructura -> segundos = segundo;
}
/* Construir una estructura de datos que represente a un automóvil. Un automóvil
es una estructura que tiene los siguientes atributos:
 numeroDominio: el número de patente,
 numeroMotor: número que trae grabado el motor,
 marca: marca del automóvil
 modelo: el modelo de automóvil
 tamañoMotor: número que indica la potencia del motor.
 color: el color de la carrocería
Escribir las siguientes funciones para manipular un automóvil como el definido en
el ejercicio anterior:
a) crearAuto: genera una instancia de tipo Automóvil con valores de inicialización
adecuados para cada uno de sus atributos.
b) cambiarColor: modifica el valor del atributo color de un automóvil que recibe
c) mostrarAuto: imprime todos los atributos de un automóvil en particular
d) clonarAuto: es una función que reproduce un automóvil en otra variable de
tipo Automóvil (función clone()) */

#include <stdio.h>
#include <string.h>

#define N 30

struct Automovil
{
    int numeroDominio;
    int numeroMotor;
    char marca[N];
    char modelo[N];
    int tamanoMotor;
    char color[N];
};

struct Automovil crearAuto()
{
    struct Automovil nueva;

    nueva.numeroDominio = 123456;
    nueva.numeroMotor = 111111;
    strcpy(nueva.marca, "Fiat");
    strcpy(nueva.modelo, "Uno");
    nueva.tamanoMotor = 250;
    strcpy(nueva.color, "Rojo");

    return nueva;
}

void cambiarColor(struct Automovil *estructura, char *color_nuevo)
{
    strcpy(estructura->color, color_nuevo);
}

void mostrarAuto(struct Automovil estructura)
{
    printf("Numero Dominio: %d\n", estructura.numeroDominio);
    printf("Número Motor: %d\n", estructura.numeroMotor);
    printf("Marca: %s\n", estructura.marca);
    printf("Modelo: %s\n", estructura.modelo);
    printf("Tamaño Motor: %d\n", estructura.tamanoMotor);
    printf("Color: %s\n", estructura.color);
}

void clonarAuto(struct Automovil original, struct Automovil *clon)
{
    clon->numeroDominio = original.numeroDominio;
    clon->numeroMotor = original.numeroMotor;
    strcpy(clon->marca, original.marca);
    strcpy(clon->modelo, original.modelo);
    clon->tamanoMotor = original.tamanoMotor;
    strcpy(clon->color, original.color);
}
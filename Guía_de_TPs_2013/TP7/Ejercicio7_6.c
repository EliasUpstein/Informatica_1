/* Escribir funciones que, mediante el uso de estructuras, realicen lo siguiente:
a) Convertir coordenadas rectangulares en polares
b) Convertir coordenadas polares en rectangulares
c) Realizar suma, resta, producto, división, potencia y radicación de números
complejos
d) Agregar la posibilidad de expresar los ángulos en grados o radianes. */

#include <math.h>

struct rectangulares
{
    float x, y;
};

struct polares
{
    float mod, ang;
};

struct complejos
{
    float real, imag;
};

struct polares recToPol(struct rectangulares coordenadas)
{
    struct polares coorde;

    coorde.mod = sqrt((coordenadas.x * coordenadas.x) + (coordenadas.y * coordenadas.y));
    coorde.ang = atan2(coordenadas.x, coordenadas.y);

    return coorde;
}

struct rectangulares polToRec(struct polares coordenadas)
{
    struct rectangulares coorde;

    coorde.x = coordenadas.mod * cos(coordenadas.ang);
    coorde.y = coordenadas.mod * sin(coordenadas.ang);

    return coorde;
}


struct complejos sumaComplejos (struct complejos num1, struct complejos num2)
{
    struct complejos coorde;

    coorde.real = num1.real + num2.real;
    coorde.imag = num1.imag + num2.imag;

    return coorde;
}

struct complejos restaComplejos (struct complejos num1, struct complejos num2)
{
    struct complejos coorde;

    coorde.real = num1.real - num2.real;
    coorde.imag = num1.imag - num2.imag;

    return coorde;
}

struct complejos prodComplejos (struct complejos num1, struct complejos num2)
{
    struct complejos coorde;

    coorde.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    coorde.imag = (num1.real * num2.imag) + (num1.imag * num2.real);

    return coorde;
}

struct complejos divComplejos (struct complejos num1, struct complejos num2)
{
    struct complejos coorde;

    coorde.real = ((num1.real*num2.real) + (num1.imag*num2.imag)) / ((num2.real*num2.real) + (num2.imag*num2.imag));
    coorde.imag = ((num1.imag*num2.real) - (num1.real*num2.imag)) / ((num2.real*num2.real) + (num2.imag*num2.imag));

    return coorde;
}

struct complejos potComplejos (struct complejos num, int n)
{
    struct complejos coorde;
    struct polares aux;             //Convierto el dato complejo en polar
    struct rectangulares aux2;      

    //Convierto entre dato complejo y rectangular
    aux2.x = num.real;
    aux2.y = num.imag;

    //Convierto el dato complejo en polar
    aux = recToPol(aux2);

    //Realizo el cálculo de la potencia
    aux.mod = pow(aux.mod,n);
    aux.ang = n * aux.ang;

    //Vuelvo a llevar el número a coordenadas reectangulares
    aux2 = polToRec(aux);

    //Convierto el dato rectangular en complejo
    coorde.real = aux2.x;
    coorde.imag = aux2.y;

    return coorde;
}

struct complejos radComplejos (struct complejos num, int n)
{
    struct complejos coorde;
    struct polares aux;             //Convierto el dato complejo en polar
    struct rectangulares aux2;      

    //Convierto entre dato complejo y rectangular
    aux2.x = num.real;
    aux2.y = num.imag;

    //Convierto el dato complejo en polar
    aux = recToPol(aux2);

    //Realizo el cálculo de la raíz
    aux.mod = pow(aux.mod,(1/n));   //1/n equivale a la raíz de grado n
    aux.ang = aux.ang / n;

    //Vuelvo a llevar el número a coordenadas reectangulares
    aux2 = polToRec(aux);

    //Convierto el dato rectangular en complejo
    coorde.real = aux2.x;
    coorde.imag = aux2.y;

    return coorde;
}

float radToDeg(float rad)
{
    return rad * 180 / M_PI;
}

float degToRad(float deg)
{
    return deg * M_PI / 180;
}
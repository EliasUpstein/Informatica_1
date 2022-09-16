/* Escriba una función que reciba un ángulo expresado en radianes y lo devuelva en
formato sexagesimal.*/

struct sexagesimal
{
    int grados;
    int minutos;
    float segundos;
};

#define PI 3.1415

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float rad;
    float aux;
    struct sexagesimal sex;

    printf("Ingrese un grado en radianes: ");
    fflush(stdin);
    scanf("%f", &rad);

    aux = (rad * 180) / PI;

    sex.grados = (int) aux;                                 //Almacena la parte entera del ángulo
    sex.minutos = (int) (aux - sex.grados) * 60;            //Almacena la parte entera de los minutos
    sex.segundos = (((aux - sex.grados) * 60) - sex.minutos) * 60;

    printf("El ángulo ingresado en grados sexagesimales es: %d° %d' %f''\n", sex.grados, sex.minutos, sex.segundos);

    return 0;
}
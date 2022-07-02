/* Escribir una función que recibe las coordenadas rectangulares de dos puntos del
plano y calcule la distancia entre ellos. */

#include <stdio.h>
#include <string.h>
#include <math.h>

float distanciaPuntos(float* p1, float* p2);

int main()
{
    float punto1[2];
    float punto2[2]; 

    printf("Ingrese coordenada x del punto 1:\n");
    fflush(stdin);
    scanf("%f", &punto1[0]);
    printf("Ingrese coordenada y del punto 1:\n");
    fflush(stdin);
    scanf("%f", &punto1[1]);
    printf("Ingrese coordenada x del punto 2:\n");
    fflush(stdin);
    scanf("%f", &punto2[0]);
    printf("Ingrese coordenada y del punto 2:\n");
    fflush(stdin);
    scanf("%f", &punto2[1]);

    printf("La distancia entre puntos es: %f\n", distanciaPuntos(punto1,punto2));

    return 0;
}

float distanciaPuntos(float* p1, float* p2)
{
    return sqrt(pow(p2[0]-p1[0],2)+pow(p2[1]-p1[1],2));
}

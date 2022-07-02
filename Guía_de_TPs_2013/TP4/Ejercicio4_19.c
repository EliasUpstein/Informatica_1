/* Escribir una función que calcule la partes entera y decimal de cualquier número
real recibido como argumento, y las retorne al programa invocante. ¿Como se
resuelve devolver mas de un resultado? */

#include <stdio.h>
#include <stdlib.h>

#define N 2

//static float *separarEnteroDecimal(float);
float *separarEnteroDecimal(float n);

int main()
{
    float n;
    float *partes;

    printf("Ingrese el real a separar:\n");
    fflush(stdin);
    scanf("%f", &n);

    partes = separarEnteroDecimal(n);

    printf("La parte entera del número es: %d\n", (int) partes[0]);
    printf("La parte decimal del número es: %f\n", partes[1]);

    free(partes);
    return 0;
}

float *separarEnteroDecimal(float n)
{
    float *separado = (float*) calloc(N,sizeof(float));

    if (separado != NULL)
    {
        separado[0]= (int) n;
        separado[1]= n - separado[0];
    }
    return separado;
}

// //static para que no me libere la memoria 
// static float *separarEnteroDecimal(float n)
// {
//     static float separado[N];

//     separado[0]= (int) n;
//     separado[1]= n - separado[0];

//     return separado;
// }
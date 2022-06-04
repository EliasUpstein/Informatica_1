/* Escribir un programa que lea dos valores que correspondan a los extremos
izquierdo y derecho de un intervalo. Luego, se debe dividir dicho intervalo en 4
subintervalos iguales. Si la longitud del intervalo ingresado no fuese múltiplo de
4, se redondeará al primer múltiplo mayor. Se deberá mostrar por pantalla el
rango ingresado y cada uno de los subrangos. */

#include <stdio.h>

int main()
{
    int A, B, C, D, E;
    int largo;

    printf("Ingrese el extremo izquierdo del intervalo:\n");
    fflush(stdin);
    scanf("%d", &A);
    
    printf("Ingrese el extremo derecho del intervalo:\n");
    fflush(stdin);
    scanf("%d", &E);

    largo = (E - A) % 4;      

    if (largo != 0)     //Si la longitud del intervalo no es multiplo de 4
        E = E + (4 - largo);   //Le sumo el resto para que sea multiplo de 4

    largo = (E - A) / 4;    

    B = A + largo;  //Intevalo (A;B)
    C = B + largo;  //Intevalo (B;C) 
    D = C + largo;  //Intevalo (C;D)

    printf("Rango ingresado: (%d;%d)\n", A, E);
    printf("Subintervalo 1: (%d;%d)\n", A, B);
    printf("Subintervalo 2: (%d;%d)\n", B, C);
    printf("Subintervalo 1: (%d;%d)\n", C, D);
    printf("Subintervalo 1: (%d;%d)\n", D, E);

    return 0;
}
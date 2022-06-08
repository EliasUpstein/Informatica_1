/* - Trabajo Práctico Nº3
- Grupo 3
- Ejercio 3c
-Observaciones:

/* Escriba una función que reciba un valor de temperatura en precisión doble, y
la escala de temperaturas de destino, y realice la conversión del valor. 
(conversión celsius-fahrenheit o viceversa)*/

#include <stdio.h>
#include "Ejercicio3_8c.h"

int main()
{
    double temp = 0;
    char conver;

    printf("Ingrese el valor de la temperatura:\n");
    fflush(stdin);
    scanf("%lf", &temp);

    printf("Ingrese la escala a convertir:\n");
    fflush(stdin);
    scanf(" %c", &conver);

    while (conver != 'c' && conver != 'f')
    {
        printf("Ingrese una escala válida:\n");
        fflush(stdin);
        scanf(" %c", &conver);
    }

    printf("La temperatura convertida es: %lf", convertTemp(temp, conver));
    
    return 0;
}
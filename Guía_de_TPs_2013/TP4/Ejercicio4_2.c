/* Repita el Ejercicio 3.8. utilizando punteros. */
/*Escriba una función que reciba un valor de temperatura en precisión doble, y
la escala de temperaturas de destino, y realice la conversión del valor. */

#include <stdio.h>

void convertTemp(double *tem, char *des)
{
    if (*des == 'c')
        *tem = (*tem - 32) * 5/9;
    else if (*des == 'f')
        *tem = (*tem * 9/5) + 32;
    else
        *tem = *tem;
}

int main()
{
    double temp = 0;
    char conver;

    printf("Ingrese el valor de la temperatura:\n");
    fflush(stdin);
    scanf("%lf", &temp);

    printf("Ingrese la escala a convertir ('c' o 'f'):\n");
    fflush(stdin);
    scanf(" %c", &conver);

    while (conver != 'c' && conver != 'f')
    {
        printf("Ingrese una escala válida:\n");
        fflush(stdin);
        scanf(" %c", &conver);
    }

    convertTemp(&temp, &conver);

    printf("La temperatura convertida es: %lf\n", temp);
    
    return 0;
}
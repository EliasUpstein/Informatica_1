/* Escribí un programa que solicite al usuario ingresar la cantidad de kilómetros recorridos por
una motocicleta y la cantidad de litros de combustible que consumió durante ese recorrido.
Mostrar el consumo de combustible por kilómetro. */

#include <stdio.h>

int main(void)
{
    float kilometros, litros_combustilble;

    printf("Ingrese la cantidad de kilometros recorridos: ");
    fflush(stdin);
    scanf("%f", &kilometros);

    while (kilometros < 0)
    {
        printf("\nIngrese una cantidad de kilometros válida: ");
        fflush(stdin);
        scanf("%f", &kilometros);
    }
    
    printf("\nIngrese la cantidad de combustible comsumido en litros: ");
    fflush(stdin);
    scanf("%f", &litros_combustilble);

    while (litros_combustilble <= 0)
    {
        printf("\nIngrese una cantidad de combustible válida: ");
        fflush(stdin);
        scanf("%f", &litros_combustilble);
    }

    printf("\nConsumo de combustible por kilómetro [litros / kilometros]: %f\n", (litros_combustilble / kilometros));

    return 0;
}
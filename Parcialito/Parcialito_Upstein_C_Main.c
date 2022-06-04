#include <stdio.h>
#include "Parcialito_Upstein_C_Lib.h"    //El archivo está en el mismo directorio

int main()
{
    float radio = 0;

    printf("Ingrese un radio:\n");
    fflush(stdin);
    scanf("%f", &radio);

    while (radio < 0)
    {
        printf("Ingrese un radio válido\n");
        fflush(stdin);
        scanf("%f", &radio);
    }
    
    printf("El área del círculo es %f\n", areaCirculo(radio));
    printf("El perímetro del círculo es %f\n", perimetroCirculo(radio));

    return 0;
}
//Compilación: gcc -o circulo Parcialito_Upstein_C_Main.c Parcialito_Upstein_C_Lib.c
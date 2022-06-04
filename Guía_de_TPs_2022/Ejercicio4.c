/* Desarrollar programa que permita calcular el promedio de 3 notas. Luego debe obtener
la situación final que refleja el promedio, ya sea aprobado o reprobado. Considere
validar que las notas estén entre 1 y 7. Al terminar imprima la situación junto con el
promedio. */

#include <stdio.h>

#define APROBADO 4

int main(void)
{
    float nota[3]; 
    float promedio;

    for(int i=0; i<3; i++)
    {
        printf("Ingrese nota %d: ", (i+1));
        fflush(stdin); 
        scanf("%f", &nota[i]);

        while(nota[i] < 1 || nota[i] > 7)
        {
            printf("\nIngrese una nota válida: "); 
            fflush(stdin); 
            scanf("%f", &nota[i]);
        }
    }

    promedio = (nota[0] + nota[1]+nota[2]) / 3;

    if (promedio > APROBADO)
        printf("\nAprobado: %f\n", promedio);
    else
        printf("\nDesaprobado: %f\n", promedio);

    return 1;
}
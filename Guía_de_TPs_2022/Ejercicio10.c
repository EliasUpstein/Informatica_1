/* Desarrollar programa que permita Pedir por Pantalla 4 Notas e identifique la Mayor de
las Notas. Las notas deben estar entre 1 y 7. */

#include <stdio.h>

int main(void)
{
    float nota[4]; 
    float mayor = 0;

    for(int i=0; i<4; i++)
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

        if (nota[i] > mayor)
            mayor = nota[i];
    }

    printf("\nLa mayor nota es: %f\n", mayor);

    return 0;
}
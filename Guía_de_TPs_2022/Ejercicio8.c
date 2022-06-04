/* Desarrollar programa que permita Pedir por Pantalla 3 Notas e identifique la Menor de
ellas. Las notas deben estar entre 1 y 7. */

#include <stdio.h>

int main(void)
{
    float nota[3]; 

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

    if(nota[0] < nota[1] && nota[0] < nota[2])
        printf("\nLa menor nota es: %f\n", nota[0]);
    else if (nota[1] < nota[0] && nota[1] < nota[2])
        printf("\nLa menor nota es: %f\n", nota[1]);
    else    //Por descarte, es la última nota
        printf("\nLa menor nota es: %f\n", nota[2]);
    
    return 0;
}
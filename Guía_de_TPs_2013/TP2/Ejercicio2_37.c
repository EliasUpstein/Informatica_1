/* Leer 30 números desde teclado, y determinar e informar por pantalla:
a) el promedio de cada uno de los 5 grupos de 6 valores consecutivos
b) el promedio total. */

#include <stdio.h>

int main()
{
    float n1,n2,n3,n4,n5,n6;
    float p1,p2,p3,p4,p5,pt;
    int aux = 1;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("Ingrese el valor %d:\n", i+j+aux);
            fflush(stdin);

            switch (j)
            {
                case 0:
                    scanf("%f", &n1);
                    break;
                case 1:
                    scanf("%f", &n2);
                    break;
                case 2:
                    scanf("%f", &n3);
                    break;
                case 3:
                    scanf("%f", &n4);
                    break;
                case 4:
                    scanf("%f", &n5);
                    break;
                case 5:
                    scanf("%f", &n6);
                    break;    
            }
        }

        switch (i)
        {
            case 0:
                p1 = (float) (n1 + n2 + n3 + n4 + n5 + n6) / 6; 
                aux = 6;
                break;
            case 1:
                p2 = (float) (n1 + n2 + n3 + n4 + n5 + n6) / 6; 
                aux = 11;
                break;
            case 2:
                p3 = (float) (n1 + n2 + n3 + n4 + n5 + n6) / 6;
                aux = 16; 
                break;
            case 3:
                p4 = (float) (n1 + n2 + n3 + n4 + n5 + n6) / 6; 
                aux = 21;
                break;
            case 4:
                p5 = (float) (n1 + n2 + n3 + n4 + n5 + n6) / 6; 
                break;
        }
    }

    pt = (float) (p1 + p2 + p3 + p4 + p5) / 5;

    printf("Los promedios parciales son: %f, %f, %f, %f, %f.\n", p1,p2,p3,p4,p5);
    printf("El promedio total es: %f\n", pt);

    return 0;
}
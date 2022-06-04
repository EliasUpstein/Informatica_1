#include <stdio.h>

int main()
{
    int n = 0;

    printf("Ingrese un número entero del 1 al 7:\n");
    fflush(stdin);
    scanf("%d", &n);

    switch (n)
    {
        case 1:
            printf("Domingo\n");
            break;
        case 2:
            printf("Lunes\n");
            break;
        case 3:
            printf("Martes\n");
            break;
        case 4:
            printf("Miércoles\n");
            break;
        case 5:
            printf("Jueves\n");
            break;
        case 6:
            printf("Viernes\n");
            break;
        case 7:
            printf("Sábado\n");
            break;
        default:
            printf("Error, número inválido\n");
        break;
    }
    return 0;
}
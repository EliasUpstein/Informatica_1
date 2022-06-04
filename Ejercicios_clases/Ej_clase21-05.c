/* Crear un menú que tenga 3 opciones (recta, parábola, fin)
El usuario deberá elegir qúe función usar y enviar los valores de a,b y c
Imprimir en pantalla 100 valores de la función elegida*/

#include <stdio.h>

void lineal(void);
void cuadratica(void);

int main()
{
    int opc;

    printf("Ingrese la opción deseada:\n1)Recta: y=mx+b\n2)Parábola: y=ax^2+bx+c\n3)Fin\n");
    fflush(stdin);
    scanf("%d", &opc);

    switch (opc)
    {
        case 1:
            lineal();
            break;
        case 2:
            cuadratica();
            break;
        case 3:
            break;
        default:
            printf("Error. Opción inválida");
            break;
    }
    return 0;
}

void lineal()
{
    float m, b;

    printf("Ingrese el valor de m:\n");
    fflush(stdin);
    scanf("%f", &m);

    printf("Ingrese el valor de b:\n");
    fflush(stdin);
    scanf("%f",&b);

    for (int i = 0; i <= 100; i++)
    {
        printf("x = %d, y = %f\n", i, ((m * i) + b));
    }
}

void cuadratica()
{
    float a, b, c;

    printf("Ingrese el valor de a:\n");
    fflush(stdin);
    scanf("%f", &a);

    printf("Ingrese el valor de b:\n");
    fflush(stdin);
    scanf("%f", &b);

    printf("Ingrese el valor de c:\n");
    fflush(stdin);
    scanf("%f", &c);

    for (int i = 0; i <= 100; i++)
    {
        printf("x = %d, y = %f\n", i, ((a * a * i) + (b * i) + c));
    }
}
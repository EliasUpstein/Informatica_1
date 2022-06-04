/* Desarrollar programa que permita calcular el área de un triángulo. Recuerde que la
fórmula a utilizar es: area= (base*altura)/2), además valide que la base y la altura sean
mayores a cero. Al terminar imprima el resultado obtenido. */

#include <stdio.h>

int main(void)
{
    int base, altura; float area;

    printf("Introduzca el valor de la base: \n");
    fflush(stdin); 
    scanf("%d", &base);

    while(base <= 0)
    {
        printf("Por favor ingrese un valor positivo de la variable: "); 
        fflush(stdin);
        scanf("%d", &base);
    }

    printf("Introduzca el valor de la altura: \n");
    fflush(stdin); 
    scanf("%d", &altura);

    while(base <= 0)
    {
        printf("Por favor ingrese un valor positivo de la variable: ");
        fflush(stdin);
        scanf("%d", &altura);
    }

    area= (base * altura) / 2;
    printf("El area del triangulo ingresado es: %f\n", area);

    return 1;
}
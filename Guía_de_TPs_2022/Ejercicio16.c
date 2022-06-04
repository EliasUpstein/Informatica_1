/* Escribí un programa que le solicite al usuario su edad y la guarde en una variable. Que luego
solicite la cantidad de artículos comprados en una tienda y la guarde en otra variable.
Finalmente, mostrar en pantalla un valor de verdad (True o False) que indique si el usuario es
mayor de 18 años de edad y además compró más de 1 artículo. */

#include <stdio.h>

int main(void)
{
    int edad, articulos;

    printf("Ingrese su edad: ");
    fflush(stdin);
    scanf("%d", &edad);

    while (edad <= 0)
    {
        printf("\nIngrese una edad válida: ");
        fflush(stdin);
        scanf("%d", &edad);
    }
    
    printf("\nIngrese la cantidad de artículos comprados: ");
    fflush(stdin);
    scanf("%d", &articulos);

    while (articulos < 0)
    {
        printf("\nIngrese la cantidad de artículos válida: ");
        fflush(stdin);
        scanf("%d", &articulos);
    }

    if (edad > 18 && articulos > 1)
        printf("\nVerdadero: el usuario es mayor de 18 años y compró más de 1 artículo.\n");
    else
        printf("\nFalso: no se cumplen las condiciones establecidas.\n");
    
    return 0;
}
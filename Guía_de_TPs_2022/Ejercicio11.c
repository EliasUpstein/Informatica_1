/* Escribí un programa que solicite al usuario dos números y los almacene en dos variables. En
otra variable, almacená el resultado de la suma de esos dos números y luego mostrá ese
resultado en pantalla.
A continuación, el programa debe solicitar al usuario que ingrese un tercer número, el cual se
debe almacenar en una nueva variable. Por último, mostrá en pantalla el resultado de la
multiplicación de este nuevo número por el resultado de la suma anterior. */

#include <stdio.h>

int main(void)
{
    float numero1, numero2, numero3, suma, producto;

    printf("Ingrese el primer número: ");
    fflush(stdin);
    scanf("%f", &numero1);

    printf("\nIngrese el segundo número: ");
    fflush(stdin);
    scanf("%f", &numero2);

    suma = numero1 + numero2;

    printf("\nSuma de los números ingresados: %f\n", suma);

    printf("Ingrese el tercer número: ");
    fflush(stdin);
    scanf("%f", &numero3);

    producto = numero3 * suma;

    printf("\nProducto de la suma y el último valor: %f\n", producto);

    return 0;
}
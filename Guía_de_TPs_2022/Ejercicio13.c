/* Escribí un programa que solicite al usuario el ingreso de una temperatura en escala Fahrenheit
(debe permitir decimales) y le muestre el equivalente en grados Celsius. La fórmula de
conversión que se usa para este cálculo es: _Celsius = (5/9) * (Fahrenheit-32) */

#include <stdio.h>

int main(void)
{
    float gradosF;

    printf("Ingrese la temperatura en grados Fahrenheit: ");
    fflush(stdin);
    scanf("%f", &gradosF);

    printf("\nTemperatura en grados Celsius: %f\n", ((5 * gradosF - 160)/9));

    return 0;
}
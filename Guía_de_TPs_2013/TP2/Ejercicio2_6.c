/* Modifique el programa 2.2. para que el mismo transforme y muestre la
temperatura ingresada en grados Celsius, en grados Fahrenheit.
(Recordar ºC = 5/9 * [ºF-32]) */

#include <stdio.h>

int main(void)
{
    float gradosC, gradosF;

    printf("Ingrese la temperatura en grados Celsius:\n");
    fflush(stdin);
    scanf("%f", &gradosC);

    gradosF = (gradosC * 9/5) + 32;

    printf("Temperatura en grados Celsius: %f\nTemperatura en grados Fahrenheir: %f\n", gradosC, gradosF);

    return 0;
}
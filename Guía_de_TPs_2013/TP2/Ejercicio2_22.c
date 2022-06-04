/* Elabore un programa donde ingresan dos valores reales y el símbolo de la
operación (‘+’, ‘-’, ‘*’, ‘/’). Se deberá presentar por pantalla, los datos
ingresados, la operación y el resultado. Si el símbolo utilizado no correspondiera
a ninguna de las cuatro operaciones deberá presentar un mensaje de
“Operación NO Válida”. (El programa deberá resolverse mediante el uso de
la estructura switch). */ 

#include <stdio.h>

int main()
{
	float n1,n2,res;
	char op;
	
	printf("Introduzca un numero:\n");
    fflush(stdin);
	scanf("%f", &n1);
	
	printf("Introduzca otro numero:\n");
    fflush(stdin);
	scanf("%f", &n2);
	
	printf("Introduzca la operaciónn deseada. Debe ser alguna de las siguientes:\n");
	printf(" +,-,*,/.\n");
	scanf(" %c", &op);
	
    switch (op)
    {
        case '+':
            res = n1 + n2;
            break;
        case '-':
            res = n1 - n2;
            break;
        case '*':
            res = n1 * n2;
            break;
        case '/':
            res = n1 / n2;
            break;
        default:
            printf("\nOperación NO válida.");
            return 0;
    }

    printf("\nEl primer número es %f, el segundo número es %f y la operacion es %c .\n", n1,n2,op);
    printf("El total es %f\n", res);

    return 0;
}

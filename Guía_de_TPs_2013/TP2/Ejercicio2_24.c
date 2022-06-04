/* Modifique el programa anterior de manera que lo que ingrese sean dos números
complejos. (NO se puede emplear la biblioteca cuyas definiciones están en el archivo
header <complex.h>. El programador podrá determinar la forma de ingreso 
de los datos y egreso de la información). */

#include <stdio.h>

int main()
{
	float r1,r2,i1,i2,resr,resi;
	char op;
	
	printf("Introduzca la componente real del primer número:\n");
    fflush(stdin);
	scanf("%f", &r1);

    printf("Introduzca la componente imaginaria del primer número:\n");
    fflush(stdin);
	scanf("%f", &i1);
	
	printf("Introduzca la componente real del segundo número:\n");
    fflush(stdin);
	scanf("%f", &r2);

    printf("Introduzca la componente imaginaria del segundo número:\n");
    fflush(stdin);
	scanf("%f", &i2);
	
	printf("Introduzca la operaciónn deseada. Debe ser alguna de las siguientes:\n");
	printf(" +,-,*,/.\n");
	scanf(" %c", &op);

    if (op == '/' && r2 == 0 && i2 == 0)
        printf("Operación NO Válida\nDivisión por Cero\n");
    else
    {
        switch (op)
        {
            case '+':
                resr = r1 + r2;
                resi = i1 + i2;
                break;
            case '-':
                resr = r1 - r2;
                resi = i1 - i2;
                break;
            case '*': //(r1+i1)*(r2+i2) = r1*r2 + r1*i2 + i1*r2 + i1*i2 (i*i = -1) => r: r1*r2 - i1*i2, i: i1*r2 + r1*i2
                resr = r1*r2 - i1*i2;
                resi = i1*r2 + r1*i2;
                break;
            case '/': //Multiplicar y dividir por el conjugado y desarrollar
                resr = (r1*r2 + i1*i2) / ((r2*r2)+(i2*i2));
                resi = (i1*r2 - r1*i2) / ((r2*r2)+(i2*i2));
                break;
            default:
                printf("Operación NO válida.\n");
                return 0;
        }

        printf("El primer número es %.2f+%.2fi, el segundo número es %.2f+%.2fi y la operacion es %c.\n", r1,i1,r2,i2,op);
        printf("El total es %.2f+%.2fi\n", resr,resi);
    }
    return 0;
}

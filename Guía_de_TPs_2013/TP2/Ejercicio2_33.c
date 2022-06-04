/* Escribir un programa que calcule el promedio de 10 valores numéricos
ingresados por teclado. */

#include <stdio.h>

int main (void)
{
	float n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,res;
	
	printf("Ingrese 10 valores numéricos\n");
	scanf("%f%f%f%f%f%f%f%f%f%f",&n1,&n2,&n3,&n4,&n5,&n6,&n7,&n8,&n9,&n10);
	
	res = (n1+n2+n3+n4+n5+n6+n7+n8+n9+n10)/10;
	
	printf("El promedio es %f\n", res);

    return 0;
}

/* Escribir una función que reciba un puntero a una secuencia de doubles y su
longitud como parámetros, y retorne el promedio aritmético de los valores
contenidos en él. */

#include <stdio.h>

#define N 8

double prom(double *s, int n);

int main(void)
{
	double s[N];

	printf("Introduzca una serie de %d números: \n",N);

	for(int i=0;i<N;i++)
	{
		setbuf(stdin,NULL);
		scanf("%lf",&s[i]);
	}

	printf("El promedio de los %d números ingresados en la cadena es: %.3lf\n",N,prom(s,sizeof(s)/sizeof(double)));
	
    return 0;
}

double prom(double *s, int n)
{
	double promedio = 0;

	for(int i=0;i<n;i++)
	{
		promedio += s[i];       //Suma todos los valores del vector
	}
	promedio = (promedio/n);    //Divide la suma por la cantidad de valores

	return promedio;
}
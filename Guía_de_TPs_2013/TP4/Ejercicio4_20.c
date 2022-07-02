/* a) Escribir una función que reciba como parámetros un puntero a una secuencia
de doubles y la cantidad de elementos que componen la secuencia, y devuelva al
máximo (o el mínimo) valor contenido en la misma.
b) ¿Cómo modificaría la interfaz de la función, para pasarle al módulo un token
de tipo enumerativo, que indique cuál de los dos extremos se desea calcular?
Sugerencia:
typedef enum { MAXIMO, MINIMO } t_extremo; */

#include <stdio.h>

#define N 8

double numMax(double *s, int n);

int main(void)
{
	double s[N];

	printf("Introduzca una serie de %d números:\n",N);

	for(int i=0;i<N;i++)
	{
		setbuf(stdin,NULL);
		scanf("%lf",&s[i]);
	}

	printf("El máximo número ingresado en la cadena fue: %0.2lf\n",numMax(s,sizeof(s)/sizeof(double)));

	return 0;
}

double numMax(double *s, int n)
{
	int i=0;
	double Max = s[i];  //Inicializa el máximo en el primer valor del vector

	for(i=0;i<n;i++)
	{
		if(s[i] > Max)
			Max=s[i];
	}
	return Max;
}
/* Escribir un programa donde ingresan por teclado dos valores que son
almacenados en las variables A y B del mismo tipo. El programa deberá
intercambiar los valores de las mismas y mostrar por pantalla los valores
ingresados y luego del intercambio*/


#include <stdio.h>

int main (){
	
	float vA, vB, aux;
	
	printf("Ingrese la primera variables:\n");
	scanf("%f", &vA);
	
	printf("Ingrese la segunda variable\n");
	scanf("%f", &vB);
	
	aux = vA;
	vA = vB;
	vB = aux;
	
	printf("\nLuego del cambio,\nLa primera variable es: %f", vA);
	printf("\nLa segunda variable es: %f", vB);
	
	return 0;
}

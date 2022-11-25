/*
 *  dado.c
 *
 *  Ejercicio 3.3
 *
 *  Autor: Leandro Beretta <lea.beretta@gmail.com>
 *
 *  Informática I - UTN.BA
 *
 */     

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Se incluye .h propios */

#include "dado.h"
#include "util.h"

int main() {

	int dividendo, divisor;
	
	/* Se limpia la terminal */
	system(CLEAR);
	
	/* Se imprime en pantalla un titulo segun el define TITULO */
	printf(TITULO);
	
	/*  
	 * Se coloca este if para tener la posibilidad de explicar el operador %,
	 * luego se cambia EXPLICAR_MODULO a FALSE para que luego de explicarlo
	 * no siga ejecutando esa parte en las proximas veces que ejecute el programa
	 * 
	 */
	
	if (EXPLICAR_MODULO == TRUE) {

		/*
	 	 * Ingresar valores para hacer la operación modulo (%)
	 	 *
	 	 */

		printf("\nIngresar dividendo: ");
		scanf("%d", &dividendo);

		printf("\nIngresar divisor: ");
		scanf("%d", &divisor);
	
	
		/*
		 * Se realiza la operación modulo, la cual nos da el resto de la división
		 *
	 	 */

		printf("\nResto de la division: %d \n", dividendo % divisor);
	
	}

	/*
	 * La función srand sirve para cambiar el numero base con el que la funcion
	 * rand genera el numero aleatorio, debe llamarse una sola vez en el programa
	 *
	 * srand recibe como parametro un valor llamado seed, que es el valor base
	 * nombrado anteriormente, ente este caso usamos la hora actual provista
	 * por la funcion time()
	 *
	 * Notar que el valor retornado por time() es casteado a unsigned, debido a que
	 * time() puede retornar -1 si no le es posible entregar la hora actual
	 *
	 */

	srand((unsigned) time(NULL));
	
	/*
	 * Se utiliza la funcion tirarDado y se imprime su resultado
	 *
	 */

	printf("\nResultado de tirar un dado: %d \n\n", tirarDado());

	return 0;
}

int tirarDado() {
	return generarValorAleatorio(VALOR_MIN_DADO, VALOR_MAX_DADO);
}

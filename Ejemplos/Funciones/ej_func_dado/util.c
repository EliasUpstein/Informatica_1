/*
 *  util.c
 *
 *  Ejercicio 3.3
 *
 *  Autor: Leandro Beretta <lea.beretta@gmail.com>
 *
 *  Informática I - UTN.BA
 *
 */ 

#include <stdlib.h>
#include "util.h"

int generarValorAleatorio(int valorMin, int valorMax) {

	/* Defino variables locales a la funcion generarValorAleatorio */

	int valorAleatorio;

	/*
	 * Se genera el valor aleatorio entre un valor minimo y un valor maximo 
	 * 
	 * Limites: valorMin <= valorAleatorio <= valorMax
	 *
	 */

	valorAleatorio = rand() % (valorMax - valorMin + 1) + valorMin;

	return valorAleatorio;
} 

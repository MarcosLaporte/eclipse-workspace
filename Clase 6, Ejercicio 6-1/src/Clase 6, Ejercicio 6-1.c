/*
 ============================================================================
 Name        : Ejercicio 6-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Disponemos de dos variables numéricas (a y b).
	Realizar un algoritmo que permita el intercambio de valores de dichas variables.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int a;
	int b;
	a = 14;
	b = 6;

	printf("a = %d / b = %d\n", a, b);

	int aux;

	aux = b;
	b = a;
	a = aux;

	printf("\na = %d / b = %d", a, b);

	return 0;
}

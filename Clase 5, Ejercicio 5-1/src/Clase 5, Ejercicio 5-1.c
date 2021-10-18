/*
 ============================================================================
 Name        : Ejercicio 5-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*===========================================================================
Consigna:
	Pedir el ingreso de 5 números. Mostrarlos y calcular la sumatoria de los mismos.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeros[T];
	int suma;

	PedirVectorEntero(numeros, T);
	MostrarVectorEntero(numeros, T);
	suma = SumarVectores(numeros, T);

	printf("\n\nLa suma de los números es: %d.", suma);

	return 0;
}

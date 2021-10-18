/*
 ============================================================================
 Name        : Ejercicio 4-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un n�mero.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int resultado;

	numero = PedirEntero("Ingrese un n�mero para calcular su factorial: ", 0, 12);
	resultado = CalcularFactorial(numero);

	printf("El factorial del n�mero es: %d", resultado);
	return 0;
}

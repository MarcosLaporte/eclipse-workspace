/*
 ============================================================================
 Name        : Ejercicio 1-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar dos n�meros enteros, sumarlos y mostrar el resultado.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int primerNumero;
	int segundoNumero;
	int suma;

	printf("Ingrese un n�mero: ");
	scanf("%d", &primerNumero);
	printf("Ingrese otro n�mero: ");
	scanf("%d", &segundoNumero);

	suma = primerNumero + segundoNumero;
	printf("La suma de %d y %d es %d.", primerNumero, segundoNumero, suma);
	return 0;
}

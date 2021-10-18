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
	Ingresar dos números enteros, sumarlos y mostrar el resultado.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int primerNumero;
	int segundoNumero;
	int suma;

	printf("Ingrese un número: ");
	scanf("%d", &primerNumero);
	printf("Ingrese otro número: ");
	scanf("%d", &segundoNumero);

	suma = primerNumero + segundoNumero;
	printf("La suma de %d y %d es %d.", primerNumero, segundoNumero, suma);
	return 0;
}

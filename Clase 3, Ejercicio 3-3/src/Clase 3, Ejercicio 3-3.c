/*
 ============================================================================
 Name        : Ejercicio 3-3
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Crear una función que pida el ingreso de un entero y lo retorne.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int PedirEntero(void);

int main(void){
	setbuf(stdout, NULL);

	int numero;

	numero = PedirEntero();

	printf("El entero ingresado es %d.", numero);

	return 0;
}

int PedirEntero(void){
	int numeroIngresado;

	printf("Ingrese un entero: ");
	scanf("%d", &numeroIngresado);

	return numeroIngresado;
}

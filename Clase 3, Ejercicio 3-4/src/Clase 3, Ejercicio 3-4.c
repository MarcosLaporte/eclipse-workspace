/*
 ============================================================================
 Name        : Ejercicio 3-4
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Especializar la función anterior para que permita validar el entero
	ingresado en un rango determinado.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h" //Acá está el prototipo de "PedirEntero"

int main() {
	setbuf(stdout, NULL);

	int nota;
	int legajo;

	nota = PedirEntero("Ingrese su nota: ", 1, 10);
	legajo = PedirEntero("Ingrese su legajo: ", 0, 1000);

	printf("Su nota es %d.\n", nota);
	printf("Su legajo es %d.", legajo);

	return 0;
}

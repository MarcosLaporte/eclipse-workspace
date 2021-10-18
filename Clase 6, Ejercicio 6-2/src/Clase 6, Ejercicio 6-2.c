/*
 ============================================================================
 Name        : Ejercicio 6-2
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
	Necesito generar un listado de los números positivos de manera creciente y
	negativos de manera decreciente. (Como máximo 5 estructuras repetitivas)
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeros[T] = {0};

//	PedirArrayEnteroSec(numeros, T, "Ingrese un entero: ", "Ingrese un entero entre -1000 y 1000: ", -1000, 1000);

	OrdenarPositivosCreciente(numeros, T);
	OrdenarNegativosDecreciente(numeros, T);

	return 0;
}

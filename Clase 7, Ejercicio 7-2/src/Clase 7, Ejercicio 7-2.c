/*
 ============================================================================
 Name        : Ejercicio 7-2
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Dados 3 vectores paralelos de tipo entero:
		¬Cargar el vector A y B de manera secuencial.
		¬El tercer vector C, deberá cargarse con el mayor de los elementos del mismo componente.
		¬Mostrar los 3 vectores, ordenados de menor a mayor por el vector C
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

	int vectorA[T] = {8,25,9,10,3};
	int vectorB[T] = {7,10,25,26,0};
	int vectorC[T];

//	PedirDosArrayEnteros(vectorA, vectorB, T);
	MayorNumero(vectorA, vectorB, vectorC, T);
	MostrarTresArray(vectorA, vectorB, vectorC, T);
	return 0;
}

/*
 ============================================================================
 Name        : Ejercicio 5-2
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Pedir el ingreso de 10 n�meros enteros entre -1000 y 1000. Determinar:
		�Cantidad de positivos y negativos.
		�Sumatoria de los pares.
		�El mayor de los impares.
		�Listado de los n�meros ingresados.
		�Listado de los n�meros pares.
		�Listado de los n�meros de las /posiciones\ impares.
	Se deber�n utilizar funciones y vectores.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int enteros[T]/* = {7,-8,-96,23,10,-503,780,920,501,-687}*/;
	int sumaPares;
	int hayPares;
	int mayorImpares;
	int hayImpares;

	PedirArrayEnteroSec(enteros, T, "Ingrese un entero: ", "ERROR! Ingrese un entero entre -1000 y 1000: ", -1000, 1000);

	ContadorPosYNeg(enteros, T);

	sumaPares = SumarPares(enteros, T, &hayPares);
	if(hayPares != 1){
		printf("No se ingresaron n�meros pares.\n");
	}else{
		printf("La suma de los n�meros pares es %d.\n", sumaPares);
	}

	mayorImpares = MayorImpares(enteros, T, &hayImpares);
	if(hayImpares != 1){
		printf("No se ingresaron n�meros impares.\n");
	}else{
		printf("El mayor de los n�meros impares es %d.\n", mayorImpares);
	}

	MostrarArrayEntero("Los enteros ingresados fueron: ", enteros, T);

	MostrarPares("Los pares ingresados fueron: ", enteros, T);

	MostrarNumerosPosicionesImpares(enteros, T);

	return 0;
}

/*
 ============================================================================
 Name        : Ejercicio 2-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar 5 n�meros enteros calcular y mostrar el promedio de los n�meros.
	Probar la aplicaci�n con distintos valores.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i;
	int numeroIngresado;
	int suma;
	float promedio;

	suma = 0;

	for(i = 0; i < 5; i++){
		printf("Ingrese un n�mero: ");
		scanf("%d", &numeroIngresado);
		suma += numeroIngresado;
	}

	promedio = (float)suma / i;
	printf("El promedio de los n�meros ingresados es %.2f.", promedio);

	return 0;
}

/*
 * Biblioteca.c
 *
 *  Created on: 6 sep. 2021
 *      Author: Marcos
 */

#include "Biblioteca.h"

int PedirEntero(char mensaje[], int min, int max){
	int numeroIngresado;

	printf("%s", mensaje); //Es necesario para que muestre el mensaje especificado.
	scanf("%d", &numeroIngresado);
	while(numeroIngresado < min || numeroIngresado > max){
		printf("Ingrese un número entre %d y %d: ", min, max);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}

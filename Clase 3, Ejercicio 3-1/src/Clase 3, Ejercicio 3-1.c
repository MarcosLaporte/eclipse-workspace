/*
 ============================================================================
 Name        : Ejercicio 3-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Crear una función que muestre por pantalla el número flotante que recibe como parámetro.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

float PedirNumero(void); //Prototipo; devuelve un float, y no recibe nada.

int main(void) {
	setbuf(stdout, NULL);

	float numeroIngresado;

	numeroIngresado = PedirNumero(); //Igualo la variable de main a la nueva función.

	printf("El número flotante ingresado es: %f.", numeroIngresado);

	return 0;
}

float PedirNumero(void){
	float numero;

	printf("Ingrese un número: ");
	scanf("%f", &numero);

	return numero;
}

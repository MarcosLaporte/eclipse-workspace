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
	Crear una funci�n que muestre por pantalla el n�mero flotante que recibe como par�metro.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

float PedirNumero(void); //Prototipo; devuelve un float, y no recibe nada.

int main(void) {
	setbuf(stdout, NULL);

	float numeroIngresado;

	numeroIngresado = PedirNumero(); //Igualo la variable de main a la nueva funci�n.

	printf("El n�mero flotante ingresado es: %f.", numeroIngresado);

	return 0;
}

float PedirNumero(void){
	float numero;

	printf("Ingrese un n�mero: ");
	scanf("%f", &numero);

	return numero;
}

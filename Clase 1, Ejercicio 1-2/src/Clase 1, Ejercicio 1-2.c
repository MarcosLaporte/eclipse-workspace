/*
 ============================================================================
 Name        : Ejercicio 1-2
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar 3 números y mostrar cuál de los tres es el mayor.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	float primerNumero;
	float segundoNumero;
	float tercerNumero;

	printf("Ingrese el primer número: ");
	scanf("%f", &primerNumero);
	printf("Ingrese el segundo número: ");
	scanf("%f", &segundoNumero);
	printf("Ingrese el tercer número: ");
	scanf("%f", &tercerNumero);

	if(primerNumero > segundoNumero && primerNumero > tercerNumero){
		printf("El mayor de los números es el primero.");
	}else{
		if(segundoNumero > primerNumero && segundoNumero > tercerNumero){
			printf("El mayor de los números es el segundo.");
		}else{
			if(tercerNumero > primerNumero && tercerNumero > segundoNumero){
					printf("El mayor de los números es el tercero.");
			}
		}
	}

	return 0;
}

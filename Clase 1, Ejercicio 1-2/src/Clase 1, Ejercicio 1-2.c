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
	Ingresar 3 n�meros y mostrar cu�l de los tres es el mayor.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	float primerNumero;
	float segundoNumero;
	float tercerNumero;

	printf("Ingrese el primer n�mero: ");
	scanf("%f", &primerNumero);
	printf("Ingrese el segundo n�mero: ");
	scanf("%f", &segundoNumero);
	printf("Ingrese el tercer n�mero: ");
	scanf("%f", &tercerNumero);

	if(primerNumero > segundoNumero && primerNumero > tercerNumero){
		printf("El mayor de los n�meros es el primero.");
	}else{
		if(segundoNumero > primerNumero && segundoNumero > tercerNumero){
			printf("El mayor de los n�meros es el segundo.");
		}else{
			if(tercerNumero > primerNumero && tercerNumero > segundoNumero){
					printf("El mayor de los n�meros es el tercero.");
			}
		}
	}

	return 0;
}

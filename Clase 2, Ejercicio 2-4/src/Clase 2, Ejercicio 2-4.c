/*
 ============================================================================
 Name        : Ejercicio 2-4
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar 5 caracteres e informar cuantas letras p (min�sculas) se ingresaron.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i;
	char caracter;
	int contP;

	contP = 0;

	for(i = 0; i < 5; i++){
		printf("Ingrese un caracter: ");
		fflush(stdin);
		scanf("%c", &caracter);

		if(caracter == 'p'){
			contP++;
		}
	}

	printf("Se ingresaron %d letras 'p' min�scula.", contP);

	return 0;
}

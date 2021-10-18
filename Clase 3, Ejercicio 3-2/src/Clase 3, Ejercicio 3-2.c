/*
 ============================================================================
 Name        : Ejercicio 3-2
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Crear una funci�n que permita determinar si un n�mero es par o no.
La funci�n retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
===========================================================================*/
#include <stdio.h>
#include <stdlib.h>

int ParOImpar(void);

int main(void){
	setbuf(stdout, NULL);

	float numero;

	numero = ParOImpar();

	if(numero == 1){
		printf("Es par.");
	}else{
		printf("Es impar.");
	}

	return 0;
}

int ParOImpar(void){
	int numeroIngresado;
	int retorno;

	printf("Ingrese un n�mero: ");
	scanf("%d", &numeroIngresado);

	if(numeroIngresado%2 == 0){
		retorno = 1;
	}else{
		retorno = 0;
	}

	return retorno;
}

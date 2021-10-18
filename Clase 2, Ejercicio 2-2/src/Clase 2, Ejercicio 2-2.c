/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar 10 números enteros, distintos de cero. Mostrar:
    ¬ Cantidad de pares e impares.
    ¬ El menor número ingresado.
    ¬ De los pares el mayor número ingresado.
    ¬ Suma de los positivos.
    ¬ Producto de los negativos.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i;
	int numeroIngresado;
	int contPares;
	int contImpares;
	int numeroMenor;
	int mayorPar;
	int acumPositivos;
	int prodNegativos;

	contPares = 0;
	contImpares = 0;
	numeroMenor = 0;
	mayorPar = 0;
	acumPositivos = 0;
	prodNegativos = 1;

	for(i = 0; i < 10; i++){
		printf("Ingrese un número: ");
		scanf("%d", &numeroIngresado);

		if(numeroIngresado%2 == 0){
			contPares++;
			if(numeroIngresado > mayorPar){
				mayorPar = numeroIngresado;
			}
		}else{
			contImpares++;
		}

		if(numeroMenor == 0 || numeroIngresado < numeroMenor){
			numeroMenor = numeroIngresado;
		}

		if(numeroIngresado < 0){
			prodNegativos *= numeroIngresado;
		}else{
			acumPositivos += numeroIngresado;
		}
	}

	printf("a) La cantidad de pares e impares es:\nPares: %d.\nImpares: %d.\n", contPares, contImpares);
	printf("b) El menor número ingresado es: %d.\n", numeroMenor);
	printf("c) El mayor número par ingresado es: %d.\n", mayorPar);
	printf("d) La suma de los positivos es: %d.\n", acumPositivos);
	if(prodNegativos == 1){
		prodNegativos = 0;
	}
	printf("e) El producto de los negativos es: %d.", prodNegativos);

	return 0;
}

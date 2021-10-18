/*
 * Operaciones.c
 *      Author: Marcos
 */

#include "Operaciones.h"
#include <stdio.h>
#include <stdlib.h>

float PedirFlotante(char mensaje[]){
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}

float SumarNumeros(float num1, float num2){
	float suma;

	suma = num1 + num2;

	return suma;
}

float RestarNumeros(float num1, float num2){
	float resta;

	resta = num1 - num2;

	return resta;
}

int DividirNumeros(float num1, float num2, float* refCociente){
	float divide;
	divide = 1;

	if(num2 == 0){
		divide = 0;
	}

	*refCociente = num1/num2;

	return divide;
}

float MultiplicarNumeros(float num1, float num2){
	float multiplicacion;

	multiplicacion = num1 * num2;

	return multiplicacion;
}

float CalcularFactorial(float num){

	float factorial;
	int i;

	factorial = 1;

	if(num < 0 || num - (int)num != 0){
		factorial = 0;
	}else{
		if(num > 0){
			for(i = num; i > 0; i--){
				factorial = factorial * i;
			}
		}
	}

	return factorial;
}

/*
 * Biblioteca.c
 *
 *  Created on: 6 sep. 2021
 *      Author: Marcos
 */

#include "Biblioteca.h"

int Sumar1(int num1, int num2){
	int suma;

	suma = num1 + num2;

	return suma;
}

int Sumar2(void){
	int num1;
	int num2;
	int suma;

	printf("\nIngrese el primer número: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo número: ");
	scanf("%d", &num2);

	suma = num1 + num2;

	return suma;
}

void Sumar3(int num1, int num2){
	int suma;

	suma = num1 + num2;
	printf("El resultado de la tercer suma es: %d.\n", suma);
}

void Sumar4(void){
	int num1;
	int num2;
	int suma;

	printf("\nIngrese el primer número: ");
	scanf("%d", &num1);
	printf("Ingrese el segundo número: ");
	scanf("%d", &num2);

	suma = num1 + num2;
	printf("El resultado de la cuarta suma es: %d.\n", suma);
}


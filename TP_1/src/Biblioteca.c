/*
 * Biblioteca.c
 *      Author: Marcos
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Biblioteca.h"
#include "Operaciones.h"

int PedirEntero(char mensaje[], char mensajeError[], int min, int max){
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);
	while(numero < min || numero > max){
		printf("%s", mensajeError);
		scanf("%d", &numero);
	}

	return numero;
}

int PedirOpcion(float primerNumero, float segundoNumero, int flagA, int flagB){
	int opcion;

	if(flagA == 0){
		printf("\n~1. Ingresar 1er operando. (A = x)\n");
	}else{
		printf("\n~1. Ingresar 1er operando. (A = %.2f)\n", primerNumero);
	}
	if(flagB == 0){
		printf("~2. Ingresar 2do operando. (B = y)\n");
	}else{
		printf("~2. Ingresar 2do operando. (B = %.2f)\n", segundoNumero);
	}
	printf("~3. Calcular operaciones.\n");
	printf("~4. Informar resultados.\n");
	printf("~5. Salir.\n");
	opcion = PedirEntero("Elija una opción: ", "ERROR. Elija una opción entre 1 y 5: ", 1, 5);

	return opcion;
}

// Resultados------------------------------------------------

void ResultadoSuma(float num1, float num2, float suma){
	if(num2 < 0){
		printf("\na) El resultado de %.2f+(%.2f) es: %.2f\n", num1, num2, suma);
	}else{
		printf("\na) El resultado de %.2f+%.2f es: %.2f\n", num1, num2, suma);
	}
}

void ResultadoResta(float num1, float num2, float resta){
	if(num2 < 0){
		printf("b) El resultado de %.2f-(%.2f) es: %.2f\n", num1, num2, resta);
	}else{
		printf("b) El resultado de %.2f-%.2f es: %.2f\n", num1, num2, resta);
	}
}

void ResultadoDivision(float num1, float num2, float division){
	if(DividirNumeros(num1, num2, &division) == 0){
		printf("c) ERROR! No se puede dividir por cero.\n");
	}else{
		if(num2 < 0){
			printf("c) El resultado de %.2f/(%.2f) es: %.2f\n", num1, num2, division);
		}else{
			printf("c) El resultado de %.2f/%.2f es: %.2f\n", num1, num2, division);
		}
	}
}

void ResultadoMultiplicacion(float num1, float num2, float multiplicacion){
	if(num2 < 0){
		printf("d) El resultado de %.2f*(%.2f) es: %.2f\n", num1, num2, multiplicacion);
	}else{
		printf("d) El resultado de %.2f*%.2f es: %.2f\n", num1, num2, multiplicacion);
	}
}

void ResultadoFactorial(float num, float factorial){
	if(factorial == 0){
		printf("e) ERROR! Sólo se puede calcular el factorial de números enteros y positivos.\n");
	}else{
		if(num > 12){
			printf("e) ERROR! No se pudo calcular el factorial del número %.2f ya que es mayor a 12.\n", num);
		}else{
			printf("e) El factorial de %.2f es: %.2f\n", num, factorial);
		}
	}
}

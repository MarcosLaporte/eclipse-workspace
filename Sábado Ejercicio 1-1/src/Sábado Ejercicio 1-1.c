/*
 ============================================================================
 Name        : Sábado Ejercicio 1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
		a) El promedio de los números positivos.
		b) El promedio de los números negativos.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	char seguir;
	int numeroIngresado;
	int acumPos;
	int contPos;
	int acumNeg;
	int contNeg;
	float promPos;
	float promNeg;

	acumPos = 0;
	contPos = 0;
	acumNeg = 0;
	contNeg = 0;

	do{
		printf("Ingrese un número entero: ");
		scanf("%d", &numeroIngresado);

		if(numeroIngresado < 0){
			acumNeg += numeroIngresado;
			contNeg++;
		}else{
			acumPos += numeroIngresado;
			contPos++;
		}

		printf("Desea continuar?: ");
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		while(!(seguir == 's' || seguir == 'n')){
			printf("Desea continuar? s/n: ");
			fflush(stdin);
			scanf("%c", &seguir);
			seguir = tolower(seguir);
		}
	}while(seguir == 's');

	promPos = (float)acumPos/contPos;
	promNeg = (float)acumNeg/contNeg;

	printf("a) El promedio de los números positivos es: %.2f.\n", promPos);
	printf("b) El promedio de los números negativos es: %.2f.", promNeg);

	return 0;
}

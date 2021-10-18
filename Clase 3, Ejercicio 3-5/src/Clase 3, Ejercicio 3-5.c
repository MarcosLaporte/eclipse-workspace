/*===========================================================================
 Nombre		: Ejercicio 3-5
 Autor		: Marcos Laporte
===========================================================================*/

/*===========================================================================
Consigna:
	Realizar un programa en donde se puedan utilizar los prototipos de
	la función Sumar en sus 4 combinaciones.
		¬int Sumar1(int, int);
		¬int Sumar2(void);
		¬void Sumar3(int, int);
		¬void Sumar4(void);
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int suma1;
	int num1Suma1;
	int num2Suma1;
	int suma2;
	int num1Suma3;
	int num2Suma3;

//	Función 1
	printf("Ingrese el primer número: ");
	scanf("%d", &num1Suma1);
	printf("Ingrese el segundo número: ");
	scanf("%d", &num2Suma1);
	suma1 = Sumar1(num1Suma1, num2Suma1);
	printf("El resultado de la primer suma es: %d.\n", suma1);

//	Función 2
	suma2 = Sumar2();
	printf("El resultado de la segunda suma es: %d.\n", suma2);

//	Función 3
	printf("\nIngrese el primer número: ");
	scanf("%d", &num1Suma3);
	printf("Ingrese el segundo número: ");
	scanf("%d", &num2Suma3);
	Sumar3(num1Suma3, num2Suma3);

//	Función 4
	Sumar4();

	return 0;
}


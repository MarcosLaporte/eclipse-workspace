/*===========================================================================
 Nombre		: Ejercicio 3-5
 Autor		: Marcos Laporte
===========================================================================*/

/*===========================================================================
Consigna:
	Realizar un programa en donde se puedan utilizar los prototipos de
	la funci�n Sumar en sus 4 combinaciones.
		�int Sumar1(int, int);
		�int Sumar2(void);
		�void Sumar3(int, int);
		�void Sumar4(void);
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

//	Funci�n 1
	printf("Ingrese el primer n�mero: ");
	scanf("%d", &num1Suma1);
	printf("Ingrese el segundo n�mero: ");
	scanf("%d", &num2Suma1);
	suma1 = Sumar1(num1Suma1, num2Suma1);
	printf("El resultado de la primer suma es: %d.\n", suma1);

//	Funci�n 2
	suma2 = Sumar2();
	printf("El resultado de la segunda suma es: %d.\n", suma2);

//	Funci�n 3
	printf("\nIngrese el primer n�mero: ");
	scanf("%d", &num1Suma3);
	printf("Ingrese el segundo n�mero: ");
	scanf("%d", &num2Suma3);
	Sumar3(num1Suma3, num2Suma3);

//	Funci�n 4
	Sumar4();

	return 0;
}


/*
 ============================================================================
 Name        : Ejercicio 5-3
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
	La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).
	Determinar el promedio de los positivos, y del menor de los negativos la suma de los
	antecesores	(Según la recta numérica de los reales, hasta llegar a cero).
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int numeros[T]={};
	int i;
	int menorNeg;
	int sumaImp;

	PedirVectorEntero(numeros);
	for(i=0; i < T; i++){
		printf("%d\n", numeros[i]);
	}
	PromPos(numeros, T);
	menorNeg = MenorNegativos(numeros, T);
	if(menorNeg == 0){
		printf("\nNo se ingresaron negativos.");
	}else{
		printf("\nEl menor negativo ingresado es: %d.", menorNeg);
		sumaImp = SumarAntecNeg(menorNeg);
		printf("\nLa suma de sus antecesores es: %d.", sumaImp);
	}


	return 0;
}

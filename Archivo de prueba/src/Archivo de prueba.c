#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#include "Input.h"

int main(void){
	setbuf(stdout, NULL);

	int array[5] = {76, 52, 7, 6, 5};
	int* pArray;

	pArray = array;

	getSequentialArrayInt(pArray, 5, "Ingrese un entero: ", "ERROR! Ingrese un entero entre 1 y 100: ", 1, 100);
/*
	for(int i = 0; i < 5; i++){
		printf("%d\n", *pArray+i);
	}					//Toma el primer valor y le suma i
	printf("-----------\n");
	for(int i = 0; i < 5; i++){
		printf("%d\n", *(pArray+i));
	}					//Muestra los valores en cada posición
								//Suma las direcciones de memoria
*/
	printf("-----------\n");
	for(int i = 0; i < 5; i++){
		printf("%d\n", pArray[i]);
	}				//Es lo mismo que el anterior, pero es más simple


//	Person people[T] = {{1, "Thiago", {24, 04, 2003}}, {2, "Ezequiel", {06, 07, 1978}},
//						{3, "Elias", {04, 06, 2002}}, {4, "Marcos", {8, 05, 2003}}};
//
//
//	for(int i = 0; i < T; i++){
//		printById(people, T, people[i].id);
//	}

	return 0;
}

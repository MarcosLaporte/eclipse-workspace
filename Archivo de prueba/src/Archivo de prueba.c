#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#include "Input.h"

int main(void){
	setbuf(stdout, NULL);

	int array[5] /*= {76, 52, 7, 6, 5}*/;
	int* pArray;

	pArray = array;

	getSequentialArrayInt(pArray, 5, "Ingrese un entero: ", "ERROR! Ingrese un entero entre 1 y 100: ", 1, 100);

/*	for(int i = 0; i < 5; i++){
		printf("%d\n", *pArray+i);
	}					//Toma el primer valor y le suma i
	printf("-----------\n");
	for(int i = 0; i < 5; i++){
		printf("%d\n", *(pArray+i));
	}					//Muestra los valores en cada posici�n
								//Suma las direcciones de memoria
*/	printf("-----------\n");
	for(int i = 0; i < 5; i++){
		printf("%d\n", pArray[i]);
	}				//Es lo mismo que el anterior, pero es m�s simple



	return 0;
}

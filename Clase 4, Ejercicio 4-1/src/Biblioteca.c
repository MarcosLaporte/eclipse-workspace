#include <stdio.h>
#include "Biblioteca.h"

int PedirEntero(char mensaje[], int min, int max){
	int numero;

	printf("%s", mensaje); //Imprime el mensaje especificado en el main
	scanf("%d", &numero);
	while(numero < min || numero > max){
		printf("Ingrese un número entre %d y %d: ", min, max);
		scanf("%d", &numero);
	}

	return numero;
}

int CalcularFactorial(int num){
	int factorial;

	if(num == 0){
		factorial = 1;
	}else{
		factorial = num * CalcularFactorial(num - 1);
	}	// n!	  =  n	*	(n-1)

	return factorial;
}

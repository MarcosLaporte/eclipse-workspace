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

float PedirFlotante(char mensaje[], int min, int max){
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);
	while(numero < min || numero > max){
		printf("Ingrese un número entre %d y %d: ", min, max);
		scanf("%f", &numero);
	}

	return numero;
}

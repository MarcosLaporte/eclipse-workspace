#include <stdio.h>
#include <ctype.h>
#include "Biblioteca.h"

void PedirArrayEnteroSec(int lista[], int tam, char mensaje[], char mensajeError[], int min, int max){
	int i;

	for(i = 0; i < tam; i++){
		printf("%s", mensaje);
		scanf("%d", &lista[i]);
		while(lista[i] < min || lista[i] > max){
			printf("%s", mensajeError);
			scanf("%d", &lista[i]);
		}
	}
	printf("\nLista:\n");
	for(i = 0; i < T; i++){
		printf("%d\n", lista[i]);
	}

}

int DeterminarPositividad(int numero){
	int signo;
	signo = 0;

	if(numero > 0){
		signo = 1;
	}else{
		if(numero < 0){
			signo = -1;
		}
	}

	return signo;
}

void OrdenarPositivosCreciente(int numeros[], int tam){
	int i;
	int flagSwap;
	int aux;

	if(numeros != NULL && tam >= 0){
		do{
			flagSwap = 0;
			for(i = 0; i < tam-1; i++){
				if(DeterminarPositividad(numeros[i]) == 1){
					if(numeros[i] > numeros[i+1]){
						flagSwap = 1;
						aux = numeros[i];
						numeros[i] = numeros[i+1];
						numeros[i+1] = aux;
					}
				}
			}
		}while(flagSwap);
		printf("\nPositivos ordenados:\n");
		for(i = 0; i <tam; i++){
			if(DeterminarPositividad(numeros[i]) == 1){
				printf("%d\n", numeros[i]);
			}
		}
	}
}

void OrdenarNegativosDecreciente(int numeros[], int tam){
	int i;
	int flagSwap;
	int aux;

	if(numeros != NULL && tam >= 0){
		do{
			flagSwap = 0;
			for(i = 0; i < tam-1; i++){
				if(DeterminarPositividad(numeros[i]) == -1){
					if(numeros[i] < numeros[i+1]){
						flagSwap = 1;
						aux = numeros[i];
						numeros[i] = numeros[i+1];
						numeros[i+1] = aux;
					}
				}
			}
		}while(flagSwap);
		printf("\nNegativos ordenados:\n");
		for(i = 0; i <tam; i++){
			if(DeterminarPositividad(numeros[i]) == -1){
				printf("%d\n", numeros[i]);
			}
		}
	}
}

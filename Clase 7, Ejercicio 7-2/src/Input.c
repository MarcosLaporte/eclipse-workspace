#include "Input.h"

#include <stdio.h>
#include <stdlib.h>

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

void MayorNumero(int primerLista[], int segundaLista[], int terceraLista[], int tam){
	int i;
	int j;

	for(i = 0; i < tam; i++){
		for(j = i; j < tam; j++){
			if(primerLista[i] < segundaLista[i]){
				terceraLista[i] = segundaLista[i];
			}else{
				terceraLista[i] = primerLista[i];
			}
		}
	}
}

void PedirDosArrayEnteros(int listaA[], int listaB[], int tam){
	int i;

	for(i = 0; i < tam; i++){
		listaA[i] = PedirEntero("Ingrese un entero para el vector A: ", "ERROR! Ingrese un entero entre -1000 y 1000: ", -1000, 1000);
		listaB[i] = PedirEntero("Ingrese un entero para el vector B: ", "ERROR! Ingrese un entero entre -1000 y 1000: ", -1000, 1000);
	}
}

void OrdenarVectoresPorUnVector(int vectorC[], int tam, int vectorA[], int vectorB[]){
	int flagSwap;
	int aux;

	if(vectorC != NULL && tam >= 0){
		do{
			flagSwap = 0;
			for(int i = 0; i < tam-1; i++){
				if(vectorC[i] > vectorC[i+1]){
					flagSwap = 1;
					aux = vectorC[i];
					vectorC[i] = vectorC[i+1];
					vectorC[i+1] = aux;
					aux = vectorA[i];
					vectorA[i] = vectorA[i+1];
					vectorA[i+1] = aux;
					aux = vectorB[i];
					vectorB[i] = vectorB[i+1];
					vectorB[i+1] = aux;
				}
			}
		}while(flagSwap);
	}
}

void MostrarTresArray(int listaA[], int listaB[], int listaC[], int tam){
	printf("\n%-10s%-10s%-10s\n", "Vector A", "Vector B", "Vector C");
	for(int i = 0; i < tam; i++){
		printf("%5d%10d%10d\n", listaA[i], listaB[i], listaC[i]);
	}
}

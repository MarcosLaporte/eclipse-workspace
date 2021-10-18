#include <stdio.h>
#include "Biblioteca.h"

void PedirVectorEntero(int lista[], int tam){
	int i;

	for(i = 0; i < tam; i++){
		printf("Ingrese un número: ");
		scanf("%d", &lista[i]);
	}
}

void MostrarVectorEntero(int lista[], int tam){
	int i;

	for(i = 0; i < tam; i++){
		printf("\n%d", lista[i]);
	}
}


int SumarVectores(int lista[], int tam){
	int suma;
	int i;
	suma = 0;

	for(i = 0; i < tam; i++){
		suma += lista[i];
	}

	return suma;
}

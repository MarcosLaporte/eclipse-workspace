#include <stdio.h>
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
}

void ContadorPosYNeg(int lista[], int tam){
	int i;
	int contPos;
	int contNeg;
	int flagCero;
	contPos = 0;
	contNeg = 0;
	flagCero = 0;

	for(i = 0; i < tam; i++){
		if(DeterminarPositividad(lista[i]) == 1){
			contPos++;
			flagCero = 1;
		}else{
			if(DeterminarPositividad(lista[i]) == -1){
				contNeg++;
				flagCero = 1;
			}
		}
	}

	if(flagCero == 0){
		printf("Solo se ingresaron ceros.\n");
	}else{
		printf("Se ingresaron %d positivos y %d negativos.\n", contPos, contNeg);
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

int SumarPares(int lista[], int tam, int* refPares){
	int suma;
	int i;
	suma = 0;

	for(i = 0; i < tam; i++){
		if(DeterminarParidad(lista[i]) == 1){
			suma += lista[i];
			*refPares = 1;
		}
	}

	return suma;
}

int DeterminarParidad(int numero){
	int esPar;
	esPar = 0;

	if(numero%2 == 0){
		esPar = 1;
	}

	return esPar;
}

int MayorImpares(int lista[], int tam, int* refImpar){
	int mayor;
	int i;
	int flagPrimero;

	for(i = 0; i < tam; i++){
		if(DeterminarParidad(lista[i]) == 0){
			*refImpar = 1;
			if(lista[i] > mayor || flagPrimero != 0){
				mayor = lista[i];
				flagPrimero = 0;
			}
		}
	}

	return mayor;
}

void MostrarArrayEntero(char mensaje[], int numero[], int tam){
	int i;

	printf("%s\n", mensaje);
	for(i = 0; i < tam; i++){
		printf("%d\n", numero[i]);
	}
}

void MostrarPares(char mensaje[], int numero[], int tam){
	int i;

	printf("%s\n", mensaje);
	for(i = 0; i < tam; i++){
		if(DeterminarParidad(numero[i]) == 1){
			printf("%d\n", numero[i]);
		}
	}
}

void MostrarNumerosPosicionesImpares(int lista[], int tam){
	int i;

	printf("Los números en las posiciones impares son: ");
	for(i = 0; i < tam; i++){
		if(DeterminarParidad(i) == 0){
			printf("\n%d", lista[i]);
		}
	}
}

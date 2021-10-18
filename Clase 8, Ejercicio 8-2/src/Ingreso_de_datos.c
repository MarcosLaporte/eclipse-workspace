#include "Ingreso_de_datos.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

void MostrarEntero(char mensaje[], int numero){
	printf("%s%d\n", mensaje, numero);
}

float PedirFlotante(char mensaje[], char mensajeError[], int min, int max){
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);
	while(numero < min || numero > max){
		printf("%s", mensajeError);
		scanf("%f", &numero);
	}

	return numero;
}

void MostrarFlotante(char mensaje[], float numero){
	printf("%s%f\n", mensaje, numero);
}

//Vectores
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

void PedirArrayEnteroAlea(int lista[], int tam, char mensaje[], char mensajeError[], int min, int max){
	int i;
	char seguir;

	do{
		printf("En qué posición desea ingresar el número?: ");
		scanf("%d", &i);
		while(i < 1 || i > tam){
			printf("Ingrese una posición entre 1 y %d: ", tam);
			scanf("%d", &i);
		}
		printf("%s", mensaje);
		scanf("%d", &lista[i-1]);
		while(lista[i-1] < min || lista[i-1] > max){
			printf("%s", mensajeError);
			scanf("%d", &lista[i-1]);
		}

		printf("Desea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		while(!(seguir == 's' || seguir == 'n')){
			printf("Si desea continuar escriba 's', si no, 'n': ");
			fflush(stdin);
			scanf("%c", &seguir);
			seguir = tolower(seguir);
		}
	}while(seguir == 's');
}

void MostrarArrayEntero(char mensaje[], int numero[], int tam){
	int i;

	printf("%s\n", mensaje);
	for(i = 0; i < tam; i++){
		printf("%d\n", numero[i]);
	}
}

void PedirArrayFlotanteSec(float lista[], int tam, char mensaje[], char mensajeError[], int min, int max){
	int i;

	for(i = 0; i < tam; i++){
		printf("%s", mensaje);
		scanf("%f", &lista[i]);
		while(lista[i] < min || lista[i] > max){
			printf("%s", mensajeError);
			scanf("%f", &lista[i]);
		}
	}
}

void PedirArrayFlotanteAlea(float lista[], int tam, char mensaje[], char mensajeError[], int min, int max){
	int i;
	char seguir;

	do{
		printf("En qué posición desea ingresar el número?: ");
		scanf("%d", &i);
		while(i < 1 || i > tam){
			printf("Ingrese una posición entre 1 y %d: ", tam);
			scanf("%d", &i);
		}
		printf("%s", mensaje);
		scanf("%f", &lista[i-1]);
		while(lista[i-1] < min || lista[i-1] > max){
			printf("%s", mensajeError);
			scanf("%f", &lista[i-1]);
		}

		printf("Desea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		while(!(seguir == 's' || seguir == 'n')){
			printf("Si desea continuar escriba 's', si no, 'n': ");
			fflush(stdin);
			scanf("%c", &seguir);
			seguir = tolower(seguir);
		}
	}while(seguir == 's');
}

void MostrarArrayFlotante(char mensaje[], float numero[], int tam){
	int i;

	printf("%s\n", mensaje);
	for(i = 0; i < tam; i++){
		printf("%f\n", numero[i]);
	}
}

void PedirCadena(char mensaje[], char input[]){
	printf("%s", mensaje);
	fflush(stdin);
	gets(input);
}

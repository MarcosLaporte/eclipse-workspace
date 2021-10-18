#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Biblioteca.h"

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

void PedirCadena(char mensaje[], char input[]){
	printf("%s", mensaje);
	fflush(stdin);
	gets(input);
}

void PedirDatosProducto(int* id, char* desc[50], int* nacion, int* tipo, float* precio, int* estado){
	*id = PedirEntero("Ingrese el ID del producto: ", "ERROR! Ingrese un ID entre 0 y 10000: ", 0, 10000);
	PedirCadena("Ingrese la descripción del producto: ", *desc);
	*nacion = PedirEntero("Ingrese la nacionalidad del producto (1: EEUU - 2: CHINA - 3: OTRO): ", "ERROR! Ingrese una nacionalidad entre 1 y 3 (1: EEUU - 2: CHINA - 3: OTRO): ", 1, 3);
	*tipo = PedirEntero("Ingrese el tipo de producto (1: IPHONE - 2: MAC - 3: IPAD - 4: ACCESORIOS): ", "ERROR! Ingrese un tipo entre 1 y 4 (1: IPHONE - 2: MAC - 3: IPAD - 4: ACCESORIOS): ", 1, 4);
	*precio = PedirFlotante("Ingrese el precio del producto: ", "ERROR! Ingrese un precio entre 1 y 5000: ", 1, 5000);
	*estado = CARGADO;
}

int AltaProducto(int id[], char desc[][50], int nacion[], int tipo[], float precio[], int estado[], int tam){
	int i;
	int retorno;
	retorno = VACIO;

	for(i = 0; i < tam; i++){
		if(estado[i] != CARGADO){
			PedirDatosProducto(id[i], desc[i], nacion[i], tipo[i], precio[i], estado[i]);
			retorno = CARGADO;
			break;
		}
	}
	return retorno;
}

void MostrarDatosProducto(int id[], char desc[][50], int nacion[], int tipo[], float precio[]){
	int i;
	char prodNacion[6];
	char prodTipo[11];


	for(i = 0; i < T; i++){
		switch(nacion[i]){
		case EEUU:
			strcpy(prodNacion, "EEUU");
			break;
		case CHINA:
			strcpy(prodNacion, "CHINA");
			break;
		case OTRO:
			strcpy(prodNacion, "OTRO");
			break;
		}

		switch(tipo[i]){
		case IPHONE:
			strcpy(prodTipo, "IPHONE");
			break;
		case MAC:
			strcpy(prodTipo, "MAC");
			break;
		case IPAD:
			strcpy(prodTipo, "IPAD");
			break;
		case ACCESORIOS:
			strcpy(prodTipo, "ACCESORIOS");
			break;
		}

		printf("\nID: %d - Descripción: %s - Nacionalidad: %s - Tipo: %s - Precio: %.2f\n",id[i],desc[i],prodNacion,prodTipo,precio[i]);
	}
}

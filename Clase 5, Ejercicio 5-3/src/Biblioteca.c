#include <stdio.h>
#include <ctype.h>
#include "Biblioteca.h"

void PedirVectorEntero(int lista[]){
	int i;
	char seguir;

	do{
		printf("En qué posición desea ingresar el número?: ");
		scanf("%d", &i);
		while(i < 1 || i > T){
			printf("Ingrese una posición entre 1 y 10: ");
			scanf("%d", &i);
		}
		printf("Ingrese un número: ");
		scanf("%d", &lista[i-1]);
		while(lista[i-1] == 0){
			printf("Ingrese un número DISTINTO a 0: ");
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

void PromPos(int lista[], int tam){
	int i;
	int contPos;
	int acumPos;
	float promedio;

	contPos = 0;
	acumPos = 0;

	for(i = 0; i < tam; i++){
		if(lista[i] > 0){
			contPos++;
			acumPos += lista[i];
		}
	}
	if(contPos == 0){
		promedio = 0;
	}else{
		promedio = (float)acumPos / contPos;
	}

	printf("\nEl promedio de los positivos es: %.2f", promedio);
}

int MenorNegativos(int lista[], int tam){
	int menor;
	int i;

	menor = 0;

	for (i = 0; i < tam; i++) {
		if(lista[i] < 0 && (menor == 0 || lista[i] < menor)){
			menor = lista[i];
		}
	}

	return menor;
}

int SumarAntecNeg(int menor){
	int suma;
	suma = 0;

	if(menor < 0){
		suma = menor + SumarAntecNeg(menor + 1);
	}

	return suma;
}

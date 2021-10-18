#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Biblioteca.h"

int PedirOpcion(void){
	int opcion;

		printf("———————————————————\n"
				"1-Inicializar\n"
				"2-Cargar\n"
				"3-Mostrar\n"
				"4-Calcular Promedio\n"
				"5-Ordenar\n"
				"6-Salir\n"
				"Elija una opción: ");
		scanf("%d", &opcion);
		while(opcion < 1 || opcion > 6){
			printf("———————————————————\n"
					"1-Inicializar\n"
					"2-Cargar\n"
					"3-Mostrar\n"
					"4-Calcular Promedio\n"
					"5-Ordenar\n"
					"6-Salir\n"
					"Elija una opción (0-6): ");
			scanf("%d", &opcion);
		}
	return opcion;
}

void MostrarOpcion(int opcion){
		switch(opcion){
		case 1:
			printf("Seleccionó la opción 1-Inicializar.\n");
			break;
		case 2:
			printf("Seleccionó la opción 2-Cargar.\n");
			break;
		case 3:
			printf("Seleccionó la opción 3-Mostrar.\n");
			break;
		case 4:
			printf("Seleccionó la opción 4-Calcular Promedio.\n");
			break;
		case 5:
			printf("Seleccionó la opción 5-Ordenar.\n");
			break;
		default:
			printf("Seleccionó la opción 6-Salir.\n");
		}
}

void InicializarEdad(int lista[]){
	int i;
	for(i = 0; i < T; i++){
		lista[i] = -1;
	}
}

void PedirVectorEntero(int lista[]){
	int i;
	char seguir;

	do{
		printf("En qué posición desea ingresar el número?: ");
		scanf("%d", &i);
		while(i < 1 || i > T){
			printf("Ingrese una posición entre 1 y %d: ", T);
			scanf("%d", &i);
		}
		printf("Ingrese una edad: ");
		scanf("%d", &lista[i-1]);
		while(lista[i-1] < 0 || lista[i-1] > 150){
			printf("Ingrese una edad válida (0-150): ");
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

void MostrarVectorEntero(int lista[], int tam){
	int i;
	printf("Las edades ingresadas fueron: \n");
	for(i = 0; i < tam; i++){
		printf("%d\n", lista[i]);
	}
}

void MostrarElementoVectorEntero(int lista[], int max){
	int puesto;
	printf("El número de qué puesto desea ver?: ");
	scanf("%d", &puesto);
	while(puesto < 1 || puesto > max){
		printf("Elija un puesto entre 1 y %d: ", max);
		scanf("%d", &puesto);
	}
	printf("La edad ingresada en el puesto %d es: %d\n", puesto, lista[puesto-1]);
}

float PromedioVectores(int lista[], int tam){
	int suma;
	int cont;
	float promedio;
	int i;
	suma = 0;
	cont = 0;

	for(i = 0; i < tam; i++){
		if(lista[i] != -1){
			suma += lista[i];
			cont++;
		}
	}

	if(cont == 0){
		promedio = 0;
	}else{
		promedio = (float)suma/cont;
	}

	return promedio;
}

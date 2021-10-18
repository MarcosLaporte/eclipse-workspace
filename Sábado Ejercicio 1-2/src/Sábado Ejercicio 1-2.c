/*
 ============================================================================
 Name        : Sábado Ejercicio 2
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden
	fue ingresado.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int i;
	float numeroIngresado;
	float numeroMayor;
	int ordenMayor;
	float numeroMenor;
	int ordenMenor;

	numeroMayor = 0;
	numeroMenor = 0;

	for(i = 1; i < 6; i++){
		printf("Ingrese un número: ");
		scanf("%f", &numeroIngresado);

		if(numeroIngresado > numeroMayor){
			numeroMayor = numeroIngresado;
			ordenMayor = i;
		}
		if(numeroIngresado < numeroMenor || numeroMenor == 0){
			numeroMenor = numeroIngresado;
			ordenMenor = i;
		}
	}

	printf("El mayor número ingresado es: %f y se encuentra en la posición %d.\n", numeroMayor, ordenMayor);
	printf("El menor número ingresado es: %f y se encuentra en la posición %d.\n", numeroMenor, ordenMenor);

	return 0;
}

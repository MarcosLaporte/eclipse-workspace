/*
 ============================================================================
 Name        : Ejercicio 1-3
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Ingresar 3 n�meros y mostrar el n�mero del medio, s�lo si existe.
	En caso de que no exista tambi�n informarlo.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	float primerNumero;
	float segundoNumero;
	float tercerNumero;

	printf("Ingrese el primer n�mero: ");
	scanf("%f", &primerNumero);
	printf("Ingrese el segundo n�mero: ");
	scanf("%f", &segundoNumero);
	printf("Ingrese el tercer n�mero: ");
	scanf("%f", &tercerNumero);

	if((primerNumero > segundoNumero && primerNumero < tercerNumero) || (primerNumero < segundoNumero && primerNumero > tercerNumero)){
		printf("El n�mero del medio es el %f.", primerNumero);
	}else{
		if((segundoNumero > primerNumero && segundoNumero < tercerNumero) || (segundoNumero < primerNumero && segundoNumero > tercerNumero)){
			printf("El n�mero del medio es el %f.", segundoNumero);
		}else{
			if((tercerNumero > primerNumero && tercerNumero < segundoNumero) || (tercerNumero < primerNumero && tercerNumero > segundoNumero)){
				printf("El n�mero del medio es el %.2f.", tercerNumero);
			}else{
				printf("No hay n�mero del medio.");
			}
		}
	}

	return 0;
}

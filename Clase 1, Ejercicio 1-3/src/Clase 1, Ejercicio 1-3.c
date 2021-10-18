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
	Ingresar 3 números y mostrar el número del medio, sólo si existe.
	En caso de que no exista también informarlo.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	float primerNumero;
	float segundoNumero;
	float tercerNumero;

	printf("Ingrese el primer número: ");
	scanf("%f", &primerNumero);
	printf("Ingrese el segundo número: ");
	scanf("%f", &segundoNumero);
	printf("Ingrese el tercer número: ");
	scanf("%f", &tercerNumero);

	if((primerNumero > segundoNumero && primerNumero < tercerNumero) || (primerNumero < segundoNumero && primerNumero > tercerNumero)){
		printf("El número del medio es el %f.", primerNumero);
	}else{
		if((segundoNumero > primerNumero && segundoNumero < tercerNumero) || (segundoNumero < primerNumero && segundoNumero > tercerNumero)){
			printf("El número del medio es el %f.", segundoNumero);
		}else{
			if((tercerNumero > primerNumero && tercerNumero < segundoNumero) || (tercerNumero < primerNumero && tercerNumero > segundoNumero)){
				printf("El número del medio es el %.2f.", tercerNumero);
			}else{
				printf("No hay número del medio.");
			}
		}
	}

	return 0;
}

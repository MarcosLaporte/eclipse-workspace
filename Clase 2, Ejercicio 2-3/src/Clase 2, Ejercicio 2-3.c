/*
 ============================================================================
 Name        : Ejercicio 2-3
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Debemos alquilar el servicio de transporte para llegar a Mar del Plata con
	un grupo de personas, de cada persona debemos obtener los siguientes datos:
		¬ número de cliente,
		¬ estado civil ('s' para soltero", 'c' para casado o 'v' viudo),
		¬ edad( solo mayores de edad, más de 17),
		¬ temperatura corporal (validar por favor)
		¬ y sexo ('f' para femenino, 'm' para masculino, 'o' para no binario).
	NOTA: El precio por pasajero es de $600.
	Se debe informar (solo si corresponde):
	a) La cantidad de personas con estado "viudo" de más de 60 años.
	b) El número de cliente y edad de la mujer soltera más joven.
	c) Cuánto sale el viaje total sin descuento.
	d) Si hay más del 50% de los pasajeros que tiene más de 60 años,
    el precio final tiene un descuento del 25%, que solo mostramos si corresponde.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	char seguir;
	int numeroCliente;
	char estCiv;
	int edad;
	int temperatura;
	char sexo;
	int contViejoViudo;
	int mujerSolteraJoven;
	int clienteMSJ;
	int contClientes;
	int precioBruto;
	int contViejos;
	float precioFinal;

	contViejoViudo = 0;
	mujerSolteraJoven = 0;
	contClientes = 0;
	contViejos = 0;

	do{
		printf("Ingrese el numero de cliente: ");
		scanf("%d", &numeroCliente);

		printf("Ingrese su estado civil (c/s/v): ");
		fflush(stdin);
		scanf("%c", &estCiv);
		estCiv = tolower(estCiv);
		while(!(estCiv == 'c' || estCiv == 's' || estCiv == 'v')){
			printf("Ingrese su estado civil ('c' si es casado, 's' si es soltero, o 'v' si es viudo): ");
			fflush(stdin);
			scanf("%c", &estCiv);
			estCiv = tolower(estCiv);
		}

		printf("Ingrese su edad: ");
		scanf("%d", &edad);
		while(edad < 18){
			printf("Ingrese una edad igual o mayor a 18: ");
			scanf("%d", &edad);
		}

		printf("Ingrese su temperatura corporal: ");
		scanf("%d", &temperatura);
		while(temperatura < 35 || temperatura > 42){
			printf("Ingrese una temperatura corporal válida (35-42): ");
			scanf("%d", &temperatura);
		}

		printf("Ingrese su sexo: ");
		fflush(stdin);
		scanf("%c", &sexo);
		sexo = tolower(sexo);
		while(!(sexo == 'f' || sexo == 'm' || sexo == 'o')){
			fflush(stdin);
			printf("Ingrese un sexo válido ('f' femenino - 'm' masculino - 'o' no binario): ");
			scanf("%c", &sexo);
			sexo = tolower(sexo);
		}

		if(estCiv == 'v' && edad > 60){
			contViejoViudo++;
		}

		if(sexo == 'f' && estCiv == 's' && (mujerSolteraJoven == 0 || edad < mujerSolteraJoven)){
			clienteMSJ = numeroCliente;
			mujerSolteraJoven = edad;
		}

		contClientes++;

		if(edad > 60){
			contViejos++;
		}

		printf("Desea continuar ingresando? s/n: ");
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		while(seguir != 's' && seguir != 'n'){
			printf("Ingrese 's' si desea continuar, o 'n' si no: ");
			fflush(stdin);
			scanf("%c", &seguir);
			seguir = tolower(seguir);
		}
	}while(seguir == 's');

	printf("a) En total hay %d personas mayores a 60 años viudas.\n", contViejoViudo);
	if(mujerSolteraJoven == 0){
		printf("b) No se ingresó ninguna mujer soltera.\n");
	}else{
		printf("b) La mujer soltera mas joven tiene %d años y su número de cliente es %d.\n", mujerSolteraJoven, clienteMSJ);
	}
	precioBruto = contClientes * 600;
	printf("c) El viaje total sin descuento cuesta $%d.\n", precioBruto);
	precioFinal = precioBruto * 0.75;
	if(contClientes * 0.5 < contViejos){
		printf("d) El precio final con un desecuento del 25, es de %.2f.", precioFinal);
	}

	return 0;
}

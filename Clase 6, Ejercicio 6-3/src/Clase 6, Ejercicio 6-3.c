/*
 ============================================================================
 Name        : Ejercicio 6-3
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


/*===========================================================================
Consigna:
	Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre
		y otra para el apellido). Ninguna de las dos variables se puede modificar.
	Debemos lograr guardar en una tercer variable el apellido y el nombre como el sig:
		Gomez, Juan Ignacio
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Ingreso_de_datos.h"

int main(void) {
	setbuf(stdout, NULL);

	char nombre[T];
	char apellido[T];
	char nombreCompleto[100];

	PedirCadena("Ingrese su nombre: ", nombre);
	PedirCadena("Ingrese su apellido: ", apellido);
	printf("El nombre es: ");
	MostrarCadena(nombre);
	printf("\nEl apellido es: ");
	MostrarCadena(apellido);

	MostrarNombreCompleto(nombre, apellido, nombreCompleto);

	return 0;
}

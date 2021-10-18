/*
 ============================================================================
 Name        : Ejercicio 4-2
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	¬Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit,
		validando que las temperaturas ingresadas estén entre el punto de congelación y
		ebullición del agua para cada tipo de escala.
	¬Las validaciones se hacen en una biblioteca.
	¬Las funciones de transformación de fahrenheit a celsius y de celsius a
		fahrenheit se hacen en otra biblioteca.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Conversion.h"

int main(void) {
	setbuf(stdout, NULL);

	float celsiusIngresado;
	float farenheitIngresado;
	float celsiusAfarenheit;
	float farenheitAcelsius;

	celsiusIngresado = PedirFlotante("Ingrese la temperatura celsius: ", 0, 100);
	farenheitIngresado = PedirFlotante("Ingrese la temperatura farenheit: ", 32, 212);

	celsiusAfarenheit = Celsius_Farenheit(celsiusIngresado);
	farenheitAcelsius = Farenheit_Celsius(farenheitIngresado);

	printf("%.2f°C es igual a %.2f°F.\n", celsiusIngresado, celsiusAfarenheit);
	printf("%.2f°F es igual a %.2f°C.\n", farenheitIngresado, farenheitAcelsius);

	return 0;
}

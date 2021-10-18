/*
 ============================================================================
 Name        : Ejercicio 8-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Crear la estructura Jugador (nombre, goles metidos, partidos jugados, promedio de goles).
	Crear una funci�n que permita cargar los datos de un jugador y otra que los muestre.
	Una tercera funci�n calcular� el promedio de goles.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Ingreso_de_datos.h"
#include "Jugadores.h"

int main(void) {
	setbuf(stdout, NULL);

	eJugador jugadores[T];
	int opcion;

	do{
		opcion = PedirEntero("\nIngrese una opci�n (1.Ingresar - 2.Mostrar - 3.Salir): ", "ERROR! Ingrese una opci�n (1.Ingresar - 2.Mostrar - 3.Salir): ", 1, 3);
		switch(opcion){
		case 1:
			if(PedirDatosJugadores(jugadores, T) == 0){
				printf("Ya no hay m�s espacio.\n");
			}
			break;
		case 2:
			CalcularPromedioGoles(jugadores, T);
			if(MostrarJugadores(jugadores, T) == 0){
				printf("No se han ingresado jugadores.\n");
			}
			break;
		case 3:
			printf("Sali�.");
		}
	}while(opcion != 3);


	return 0;
}

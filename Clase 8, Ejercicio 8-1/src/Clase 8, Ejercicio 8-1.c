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
	Crear una función que permita cargar los datos de un jugador y otra que los muestre.
	Una tercera función calculará el promedio de goles.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Ingreso_de_datos.h"

typedef struct{
	char nombre[25];
	int goles;
	int partidos;
	float promedioGoles;
}eJugador;

eJugador PedirDatosUnJugador(void);
int CalcularPromedioGoles(eJugador jugador[], int tam);

int main(void) {
	setbuf(stdout, NULL);



	return 0;
}

eJugador PedirDatosUnJugador(void){
	eJugador unJugador;

	PedirCadena("Ingrese el nombre del jugador: ", unJugador.nombre);
	unJugador.goles = PedirEntero("Ingrese la cantidad de goles: ", "ERROR! Ingrese una cantidad de goles entre 0 y 10000: ", 0, 10000);
	unJugador.partidos = PedirEntero("Ingrese la cantidad de partidos jugados: ", "ERROR! Ingrese una cantidad de partidos entre 0 y 10000: ", 0, 10000);
	unJugador.promedioGoles = CalcularPromedioGoles(unJugador, T);

	return unJugador;
}

int PedirDatosJugadores(eJugador listaJugadores[], int tam){
	int i;

	for(i = 0; i < tam; i++){
		listaJugadores[i] = PedirDatosUnJugador();
	}
}

int CalcularPromedioGoles(eJugador jugador[], int tam){
	int i;
//	int retorno;
//	retorno = -1;

	for(i = 0; i < tam; i++){
		if(jugador[i].partidos != 0){
//			retorno = 0;
			jugador[i].promedioGoles = jugador[i].goles / jugador[i].partidos;
		}
	}

//	return retorno;
	return promedio;
}

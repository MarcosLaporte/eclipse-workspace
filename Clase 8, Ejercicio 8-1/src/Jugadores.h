/*
 * Jugadores.h
 *
 *  Created on: 18 oct. 2021
 *      Author: Marcos
 */

#ifndef JUGADORES_H_
#define JUGADORES_H_
#include <stdio.h>
#include <stdlib.h>
#include "Ingreso_de_datos.h"

typedef struct{
	char nombre[25];
	int goles;
	int partidos;
	float promedioGoles;
	int estado;
}eJugador;

eJugador PedirDatosUnJugador(void);
int PedirDatosJugadores(eJugador listaJugadores[], int tam);
void CalcularPromedioGoles(eJugador jugador[], int tam);
int MostrarJugadores(eJugador jugador[], int tam);

#endif /* JUGADORES_H_ */

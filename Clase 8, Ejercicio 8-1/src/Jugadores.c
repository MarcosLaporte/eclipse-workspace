/*
 * Jugadores.c
 *      Author: Marcos
 */
#include "Jugadores.h"

eJugador PedirDatosUnJugador(void){
	eJugador unJugador;

	PedirCadena("Ingrese el nombre del jugador: ", unJugador.nombre);
	unJugador.goles = PedirEntero("Ingrese la cantidad de goles: ", "ERROR! Ingrese una cantidad de goles entre 0 y 10000: ", 0, 10000);
	unJugador.partidos = PedirEntero("Ingrese la cantidad de partidos jugados: ", "ERROR! Ingrese una cantidad de partidos entre 0 y 10000: ", 0, 10000);
	unJugador.estado = 1;

	return unJugador;
}

int PedirDatosJugadores(eJugador listaJugadores[], int tam){
	int retorno;
	retorno = 0;

	for(int i = 0; i < tam; i++){
		if(listaJugadores[i].estado != 1){
			retorno = 1;
			listaJugadores[i] = PedirDatosUnJugador();
			break;
		}
	}

	return retorno;
}

void CalcularPromedioGoles(eJugador jugador[], int tam){
	for(int i = 0; i < tam; i++){
		if(jugador[i].estado == 1){
			if(jugador[i].partidos != 0){
				jugador[i].promedioGoles = (float)jugador[i].goles / jugador[i].partidos;
			}else{
				jugador[i].promedioGoles = 0;
			}
		}
	}
}

int MostrarJugadores(eJugador jugador[], int tam){
	int retorno;
	retorno = 0;

	for(int i = 0; i < tam; i++){
		if(jugador[i].estado == 1){
			retorno = 1;
			printf("%15s%3d%3d%6.2f\n", jugador[i].nombre, jugador[i].goles, jugador[i].partidos, jugador[i].promedioGoles);
		}
	}

	return retorno;
}

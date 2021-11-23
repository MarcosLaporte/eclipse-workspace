/*
 ============================================================================
 Name        : Práctica segundo parcial Laboratorio.c
 Author      : Marcos Laporte
 ============================================================================
 */

/*===========================================================================
1) Cargar archivo Pilotos: Se pedirá el nombre del archivo y se cargará en un LinkedList los
elementos del mismo.
2) Cargar archivo Vuelos: Se pedirá el nombre del archivo y se cargará en un LinkedList los
elementos del mismo.
3) Imprimir vuelos: Se imprimirá por pantalla la tabla con los datos de los vuelos indicando el
nombre del piloto (no el número)
4) Cantidad de pasajeros: Cantidad de pasajeros totales
5) Cantidad de pasajeros a China: cantidad de pasajeros a China.
6) Filtrar vuelos cortos: Generar un archivo de iguales características que el original, con los
datos de los vuelos cuya duración sea inferior a 3 horas.
7) Listar vuelos a China: Generar un listado que solo incluya los vuelos con destino a China.
8) Filtrar a Alex Lifeson: Necesitamos un listado de vuelos que no incluya al chofer Alex
Lifeson.
9) Salir.
===========================================================================*/

#include "Input.h"

int main(void) {
	setbuf(stdout, NULL);

	int option;

	do{
		option = printMenu();
		switch(option){
		case 1: //Cargar pilotos
			break;
		case 2: //Cargar vuelos
			break;
		case 3: //Imprimir
			break;
		case 4: //Cant pasajeros
			break;
		case 5: //Cant pasajeros -> China
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		}
	}while(option != 9);

	return EXIT_SUCCESS;
}

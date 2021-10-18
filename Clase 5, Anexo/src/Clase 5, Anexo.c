/*
 ============================================================================
 Name        : Clase 5 Anexo
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	1. Armar un Menú de Opciones e imprimir en pantalla el nombre del mismo.
	2. Realizar un programa que desde el main llame o invoque a la función que muestre el Menú del punto anterior.
	3. Crear un Array de 5 elementos de tipo numérico donde se cargarán edades.
		Agregar la funcionalidad para la opción 1 del Menú del ejercicio anterior
			utilizando funciones, es decir una función que inicialice el Array.
		Agregar la funcionalidad para la opción 2 del Menú utilizando funciones, es decir una
			función que le pida los números o edades al usuario para cargar el Array de forma secuencial.
	4. Modificar la funcionalidad de la opción 2 del Menú para que la carga del Array sea de forma aleatoria.
		Agregar la funcionalidad de la opción 3 del Menú para mostrar por pantalla los elementos del Array.
	5. Modificar la funcionalidad de la opción 3 del Menú de forma que existan 2 funciones:
		una que muestre solamente un elemento o edad y otra que muestre todos los elementos o edades.
		La función que muestra todos los elementos o edades debe llamar a la que muestra solo uno.
	6. Realizar una función que calcule el promedio de los números ingresados en el Array y
		agregarlo a la opción de Menú 4. La misma deberá imprimir el resultado por pantalla.
	7. Modificar la función que calcula el promedio en la opción 4 del Menú, para que
		el resultado del promedio lo devuelva por retorno y sea main quien lo imprima por pantalla.
	8. Modificar la función que calcula el promedio en la opción 4 del Menú, para que devuelva el
		resultado del promedio por parámetro por referencia. El retorno de la misma debe indicar si funcionó correctamente.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;
	int edades[T];
	float promedioEdades;

	do{
//		Ejercicio 1
		opcionElegida = PedirOpcion();
//		Ejercicio 2
		MostrarOpcion(opcionElegida);
//		Ejercicio 3
		switch(opcionElegida){
		case 1:
			InicializarEdad(edades);
			break;
		case 2:
//		Ejercicio 4
			PedirVectorEntero(edades);
			break;
		case 3:
//		Ejercicio 5
			MostrarElementoVectorEntero(edades, T);
			MostrarVectorEntero(edades, T);
			break;
		case 4:
//		Ejercicio 6
			promedioEdades = PromedioVectores(edades, T);
//		Ejercicio 7
			printf("El promedio de las edades ingresadas es: %.2f\n", promedioEdades);
			break;
		}
	}while(opcionElegida != 6);

	return 0;
}

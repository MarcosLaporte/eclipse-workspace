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
	1. Armar un Men� de Opciones e imprimir en pantalla el nombre del mismo.
	2. Realizar un programa que desde el main llame o invoque a la funci�n que muestre el Men� del punto anterior.
	3. Crear un Array de 5 elementos de tipo num�rico donde se cargar�n edades.
		Agregar la funcionalidad para la opci�n 1 del Men� del ejercicio anterior
			utilizando funciones, es decir una funci�n que inicialice el Array.
		Agregar la funcionalidad para la opci�n 2 del Men� utilizando funciones, es decir una
			funci�n que le pida los n�meros o edades al usuario para cargar el Array de forma secuencial.
	4. Modificar la funcionalidad de la opci�n 2 del Men� para que la carga del Array sea de forma aleatoria.
		Agregar la funcionalidad de la opci�n 3 del Men� para mostrar por pantalla los elementos del Array.
	5. Modificar la funcionalidad de la opci�n 3 del Men� de forma que existan 2 funciones:
		una que muestre solamente un elemento o edad y otra que muestre todos los elementos o edades.
		La funci�n que muestra todos los elementos o edades debe llamar a la que muestra solo uno.
	6. Realizar una funci�n que calcule el promedio de los n�meros ingresados en el Array y
		agregarlo a la opci�n de Men� 4. La misma deber� imprimir el resultado por pantalla.
	7. Modificar la funci�n que calcula el promedio en la opci�n 4 del Men�, para que
		el resultado del promedio lo devuelva por retorno y sea main quien lo imprima por pantalla.
	8. Modificar la funci�n que calcula el promedio en la opci�n 4 del Men�, para que devuelva el
		resultado del promedio por par�metro por referencia. El retorno de la misma debe indicar si funcion� correctamente.
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

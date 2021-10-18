/*
 ============================================================================
 Name        : Ejercicio 7-1
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Consigna:
	Una empresa importadora, decide registrar de sus productos los siguientes datos:
		�idProducto (numerico)
		�descripcion (alfanum�rico)
		�nacionalidad (num�rico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
		�tipo (num�rico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
		�precio (num�rico decimal)
	Realizar un programa que permita interactuar con un men� de usuarios con las siguientes opciones:
		�ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
		�BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista,
			dejando espacio disponible para un nuevo producto.
		�MODIFICACI�N Producto: A partir del ingreso del ID. Si existe se podr� modificar el precio o el tipo.
		�LISTADO Productos.
		�LISTADO ordenado por precio.
		�LISTADO ordenado por descripci�n.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"


int main(void) {
	setbuf(stdout, NULL);

	int idProducto[T];
	char descripcion[T][50];
	int nacionalidad[T];
	int tipo[T];
	float precio[T];
	int estado[T];

/*	int idProducto[T] = {111,222,333,444};
	char descripcion[T][50] = {"Aifon","La macos","Ah� Pa","Unos auris chetos"};
	int nacionalidad[T] = {OTRO,CHINA,EEUU,EEUU};
	int tipo[T] = {IPHONE,MAC,IPAD,ACCESORIOS};
	float precio[T] = {200,350,150,50};
	int estado[T] = {CARGADO, CARGADO, CARGADO, CARGADO};*/

	int opcion;

	do{
		printf("1. Dar de alta\n2. Dar de baja\n3. Modificar producto\n4. Lista de productos\n"
				"5. Lista ordenada por precio\n6. Lista ordenada por modificaci�n\n7. Salir\n");
		opcion = PedirEntero("Ingrese una opci�n: ", "ERROR! Ingrese una opci�n entre 1 y 7: ", 1, 7);
		switch(opcion){
		case 1:
			break;
		case 7:
			printf("Sali� de la lista.");
			break;
		}
	}while(opcion != 7);

	return 0;
}

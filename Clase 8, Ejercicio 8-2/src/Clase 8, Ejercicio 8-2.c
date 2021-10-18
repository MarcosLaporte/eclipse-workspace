/*
 ============================================================================
 Name        : Ejercicio 8-2
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
#include "Ingreso_de_datos.h"
#include "Biblioteca_Productos.h"


int main(void){
	setbuf(stdout, NULL);

	eProducto listaProductos[T] = {{111, "Iphone 13", EEUU, IPHONE, 500, CARGADO},
									{222, "MacOS", CHINA, MAC, 1500, CARGADO},
									{333, "AirPods", OTRO, ACCESORIOS, 100, CARGADO},
									{444, "IPad 5", EEUU, IPAD, 750, CARGADO},
									{555, "Cargador", CHINA, ACCESORIOS, 50, CARGADO}};
	int opcion;

//	InicializarProductos(listaProductos, T);

	do{
		printf("1. Dar de alta\n2. Dar de baja\n3. Modificar producto\n4. Lista de productos\n"
				"5. Lista ordenada por precio\n6. Lista ordenada por descripci�n\n7. Salir\n");
		opcion = PedirEntero("Ingrese una opci�n: ", "ERROR! Ingrese una opci�n entre 1 y 7: ", 1, 7);
		switch(opcion){
		case 1:
			if(AltaProducto(listaProductos, T) == 0){
				printf("Ya se ingres� la cantidad m�xima de productos.\n");
			}else{
				AltaProducto(listaProductos, T);
			}
			break;
		case 2:
			if(BajaProducto(listaProductos, T) == 0){
				printf("No existe un producto con ese ID.\n");
			}else{
				printf("El producto fue dado de baja.\n");
			}
			break;
		case 3:
			if(ModificarProducto(listaProductos, T) == 0){
				printf("No existe un producto con ese ID.\n");
			}else{
				printf("El producto fue modificado.\n");
			}
			break;
		case 4:
			MostrarLista(listaProductos, T);
			break;
		case 5:
			OrdenarArrayPrecio(listaProductos, T);
			MostrarLista(listaProductos, T);
			break;
		case 6:
			OrdenarArrayDescripcion(listaProductos, T);
			MostrarLista(listaProductos, T);
			break;
		case 7:
			printf("Sali� de la lista.");
			break;
		}

	}while(opcion != 7);

	return 0;
}

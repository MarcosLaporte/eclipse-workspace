/*
 ============================================================================
 Name        : Clase.c
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*===========================================================================
Realizar una función que retorne un puntero a eProducto. Dentro de esta función
deberá crear un producto hardcodeado, un puntero y se apuntará ese puntero al producto.
Mostrar el producto cargado 5 veces desde el main. Observar el comportamiento del programa.
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char descripcion[51];
	float precio;
}eProducto;

eProducto* crearUnProducto();

int main(void) {
	setbuf(stdout, NULL);

	eProducto* producto;

	producto = crearUnProducto();

	if(producto != NULL){
		printf("%-4s|%-15s|%-5s\n", "ID", "Descripción", "Precio");
		printf("%4d|%15s|%5.2f\n", producto->id, producto-> descripcion, producto->precio);
		printf("%4d|%15s|%5.2f\n", producto->id, producto-> descripcion, producto->precio);
		printf("%4d|%15s|%5.2f\n", producto->id, producto-> descripcion, producto->precio);
		printf("%4d|%15s|%5.2f\n", producto->id, producto-> descripcion, producto->precio);
		printf("%4d|%15s|%5.2f", producto->id, producto-> descripcion, producto->precio);
	}else{
		printf("Hubo un error.\n");
	}

	return 0;
}

eProducto* crearUnProducto(){
	eProducto* Return;

	Return = (eProducto*)malloc(sizeof(eProducto));

	if(Return != NULL){
		Return->id = 1;
		strcpy(Return->descripcion, "Iphone 13");
		Return->precio = 999;
	}


	return Return;
}




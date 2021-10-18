#include "Biblioteca_Productos.h"
#include "Ingreso_de_datos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

eProducto PedirProducto(){
	eProducto tipoProducto;

	tipoProducto.idProducto = PedirEntero("Ingrese un entero para el ID: ", "ERROR! Ingrese un entero para el ID (0-1000): ", 0, 1000);
	PedirCadena("Ingrese la descripción del producto: ", tipoProducto.descripcion);
	tipoProducto.nacionalidad = PedirEntero("Ingrese nacionalidad (1: EEUU - 2: CHINA - 3: OTRO): ", "ERROR! Ingrese nacionalidad (1: EEUU - 2: CHINA - 3: OTRO) :", 1, 3);
	tipoProducto.tipo = PedirEntero("Ingrese el tipo de producto (1: IPHONE - 2: MAC - 3: IPAD - 4: ACCESORIOS): ", "ERROR! Ingrese el tipo de producto (1: IPHONE - 2: MAC - 3: IPAD - 4: ACCESORIOS): ", 1, 4);
	tipoProducto.precio = PedirFlotante("Ingrese el precio del producto: ", "ERROR! Ingrese el precio del producto (1-10000): ", 1, 10000);
	tipoProducto.estado = CARGADO;

	return tipoProducto;
}

/// @return 0 cuando no encuentra espacio, 1 cuando encuentra espacio y da de alta.
int AltaProducto(eProducto listaProd[], int tam){
	int i;
	int retorno;
	retorno = VACIO;

	for(i = 0; i < tam; i++){
		if(listaProd[i].estado != CARGADO){
			listaProd[i] = PedirProducto();
			retorno = CARGADO;
			break;
		}
	}

	return retorno;
}

void MostrarProducto(eProducto unProducto){
	char prodNacion[6];
	char prodTipo[11];

	switch(unProducto.nacionalidad){
	case EEUU:
		strcpy(prodNacion, "EEUU");
		break;
	case CHINA:
		strcpy(prodNacion, "CHINA");
		break;
	case OTRO:
		strcpy(prodNacion, "OTRO");
		break;
	}

	switch(unProducto.tipo){
	case IPHONE:
		strcpy(prodTipo, "IPHONE");
		break;
	case MAC:
		strcpy(prodTipo, "MAC");
		break;
	case IPAD:
		strcpy(prodTipo, "IPAD");
		break;
	case ACCESORIOS:
		strcpy(prodTipo, "ACCESORIOS");
		break;
	}

	printf("%4d %15s %5s %10s %4.2f\n", unProducto.idProducto,
			unProducto.descripcion, prodNacion,
			prodTipo, unProducto.precio);
}

void MostrarLista(eProducto listaProductos[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		if(listaProductos[i].estado == 1){
			MostrarProducto(listaProductos[i]);
		}
	}
}

void InicializarProductos(eProducto listaProductos[], int tam){
	int i;
	for(i = 0; i < tam; i++){
		listaProductos[i].estado = VACIO;
	}
}

int BajaProducto(eProducto listaProd[], int tam){
	int idProducto;
	int i;
	int retorno;
	retorno = 0;

	MostrarLista(listaProd, tam);
	idProducto = PedirEntero("Ingrese el ID del producto a dar de baja: ", "ERROR! Ingrese un ID mayor a 0 y menor a 1000", 0, 1000);

	for(i = 0; i < tam; i++){
		if(listaProd[i].estado != VACIO && listaProd[i].idProducto == idProducto){
			listaProd[i].estado = VACIO;
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int ModificarProducto(eProducto listaProd[], int tam){
	int idProducto;
	int i;
	int retorno;
	int modificacion;
	retorno = 0;

	MostrarLista(listaProd, tam);
	idProducto = PedirEntero("Ingrese el ID del producto a modificar: ", "ERROR! Ingrese un ID mayor a 0 y menor a 1000", 0, 1000);

	for(i = 0; i < tam; i++){
		if(listaProd[i].estado != VACIO && listaProd[i].idProducto == idProducto){
			modificacion = PedirEntero("Qué desea modificar? (1: Precio - 2: Tipo): ", "ERROR! Seleccione 1 o 2 (1: Precio - 2: Tipo): ", 1, 4);
			switch(modificacion){
			case DESCR:
				PedirCadena("Ingrese la nueva descripción del producto: ", listaProd[i].descripcion);
				break;
			case NACION:
				listaProd[i].nacionalidad = PedirEntero("Ingrese la nueva nacionalidad (1: EEUU - 2: CHINA - 3: OTRO): ", "ERROR! Ingrese la nueva nacionalidad (1: EEUU - 2: CHINA - 3: OTRO) :", 1, 3);
				break;
			case TIPO:
				listaProd[i].tipo = PedirEntero("Ingrese el nuevo tipo de producto (1: IPHONE - 2: MAC - 3: IPAD - 4: ACCESORIOS): ", "ERROR! Ingrese el nuevo tipo de producto (1: IPHONE - 2: MAC - 3: IPAD - 4: ACCESORIOS): ", 1, 4);
				break;
			case PRECIO:
				listaProd[i].precio = PedirFlotante("Ingrese el nuevo precio del producto: ", "ERROR! Ingrese el nuevo precio del producto (1-10000): ", 1, 10000);
				break;
			}
			retorno = 1;
			break;
		}
	}

	return retorno;
}

int OrdenarArrayPrecio(eProducto listaProd[], int tam){
	int flagCambio;
	int i;
	int j;
	eProducto aux;

	if(listaProd != NULL && tam > 0){
		do{
			flagCambio = 0;
			for(i = 0; i < tam-1; i++){
				for(j = i+1; j < tam; j++){
					if(listaProd[i].estado == CARGADO && listaProd[j].estado == CARGADO){
						if(listaProd[i].precio > listaProd[i+1].precio){
							flagCambio = 1;
							aux = listaProd[i];
							listaProd[i] = listaProd[j];
							listaProd[j] = aux;
						}
					}
				}
			}
		}while(flagCambio);
	}

	return flagCambio;
}


int OrdenarArrayDescripcion(eProducto listaProd[], int tam){
	int flagCambio;
	int i;
	int j;
	eProducto aux;

	if(listaProd != NULL && tam > 0){
		do{
			flagCambio = 0;
			for(i = 0; i < tam-1; i++){
				for(j = i+1; j < tam; j++){
					if(strcmp(listaProd[i].descripcion, listaProd[j].descripcion) > 0){
						flagCambio = 1;
						aux = listaProd[i];
						listaProd[i] = listaProd[j];
						listaProd[j] = aux;
					}
				}
			}
		}while(flagCambio);
	}

	return flagCambio;
}

/* No sé qué hacer :(
int BuscarId(int idBuscado, int tam){
	int retorno;
	int i;

	for(i = 0; i < tam; i++){
		if(idBuscado == eProducto){
			retorno = 1;
		}
	}

	return retorno;
}
*/

/*
 ============================================================================
 Name        : Ejercicio 10-3
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*-----------------------------------------------------------------------------------------------------
Una empresa importadora que comercializa productos Apple, decide registrar de sus productos los siguientes datos:
	idProducto (numerico)
	descripcion (alfanum?rico)
	nacionalidad (num?rico, por el momento utilizaremos un define: EEUU - CHINA - OTRO)
	tipo (num?rico, por el momento utilizaremos un define: IPHONE -MAC - IPAD - ACCESORIOS)
	precio (num?rico decimal)
Realizar un programa que permita interactuar con un men? de usuarios con las siguientes opciones:
	1.	ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando haya espacio disponible en el array.
	2.	BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de la lista, dejando espacio disponible para un nuevo producto.
	3.	MODIFICACI?N Producto: A partir del ingreso del ID. Si existe se podr? modificar el precio o el tipo.
	4.	LISTADO Productos.
	5.	LISTADO ordenado por precio.
	6.	LISTADO ordenado por descripci?n.
	7.	El/los productos m?s caros.
	8.	Los productos que cuestan 700.
	9.	Precio promedio por tipo de producto.
	10.	Por cada tipo la lista de productos.
	11.	El/los tipos de productos con mas productos importados.
	12.	La nacionalidad que solo fabrica Iphone.
	13.	Los productos, ordenados por nacionalidad alfab?ticamente.
	14. La nacionalidad con m?s tipos de productos fabricados.
	15. El precio promedio de productos por nacionalidad
------------------------------------------------------------------*/

#include "Nexus.h"

int main(){
	setbuf(stdout, NULL);

	int option;
	sProduct arrayProduct[MAX_PROD] = {{111, "Iphone 13", 1, 1000, 700, FULL},
									{222, "MacOS", 2, 1002, 1500, FULL},
									{333, "AirPods", 3, 1003, 100, FULL},
									{444, "IPad 5", 1, 1001, 750, FULL},
									{555, "Cargador", 3, 1003, 799, FULL},
									{666, "Iphone 8", 3, 1000, 650, FULL}};
	float averagePrices[MAX_TYPE];
	sType productType[MAX_TYPE]= {{1000, "Iphone", FULL}, {1001, "IPad", FULL}, {1002, "Mac", FULL}, {1003, "Accesorios", FULL}};
	sNation productNation[MAX_NATION] = {{1, "EEUU", FULL}, {2, "CHINA", FULL}, {3, "OTRO", FULL}};

//	if(initProduct(arrayProduct, MAX_PROD) == 0){
//		printf("Se han inicializado los productos!\n");
//	}

	do{
		option = printMenu();
		switch(option){
		case 1: //ALTA Producto
			if(addProduct(arrayProduct, MAX_PROD) == -1){
				printf("Ya se ingres? la cantidad m?xima de productos.\n");
			}
			break;
		case 2: //BAJA Producto
			if(printAllProducts(arrayProduct, MAX_PROD) == -1){
				printf("No se han ingresado productos.\n");
			}else{
				if(removeProduct(arrayProduct, MAX_PROD) == -1){
					printf("No existe un producto con ese ID.\n");
				}
			}
			break;
		case 3: //MODIFICACI?N Producto
			if(printAllProducts(arrayProduct, MAX_PROD) == -1){
				printf("No se han ingresado productos.\n");
			}else{
				if(modifyProduct(arrayProduct, MAX_PROD) == -1){
					printf("No existe un producto con ese ID.\n");
				}
			}
			break;
		case 4: //LISTADO Productos
			if(printAllProducts(arrayProduct, MAX_PROD) == -1){
				printf("No se han ingresado productos.\n");
			}
			break;
		case 5: //LISTADO ordenado por precio.
			sortProductPrice(arrayProduct, MAX_PROD);
			if(printAllProducts(arrayProduct, MAX_PROD) == -1){
				printf("No se han ingresado productos.\n");
			}
			break;
		case 6: //LISTADO ordenado por descripci?n.
			sortProductDescr(arrayProduct, MAX_PROD);
			if(printAllProducts(arrayProduct, MAX_PROD) == -1){
				printf("No se han ingresado productos.\n");
			}
			break;
		case 7: //El-los productos m?s caros
			if(highestPriceProducts(arrayProduct, MAX_PROD) == -1){
				printf("No se han ingresado productos.\n");
			}
			break;
		case 8: //Los productos que cuestan 700.
			if(checkAnyProduct(arrayProduct, MAX_PROD) == 0){
				if(printByPrice(arrayProduct, MAX_PROD, 700) == -1){
					printf("No existe un producto con precio $700.\n");
				}
			}else{
				printf("No se han ingresado productos.\n");
			}
			break;
		case 9: //Precio promedio por tipo de producto.
			averagePrice(arrayProduct, MAX_PROD, averagePrices);
			if(printAveragePerType(arrayProduct, MAX_TYPE, averagePrices) == -1){
				printf("No se han ingresado productos.\n");
			}
			break;
		case 10: //Por cada tipo la lista de productos.
			if(printProductsWithType(arrayProduct, MAX_PROD, productType, MAX_TYPE, productNation, 3) == -1){
				printf("No se han ingresado productos.\n");
			}
			break;
		case 11: //El-los tipos de productos con mas productos importados.
			break;
		case 12:
			break;

		case 0:
			printf("Ha salido del programa.");
			break;
		}
	}while(option != 0);

	return 0;
}

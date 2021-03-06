/*
 * Productos.c
 *      Author: Marcos
 */

#include "Products.h"


int initProduct(sProduct* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			Return = 0;
			list[i].status = EMPTY;
		}
	}

	return Return;
}

sProduct getProduct(){
	sProduct product;

	getFinalInt(&product.idProduct, "\nIngrese el ID del producto: ", "ERROR! Ingrese un ID num?rico: ", 1, 99999);
	getString("Ingrese la descripci?n del producto: ", product.description, 51);
	getFinalInt(&product.nationality, "Ingrese la nacionalidad del producto (1: EEUU - 2: CHINA - 3: OTRO): ", "ERROR! Ingrese nacionalidad (1: EEUU - 2: CHINA - 3: OTRO): ", 1, 3);
	getFinalInt(&product.type, "Ingrese el tipo de producto (1000: IPHONE - 1001: MAC - 1002: IPAD - 1003: ACCESORIOS): ", "ERROR! Ingrese el tipo de producto (1000: IPHONE - 1001: MAC - 1002: IPAD - 1003: ACCESORIOS): ", 1000, 1003);
	getFinalFloat(&product.price, "Ingrese el precio del producto: ", "ERROR! Ingrese un precio num?rico: ", 1, 999999);
	product.status = FULL;

	return product;
}

int addProduct(sProduct* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == EMPTY){
				Return = 0;
				list[i] = getProduct();
				printf("Se carg? el producto!\n");
				break;
			}
		}
	}

	return Return;
}

void printOneProduct(sProduct aProduct){
	printf("|%4d|%15s|%6d|%4d|%7.2f|\n", aProduct.idProduct, aProduct.description,
								aProduct.nationality, aProduct.type, aProduct.price);
}

int printAllProducts(sProduct* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL){
				Return = 0;
				printf("#----------------------------------------#\n");
				printf("|%-4s|%-15s|%-6s|%-4s|%-7s|\n", "ID", "DESCRIPCI?N", "NACION", "TIPO", "PRECIO");
				printf("#----+---------------+------+----+-------#\n");
				break;
			}
		}
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL){
				printOneProduct(list[i]);
				printf("#----+---------------+------+----+-------#\n");
			}
		}
	}

	return Return;
}

int findProductById(sProduct* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL && list[i].idProduct == id){
				Return = i;
				break;
			}
		}
	}

	return Return;
}

int checkAnyProduct(sProduct* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL){
				Return = 0;
				break;
			}
		}
	}
	return Return;
}

int removeProduct(sProduct* list, int len){
	int Return;
	int id;
	int index;
	Return = -1;

	if(list != NULL && len > 0){
		getFinalInt(&id, "\nIngrese el ID del producto que desea dar de baja o 0 para cancelar: ", "ERROR! Ingrese un ID num?rico: ", 0, 99999);
		index = findProductById(list, len, id);
		if(index != -1){
			Return = 0;
			list[index].status = EMPTY;
			printf("El producto ha sido dado de baja!\n");
		}else{
			if(id == 0){
				Return = 0;
				printf("Ha cancelado la acci?n.\n");
			}
		}
	}
	return Return;
}

int modifyProduct(sProduct* list, int len){
	int Return;
	int id;
	int index;
	int option;
	Return = -1;

	if(list != NULL && len > 0){
		id = getInt("Ingrese el id del producto que desea dar de baja: ");
		index = findProductById(list, len, id);
		if(index != -1){
			Return = 0;
			option = getLimitedFloat("Campos para modificar:\n1. Precio\n2. Tipo\n0. CANCELAR\nElija uno: ", "ERROR! Campos para modificar:\n1. Precio\n2. Tipo\n0. CANCELAR\nElija uno (0-2): ", 0, 2);
			if(option == 0){
				printf("Ha cancelado la modificaci?n.\n");
			}else{
				if(option == 1){
					list[index].price = getFloat("Ingrese el nuevo precio: ");
				}else{
					list[index].type = getInt("Ingrese el nuevo tipo: ");
				}
				printf("Se ha modificado el producto!\n");
			}
		}
	}

	return Return;
}

void sortProductPrice(sProduct* list, int len){
	int flagSwap;
	sProduct aux;

	if(list != NULL && len > 0){
		do{
			flagSwap = 0;
			for(int i = 0; i < len; i++){
				if(list[i].status == FULL && list[i+1].status == FULL){
					if(list[i].price > list[i+1].price){
						flagSwap = 1;
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;
					}
				}
			}
		}while(flagSwap);
	}
}

void sortProductDescr(sProduct* list, int len){
	int flagSwap;
	sProduct aux;

	if(list != NULL && len > 0){
		do{
			flagSwap = 0;
			for(int i = 0; i < len; i++){
				if(list[i].status == FULL && list[i+1].status == FULL){
					if(strcmp(list[i].description, list[i+1].description) > 0){
						flagSwap = 1;
						aux = list[i];
						list[i] = list[i+1];
						list[i+1] = aux;
					}
				}
			}
		}while(flagSwap);
	}
}

float highestPrice(sProduct* list, int len){
	int flagFirst;
	float highPrice;
	flagFirst = 1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL){
				if(list[i].price > highPrice || flagFirst){
					flagFirst = 0;
					highPrice = list[i].price;
				}
			}
		}
	}

	return highPrice;
}

int printByPrice(sProduct* list, int len, float searchedPrice){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL && list[i].price == searchedPrice){
				Return = 0;
				printOneProduct(list[i]);
			}
		}
	}

	return Return;
}

int highestPriceProducts(sProduct* list, int len){
	float lookedPrice;
	int Return;
	lookedPrice = highestPrice(list, len);
	Return = printByPrice(list, len, lookedPrice);

	return Return;
}

int averagePrice(sProduct* list, int len, float averagePrices[]){
	int Return;
	int count[MAX_TYPE] = {0, 0, 0, 0};
	float accum[MAX_TYPE] = {0, 0, 0, 0};
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL){
				Return = 0;
				switch(list[i].type){
				case IPHONE:
					count[IPHONE-1]++;
					accum[IPHONE-1] += list[i].price;
					break;
				case MAC:
					count[MAC-1]++;
					accum[MAC-1] += list[i].price;
					break;
				case IPAD:
					count[IPAD-1]++;
					accum[IPAD-1] += list[i].price;
					break;
				case ACCESORIOS:
					count[ACCESORIOS-1]++;
					accum[ACCESORIOS-1] += list[i].price;
					break;
				}
			}
		}
	}

	for(int i = 0; i < MAX_TYPE; i++){
		if(count[i] != 0){
			averagePrices[i] = accum[i] / count[i];
		}else{
			averagePrices[i] = -1;
		}
	}

	return Return;
}

int printAveragePerType(sProduct* list, int len, float prices[]){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		if(checkAnyProduct(list, len) == 0){
			Return = 0;
			for(int i = 0; i < len; i++){
				if(prices[i] == -1){
					printf("No se ingresaron productos del tipo '%d'.\n", i+1);
				}else{
					printf("Promedio de '%d': %.2f.\n", i+1, prices[i]);
				}
			}
		}
	}

	return Return;
}

float lowestPrice(sProduct* list, int len){
	int flagFirst;
	float lowPrice;
	flagFirst = 1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].price < lowPrice || flagFirst){
				flagFirst = 0;
				lowPrice = list[i].price;
			}
		}
	}

	return lowPrice;
}

/*
int printMadeInChina(sProduct* prodList, int prodLen, sType* typeList, int typeLen, sNation* nationList, int nationLen){
	int Return;
	Return = -1;

	if(prodList != NULL && prodLen > 0 && typeList != NULL && typeLen > 0){
		for(int i = 0; i < prodLen; i++){
			for(int j = 0; j < typeLen; j++){
				for(int k = 0; k < nationLen; k++){
					if(prodList[i].status == FULL){
						if(prodList[i].type == typeList[j].typeId){
							if(nationList[k].nationId == CHINA){
								Return = 0;
								printf("|%4d|%15s|%6s|%11s|%7.2f|\n", prodList[i].idProduct, prodList[i].description,
																nationList[k].descriptionNation, typeList[j].description, prodList[i].price);
							}
						}
					}
				}
			}
		}
	}

	return Return;
}
*/

int findActiveId(sProduct* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		Return = 0;
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL && list[i].idProduct == id){
				Return = 1;
				break;
			}
		}
	}

	return Return;
}


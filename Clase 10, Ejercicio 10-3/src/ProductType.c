/*
 * tipoProducto.c
 *      Author: Marcos
 */

#include "ProductType.h"

void printProductType(sType* list, int len){
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			printf("%d, %15s", list[i].typeId, list[i].description);
		}
	}
}

sType searchTypeById(sType* list, int len, int id){
	sType aux;

	for(int i = 0; i < len; i++){
		if(list[i].status == FULL && list[i].typeId == id){
			aux = list[i];
			break;
		}
	}

	return aux;
}

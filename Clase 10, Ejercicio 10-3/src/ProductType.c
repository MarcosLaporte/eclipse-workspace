/*
 * tipoProducto.c
 *      Author: Marcos
 */

#include "ProductType.h"
#include "Input.h"

void printProductType(sType* list, int len){
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			printf("%d, %15s", list[i].typeId, list[i].description);
		}
	}
}

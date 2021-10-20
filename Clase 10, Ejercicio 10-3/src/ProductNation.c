/*
 * ProductNation.c
 *      Author: Marcos
 */

#include "ProductNation.h"

sNation searchNationById(sNation* list, int len, int id){
	sNation aux;

	for(int i = 0; i < len; i++){
		if(list[i].status == FULL && list[i].nationId == id){
			aux = list[i];
			break;
		}
	}

	return aux;
}

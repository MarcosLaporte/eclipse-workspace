/*
 * Request.c
 *      Author: Marcos
 */

#include "Request.h"

int initRequests(sRequest* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			Return = 0;
			list[i].isEmpty = EMPTY;
		}
	}

	return Return;
}

int checkARequest(sRequest* list, int len, int status){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == FULL && list[i].status == status){
				Return = 0;
				break;
			}
		}
	}
	return Return;
}

int findRequestById(sRequest* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == PENDING && list[i].id == id){
				Return = i;
				break;
			}
		}
	}

	return Return;
}

void getPlasticTypes(float total, float* HDPE, float* LDPE, float* PP, float* waste){
	float add;
	add = 0;

	printf(">>>Kilos restantes: %.2f.\n", total-add);
	getFinalFloat(&*HDPE, "Ingrese la cantidad de kilos del tipo Alta Densidad: ", "ERROR! La cantidad no puede ser negativa ni mayor al total: ", 0, total);
	add += *HDPE;

	printf(">>>Kilos restantes: %.2f.\n", total-add);
	getFinalFloat(&*LDPE, "Ingrese la cantidad de kilos del tipo Baja Densidad: ", "ERROR! La cantidad no puede ser negativa ni mayor al total: ", 0, total);
	while(*LDPE + add > total){
		getFinalFloat(&*LDPE, "ERROR! La cantidad supera el total de kilos indicado. Reingrese: ", "ERROR! La cantidad no puede ser negativa ni sumar más que el total: ", 0, total);
	}
	add += *LDPE;

	printf(">>>Kilos restantes: %.2f.\n", total-add);
	getFinalFloat(&*PP, "Ingrese la cantidad de kilos del tipo Polipropileno: ", "ERROR! La cantidad no puede ser negativa ni mayor al total: ", 0, total);
	while(*PP + add > total){
		getFinalFloat(&*PP, "ERROR! La cantidad supera el total de kilos indicado. Reingrese: ", "ERROR! La cantidad no puede ser negativa ni sumar más que el total: ", 0, total);
	}
	add += *PP;

	*waste = total - add;

}

int findFreeSpaceRequest(sRequest* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == EMPTY){
				Return = i;
				break;
			}
		}
	}

	return Return;
}

/*
 * Nexus.c
 *      Author: Marcos
 */

#include "Nexus.h"

int addRequest(sClient* clientList, int cliLen, sRequest* requestList, int reqLen, int clientId, int requestId){
	int Return;
	int index;
	Return = -1;

	if(clientList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		for(int i = 0; i < cliLen; i++){
			index = findClientById(clientList, cliLen, clientId);
			if(index != -1){
				Return = 0;
				requestList[i].id = requestId;
				getFinalFloat(&requestList[i].kilosTotal, "Ingrese la cantidad de kilos de residuos a recolectar: ", "ERROR! Ingrese una cantidad numérica mayor a 0 y menor a 20000: ", 0, 20000);
				requestList[i].status = PENDING;
				break;
			}
		}
	}

	return Return;
}

void loadRequest(sClient* clientList, int cliLen, sRequest* requestList, int reqLen, int clientId, int requestId){
//	int Return;
	int index;
//	Return = -1;

	if(clientList != NULL && cliLen > 0 && requestList != NULL && reqLen > 0){
		for(int i = 0; i < reqLen; i++){
			index = findRequestById(requestList, reqLen, requestId);
				if(index != -1){
					getPlasticTypes(requestList[i].kilosTotal, &requestList[i].kilosHDPE, &requestList[i].kilosLDPE, &requestList[i].kilosPP, &requestList[i].kilosWaste);
					break;
				}
		}
	}
}

void getPlasticTypes(float total, float* HDPE, float* LDPE, float* PP, float* waste){
	float add;
	add = 0;

	getFinalFloat(&*HDPE, "Ingrese la cantidad de kilos del tipo Alta Densidad: ", "ERROR! La cantidad no puede ser negativa ni mayor al total: ", 0, total);
	add += *HDPE;

	getFinalFloat(&*LDPE, "Ingrese la cantidad de kilos del tipo Baja Densidad: ", "ERROR! La cantidad no puede ser negativa ni mayor al total: ", 0, total);
	while(*LDPE + add > total){
		getFinalFloat(&*LDPE, "ERROR! La cantidad supera el total de kilos indicado. Reingrese: ", "ERROR! La cantidad no puede ser negativa ni sumar más que el total: ", 0, total);
	}
	add += *LDPE;

	getFinalFloat(&*PP, "Ingrese la cantidad de kilos del tipo Polipropileno: ", "ERROR! La cantidad no puede ser negativa ni mayor al total: ", 0, total);
	while(*PP + add > total){
		getFinalFloat(&*PP, "ERROR! La cantidad supera el total de kilos indicado. Reingrese: ", "ERROR! La cantidad no puede ser negativa ni sumar más que el total: ", 0, total);
	}
	add += *PP;

	*waste = total - add;

}

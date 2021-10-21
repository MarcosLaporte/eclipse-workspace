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
				getFinalFloat(&requestList[i].kilos, "Ingrese la cantidad de kilos de residuos a recolectar: ", "ERROR! Ingrese una cantidad numérica mayor a 0 y menor a 20000: ", 0, 20000);
				requestList[i].status = PENDING;
				break;
			}
		}
	}

	return Return;
}

int loadWastes(sClient* clientList, int cliLen, sRequest* requestList, int reqLen, int clientId, int requestId){

}

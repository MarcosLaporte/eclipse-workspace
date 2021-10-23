/*
 * Request.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include "Input.h"

typedef struct{
	int id; //PK
		float kilosTotal;
		float kilosHDPE;
		float kilosLDPE;
		float kilosPP;
		float kilosWaste;
	int clientId; //FK
	int status;
	int isEmpty;
}sRequest;

int initRequests(sRequest* list, int len);
int checkARequest(sRequest* list, int lenght);
int findRequestById(sRequest* list, int len, int id);
//sRequest searchRequestById(sRequest* list, int len, int id);
void getPlasticTypes(float total, float* HDPE, float* LDPE, float* PP, float* waste);
int findFreeSpaceRequest(sRequest* list, int len);

#endif /* REQUEST_H_ */

/*
 * Nexus.h
 *
 *  Created on: 20 oct. 2021
 *      Author: Marcos
 */

#ifndef NEXUS_H_
#define NEXUS_H_

#include "Input.h"
#include "Clients.h"
#include "Request.h"

int addRequest(sClient* clientList, int cliLen, sRequest* requestList, int reqLen, int clientId, int requestId);

void getPlasticTypes(float total, float* HDPE, float* LDPE, float* PP, float* waste);


#endif /* NEXUS_H_ */

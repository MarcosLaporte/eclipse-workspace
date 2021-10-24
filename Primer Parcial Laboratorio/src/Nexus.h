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

int addRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int requestId);
int printPendingRequestList(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);

int printPendingRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
int loadRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);

int countRequestsByClient(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int clientId);
int printOneCompletedRequest(sRequest request, sClient* clientsList, int cliLen);
int printCompletedRequestByClientId(sRequest* requestList, int reqLen, sClient* clientsList, int cliLen, int clientId);
int printCompletedRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
int countAveragePP(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, float* average);
void hardcodeClients(sClient* clientsList, sRequest* requestList, int maxClients, int* ids, int maxRequests, int* reqIds);

#endif /* NEXUS_H_ */

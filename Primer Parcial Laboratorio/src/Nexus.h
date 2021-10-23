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
int printRequest(sClient* clients, sRequest request, int reqLen);

int printPendingRequests(sClient* clientsList, int cliLen, sRequest* requests, int reqLen);
int loadRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);

int countRequestsByClient(sClient* cliList, int cliLen, sRequest* reqList, int reqLen, int clientId);
int printOneCompletedRequest(sRequest request, sClient* clientsList, int cliLen);
int printCompletedRequestByClientId(sRequest* requestList, int reqLen, sClient* clientsList, int cliLen, int clientId);
int printCompletedRequests(sClient* clients, int cliLen, sRequest* requests, int reqLen);

int printLocalityRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
void hardcodeClients(sClient* clients, sRequest* requests, int maxClients, int* ids, int maxRequests, int* reqIds);

#endif /* NEXUS_H_ */

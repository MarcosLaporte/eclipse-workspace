/*
 * Clients.h
 *      Author: Marcos
 */

#ifndef CLIENTS_H_
#define CLIENTS_H_

#include "Input.h"

typedef struct{
	char address[51];
	int number;
	char locality[51];
}sPlace;

typedef struct{
	int id; //PK
	char companyName[MAX_CHARAC];
	char cuit[14]; //20-44567890-9
	sPlace direction;
	int pendingRequests;
	int status;
}sClient;

int initClients(sClient* list, int len);
sClient getClient(void);
void formatCuit(char input[]);
int addClient(sClient* list, int len, int id);
int findClientById(sClient* list, int len, int id);
int modifyClient(sClient* list, int length, int id);
int checkAClient(sClient* list, int lenght);
sClient searchRequestById(sClient* list, int len, int id);
sClient searchClientById(sClient* list, int len, int id);
int removeClient(sClient* list, int len, int id);
int initPendingRequests(sClient* list, int len);
int printClient(sClient client);
int printClientList(sClient* list, int len);
int calculateLocalityRequests(sClient* list, int len, char locality[], int* accum);

#endif /* CLIENTS_H_ */

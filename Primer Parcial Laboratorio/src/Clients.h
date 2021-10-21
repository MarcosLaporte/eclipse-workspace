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
	int id;
	char companyName[21];
	char cuit[14]; //20-44567890-9
	sPlace direction;
	int idRequest; //FK
	int status;
}sClient;

int initClients(sClient* list, int len);
sClient getClient(void);
void formatCuit(char input[]);
int addClient(sClient* list, int len, int id);
int findClientById(sClient* list, int len, int id);
int modifyClient(sClient* list, int length, int id);
int checkAClient(sClient* list, int lenght);
int printClients(sClient* list, int len);
void printList(sClient* list, int len);
int removeClient(sClient* list, int len, int id);

#endif /* CLIENTS_H_ */

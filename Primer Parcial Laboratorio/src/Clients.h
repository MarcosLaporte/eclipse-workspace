/*
 * Clients.h
 *
 *  Created on: 20 oct. 2021
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
int isValidCuit(char input[]);
int addClient(sClient* list, int len, int id);
int formatCuit(char input[]);

#endif /* CLIENTS_H_ */

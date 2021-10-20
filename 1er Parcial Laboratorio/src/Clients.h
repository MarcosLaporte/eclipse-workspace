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

#endif /* CLIENTS_H_ */

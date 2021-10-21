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
	int id;
	float kilos;
	int status;
}sRequest;

int initRequests(sRequest* list, int len);

#endif /* REQUEST_H_ */

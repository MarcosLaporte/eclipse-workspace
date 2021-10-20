/*
 * Nexus.h
 *
 *  Created on: 19 oct. 2021
 *      Author: Marcos
 */

#ifndef NEXUS_H_
#define NEXUS_H_

#include "Input.c"
#include "Clients.c"
#include "Collection.c"

sClient getClient(void);
int addClient(sClient* list, int len, int id);




#endif /* NEXUS_H_ */

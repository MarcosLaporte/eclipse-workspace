/*
 * Locality.h
 *      Author: Marcos
 */

#ifndef LOCALITY_H_
#define LOCALITY_H_

#include "Input.h"

typedef struct{
	int localId;
	char description[51];
}sLocality;

int findLocalityById(sLocality* list, int len, int id);

#endif /* LOCALITY_H_ */

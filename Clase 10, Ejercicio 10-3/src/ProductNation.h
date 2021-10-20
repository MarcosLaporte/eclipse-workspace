/*
 * ProductNation.h
 *      Author: Marcos
 */

#ifndef PRODUCTNATION_H_
#define PRODUCTNATION_H_
#include "Input.h"

#define EMPTY 0
#define FULL 1

typedef struct {
	int nationId;
	char descriptionNation[51];
	int status;
} sNation;

sNation searchNationById(sNation *list, int len, int id);

#endif /* PRODUCTNATION_H_ */

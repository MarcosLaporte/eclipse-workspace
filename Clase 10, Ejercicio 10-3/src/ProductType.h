/*
 * tipoProducto.h
 *      Author: Marcos
 */

#ifndef TIPOPRODUCTO_H_
#define TIPOPRODUCTO_H_
#include "Input.h"

#define EMPTY 0
#define FULL 1

typedef struct {
	int typeId;
	char description[51];
	int status;
} sType;

void printProductType(sType *list, int len);
sType searchTypeById(sType *list, int len, int id);

#endif /* TIPOPRODUCTO_H_ */

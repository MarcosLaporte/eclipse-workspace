/*
 * tipoProducto.h
 *      Author: Marcos
 */

#ifndef TIPOPRODUCTO_H_
#define TIPOPRODUCTO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int typeId;
	char description[51];
}sType;

void printProductType(sType* list, int len);

#endif /* TIPOPRODUCTO_H_ */

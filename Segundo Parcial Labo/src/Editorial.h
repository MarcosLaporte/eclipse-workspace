/*
 * Editorial.h
 *
 *  Created on: 26 nov. 2021
 *      Author: Marcos
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "Input.h"

typedef struct{
	int idEdit;
	char descr[EDIT_LEN];
}Edit;

Edit* edit_new();

Edit* edit_newParam(char* idStr, char* descrStr);

int edit_setId(Edit* this, int id);
int edit_getId(Edit* this, int* id);

int edit_setName(Edit* this, char* name);
int edit_getName(Edit* this, char* name);


#endif /* EDITORIAL_H_ */

/*
 * Structures.h
 *      Author: Marcos
 */

#include "Input.h"

typedef struct{
	int day;
	int month;
	int year;
}Date;

typedef struct{
	int id;
	char name[51];
	Date birthday;
}Person;

int printById(Person* list, int len, int id);

Date getDate(char message[]);

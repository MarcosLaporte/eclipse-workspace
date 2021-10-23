/*
 * Structures.c
 *      Author: Marcos
 */
#include "Structures.h"

Date getDate(char message[]){
	Date entireDate;

	entireDate.day = getLimitedInt("Ingrese el día: ", "ERROR! Ingrese un día entre 1 y 31: ", 1, 31);
	entireDate.month = getLimitedInt("Ingrese el mes: ", "ERROR! Ingrese un mes entre 1 y 12: ", 1, 12);
	entireDate.year = getLimitedInt("Ingrese el año: ", "ERROR! Ingrese una fecha entre %min y %max:", 1900, 2021);

	return entireDate;
}

//Imprime solo el del ID
int printById(Person* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id){
				printf("%2d %10s %2d/%2d/%4d\n", list[i].id, list[i].name, list[i].birthday.day,
								list[i].birthday.month, list[i].birthday.year);
				break;
			}
		}
	}

	return Return;
}

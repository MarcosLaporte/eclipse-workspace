/*
 * Locality.c
 *      Author: Marcos
 */

#include "Locality.h"

int findLocalityById(sLocality* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].localId == id){
				Return = i;
				break;
			}
		}
	}

	return Return;
}

/*
 * Request.c
 *      Author: Marcos
 */

#include "Request.h"

int initRequests(sRequest* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			Return = 0;
			list[i].status = NO_REQ;
		}
	}

	return Return;
}

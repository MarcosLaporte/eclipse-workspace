/*
 * Pilot.c
 *      Author: Marcos
 */

#include "Pilot.h"

sFlight* flight_new(){
	sFlight* myFlight;
	myFlight = (sFlight*)calloc(1, sizeof(sFlight));
	return myFlight;
}

sFlight* flight_newByParameters(char* idFlight, char* idPlane, char* idPilot, char*
			date, char* dest, char* passen, char* depart, char* arrival){
	if(idFlight != NULL && idPlane != NULL && idPilot != NULL && date != NULL
			&& dest != NULL && passen != NULL && depart != NULL && arrival != NULL){

	}
}

int flight_setId(sFlight* this, int id){

}

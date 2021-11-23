/*
 * Pilot.h
 *      Author: Marcos
 */

#ifndef PILOT_H_
#define PILOT_H_
#include "Input.h"

typedef struct{
	int idFlight;
	int idPlane;
	int idPilot;
	char date[11];
	char dest[25];
	int passen;
	int depart;
	int arrival;
}sFlight;



#endif /* PILOT_H_ */

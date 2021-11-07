/*
 * Locality.h
 *      Author: Marcos
 */

#ifndef LOCALITY_H_
#define LOCALITY_H_

#include "Input.h"

typedef struct{
	int localId;
	char description[51];
}sLocality;

//---------------------------------------------------------------------------------
/// @brief
///
/// @param list - Puntero al array de localidad.
/// @param len - Indica el tama�o del array.
/// @param id - Id de la localidad a buscar.
/// @return int - Retorna la posici�n del id si lo encuentra, y -1 si no.
int findLocalityById(sLocality* list, int len, int id);
//---------------------------------------------------------------------------------

#endif /* LOCALITY_H_ */

/*
 * Clients.c
 *
 *  Created on: 19 oct. 2021
 *      Author: Marcos
 */

#include "Clients.h"

int initClients(sClient* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			Return = 0;
			list[i].status = EMPTY;
		}
	}

	return Return;
}

sClient getClient(){
	sClient costumer;

	getString("¬ Ingrese el nombre de la empresa: ", costumer.companyName, 51);
	while(checkAlphabetAndSpace(costumer.companyName) == -1){
		getString("¬ ERROR! Ingrese un nombre SOLO con letras (sin tildes ni Ñ): ", costumer.companyName, 51);
	}
	formatString(costumer.companyName);

	getString("¬ Ingrese el CUIT (00-12345678-9): ", costumer.cuit, 14);
	while(isValidCuit(costumer.cuit) == -1){
		getString("¬ ERROR! Ingrese un CUIT válido (Ejemplo: 00-12345678-9): ", costumer.cuit, 14);
	}

	getString("¬ Ingrese la dirección de la empresa: ", costumer.direction.address, 51);
	while(strlen(costumer.direction.address) > 51 || checkAlphabetAndSpace(costumer.direction.address) == 0){
		getString("¬ ERROR! Ingrese la dirección de la empresa (máximo 51 caracteres): ", costumer.direction.address, 51);
	}
	formatString(costumer.direction.address);

	getFinalInt(costumer.direction.number, "¬ Ingrese el número de la empresa: ", "¬ ERROR! Ingrese el número de la empresa: ", 0, 99999);

	getString("¬ Ingrese la dirección de la empresa: ", costumer.direction.locality, 51);
	while(strlen(costumer.direction.locality) > 51){
		getString("¬ ERROR! Ingrese la dirección de la empresa (máximo 51 caracteres): ", costumer.direction.locality, 51);
	}
	formatString(costumer.direction.locality);

	as = EMPTY;

	costumer.status = FULL;

	return costumer;
}

int addClient(sClient* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == EMPTY){
				Return = 0;
				list[i] = getClient();
				list[i].id = id;
				break;
			}
		}
	}

	return Return;
}

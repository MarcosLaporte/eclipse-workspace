/*
 * Clients.c
 *
 *  Created on: 20 oct. 2021
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
	sClient customer;

	getString("¬ Ingrese el nombre de la empresa: ", customer.companyName, 51);
	while(checkAlphabetAndSpace(customer.companyName) == 0){
		getString("¬ ERROR! Ingrese un nombre SOLO con letras (sin tildes ni Ñ): ", customer.companyName, 51);
	}
	formatString(customer.companyName);

	getString("¬ Ingrese el CUIT: ", customer.cuit, 14);
	while(isValidCuit(customer.cuit) == -1){
		getString("¬ ERROR! Ingrese un CUIT válido (Ejemplo: 00-12345678-9): ", customer.cuit, 14);
	}

	getString("¬ Ingrese la calle donde se encuentra la empresa: ", customer.direction.address, 51);
	while(strlen(customer.direction.address) > 51 || checkAlphabetAndSpace(customer.direction.address) == 0){
		getString("¬ ERROR! Ingrese la calle donde se encuentra la empresa (máximo 51 caracteres): ", customer.direction.address, 51);
	}
	formatString(customer.direction.address);

	getFinalInt(&customer.direction.number, "¬ Ingrese la altura de la calle donde se encuentra la empresa: ", "¬ ERROR! Ingrese una altura numérica: ", 0, 99999);

	getString("¬ Ingrese la localidad de la empresa: ", customer.direction.locality, 51);
	while(strlen(customer.direction.locality) > 51){
		getString("¬ ERROR! Ingrese la localidad de la empresa (máximo 51 caracteres): ", customer.direction.locality, 51);
	}
	formatString(customer.direction.locality);

	customer.status = FULL;

	return customer;
}

int isValidCuit(char input[]){
	int Return;
	Return = 0;
	for(int i = 0; i < 14 && input[i] != '\0'; i++){
		if((i == 2 || i == 11) && input[i] == '-'){
			continue;
		}
		if((strlen(input) != 13 && strlen(input) != 11) || input[i] > '9' || input[i] < '0' || input[i] == '-'){
			Return = -1;
			break;
		}
	}

	return Return;
}

int formatCuit(char input[]){
	int Return;
	char auxType[3];
	char auxDNI[9];
	char auxRandom[2];
	Return = -1;

	if(input[2] != '-'){
		strncpy(auxType, input, 2);
	}
	if(input[11] != '-'){
//		strcpy
	}

	strcat(auxType, "-");
	strcat(auxType, auxDNI);
	strcat(auxType, "-");
	strcat(auxType, auxRandom);

	return Return;
}
//	for(int i = 0; i < 14; i++){
//		if(i < 2){
//
//		}
//	}

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



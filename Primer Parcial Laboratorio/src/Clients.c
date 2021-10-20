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

	//Nombre
	getString("¬ Ingrese el nombre de la empresa: ", customer.companyName, 51);
	while(checkAlphabetAndSpace(customer.companyName) == 0){
		getString("¬ ERROR! Ingrese un nombre SOLO con letras (sin tildes ni Ñ): ", customer.companyName, 51);
	}
	formatString(customer.companyName);

	//CUIT
	getString("¬ Ingrese el CUIT sin espapcios ni guiones: ", customer.cuit, 14);
	while(isAnInt(customer.cuit, 14) == -1 || strlen(customer.cuit) != 11){
		getString("¬ ERROR! Ingrese un CUIT válido (01234567890): ", customer.cuit, 14);
	}
	formatCuit(customer.cuit);

	//Calle
	getString("¬ Ingrese la calle donde se encuentra la empresa: ", customer.direction.address, 51);
	while(strlen(customer.direction.address) > 51 || checkAlphabetAndSpace(customer.direction.address) == 0){
		getString("¬ ERROR! Ingrese la calle donde se encuentra la empresa (máximo 51 caracteres): ", customer.direction.address, 51);
	}
	formatString(customer.direction.address);

	//Altura
	getFinalInt(&customer.direction.number, "¬ Ingrese la altura de la calle donde se encuentra la empresa: ", "¬ ERROR! Ingrese una altura numérica: ", 0, 99999);

	//Localidad
	getString("¬ Ingrese la localidad de la empresa: ", customer.direction.locality, 51);
	while(strlen(customer.direction.locality) > 51){
		getString("¬ ERROR! Ingrese la localidad de la empresa (máximo 51 caracteres): ", customer.direction.locality, 51);
	}
	formatString(customer.direction.locality);

	//Estado
	customer.status = FULL;

	return customer;
}

void formatCuit(char input[]){
	char auxCUIT[14];
	int j = 0;

	for(int i = 0; i < 14; i++){
		if(i != 2 && i != 11){
			auxCUIT[i] = input[j];
			j++;
		}else{
			auxCUIT[i] = '-';
		}
	}

	strcpy(input, auxCUIT);
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

int findClientById(sClient* list, int len, int id){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL && list[i].id == id){
				Return = i;
				break;
			}
		}
	}

	return Return;
}

int modifyClient(sClient* list, int length, int id){
	int Return;
	int index;
	Return = -1;

	if(list != NULL && length > 0){
		index = findClientById(list, length, id);
		if(index != -1){
			if(list[index].status == FULL){
				Return = 0;
				//Calle
				getString("¬ Ingrese la nueva calle: ", list[index].direction.address, 51);
				while(strlen(list[index].direction.address) > 51 || checkAlphabetAndSpace(list[index].direction.address) == 0){
					getString("¬ ERROR! Ingrese una calle nueva (máximo 51 caracteres): ", list[index].direction.address, 51);
				}
				formatString(list[index].direction.address);
				//Altura
				getFinalInt(&list[index].direction.number, "¬ Ingrese una altura nueva: ", "¬ ERROR! Ingrese una altura nueva numérica: ", 0, 99999);
				//Localidad
				getString("¬ Ingrese la localidad nueva de la empresa: ", list[index].direction.locality, 51);
				while(strlen(list[index].direction.locality) > 51){
					getString("¬ ERROR! Ingrese una localidad nueva (máximo 51 caracteres): ", list[index].direction.locality, 51);
				}
				formatString(list[index].direction.locality);
			}
		}
	}

	return Return;
}

int removeClient(sClient* list, int len, int id){
	int Return;
	int index;
	char confirm[10];
	int r;
	Return = 0;

	if(list != NULL && len > 0){
		index = findClientById(list, len, id);
		if(index != -1){
			r = getConfirmation("Esta acción no puede deshacerse. Escriba 'CONFIRMAR' para eliminar: ", "CONFIRMAR", "CANCELAR", confirm, 10, 3);
			if(r == 1){
				Return = 1;
				list[index].status = EMPTY;
			}else{
				Return = -1;
			}
		}
	}

	return Return;
}

int checkAClient(sClient* list, int lenght){
	int Return;
	Return = -1;

	if(list != NULL && lenght > 0){
		for(int i = 0; i < lenght; i++){
			if(list[i].status == FULL){
				Return = 0;
				break;
			}
		}
	}
	return Return;
}

int printClients(sClient* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL){
				Return = 0;
				printf("|%4d|%20s|%15s|%25s %5d|%20s|\n", list[i].id, list[i].companyName, list[i].cuit, list[i].direction.address, list[i].direction.number, list[i].direction.locality);
				printf("#----+--------------------+---------------+-------------------------------+--------------------#\n");
			}
		}
	}

	return Return;
}

void printList(sClient* list, int len){
	if(list != NULL && len > 0){
		printf("#----+--------------------+---------------+-------------------------------+--------------------#\n");
		printf("|%-4s|%-20s|%-15s|%-31s|%-20s|\n","ID","Nombre de la empresa", "CUIT", "Dirección", "Localidad");
		printf("#----+--------------------+---------------+-------------------------------+--------------------#\n");
		if(printClients(list, len) == -1){
			printf("Ocurrió un error.\n");
		}
	}
}

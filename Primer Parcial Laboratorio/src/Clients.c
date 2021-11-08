/*
 * Clients.c
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
	getName(customer.companyName);
	//CUIT
	getCuit(customer.cuit);
	//Calle
	getAddress(customer.direction.address);
	//Altura
	getFinalInt(&customer.direction.number, "¬ Ingrese la altura de la calle donde se encuentra la empresa: ", "¬ ERROR! Ingrese una altura numérica: ", 0, 99999);
	//Localidad
	getFinalInt(&customer.direction.idLocal, "¬ Elija la localidad de la empresa.\n\t1. Barracas\n\t2. Avellaneda\n\t3. MicroCentro\n\t4. Once\n"
											"\t5. Flores.\n\tIngrese una opción: ", "ERROR! Ingrese una localidad existente: ", 1, 5);
//	getLocal(customer.direction.locality);
	//Pedidos pendientes
	customer.pendingRequests = 0;
	//Estado
	customer.status = FULL;

	return customer;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//Datos cliente
void getName(char input[]){
	getString("¬ Ingrese el nombre de la empresa: ", input, MAX_CHARAC);
	while(checkAlphabetAndSpace(input) == 0 || strlen(input) < 1){
		if(checkAlphabetAndSpace(input) == 0){
			getString("¬ ERROR! Ingrese un nombre solo con letras: ", input, MAX_CHARAC);
		}
		if(strlen(input) > 51 || strlen(input) < 1){
			getString("¬ ERROR! Este campo no puede quedar vacío ni superar los 50 caracteres. Reingrese: ", input, MAX_CHARAC);
		}
	}
	formatString(input);
}

void getCuit(char input[]){
	getString("¬ Ingrese el CUIT sin espapcios ni guiones: ", input, 14);
	while(isUnsignedInt(input, 11) == -1 || strlen(input) != 11){
		getString("¬ ERROR! Ingrese un CUIT válido (01234567890): ", input, 14);
	}
	formatCuit(input);
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

void getAddress(char input[]){
	getString("¬ Ingrese la calle donde se encuentra la empresa: ", input, MAX_CHARAC);
	while(strlen(input) > MAX_CHARAC){
		getString("¬ ERROR! Ingrese la calle donde se encuentra la empresa (máximo 50 caracteres): ", input, MAX_CHARAC);
	}
	formatString(input);
}
/*
void getLocal(char input[]){
	getString("¬ Ingrese la localidad de la empresa: ", input, MAX_CHARAC);
	while((strlen(input) > MAX_CHARAC || strlen(input) < 1) || checkAlphabetAndSpace(input) == 0){
		if(checkAlphabetAndSpace(input) == 0){
			getString("¬ ERROR! Este campo solo admite letras. Reingrese: ", input, MAX_CHARAC);
		}
		if(strlen(input) > MAX_CHARAC || strlen(input) < 1){
			getString("¬ ERROR! Este campo no puede quedar vacío ni superar los 50 caracteres. Reingrese: ", input, MAX_CHARAC);
		}
	}
	formatString(input);
}*/

//////////////////////////////////////////////////////////////////////////////////////////////

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

int modifyClient(sClient* list, int len, int id){
	int Return;
	int index;
	Return = -1;

	if(list != NULL && len > 0){
		index = findClientById(list, len, id);
		if(index != -1){
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
//				getString("¬ Ingrese la localidad nueva de la empresa: ", list[index].direction.locality, 51);
//				while(strlen(list[index].direction.locality) > 51){
//					getString("¬ ERROR! Ingrese una localidad nueva (máximo 51 caracteres): ", list[index].direction.locality, 51);
//				}
//				formatString(list[index].direction.locality);
			getFinalInt(&list[index].direction.idLocal, "Elija la nueva localidad de la empresa.\n\t1. Barracas\n\t2. Avellaneda\n\t3. MicroCentro\n"
													"\t4. Once\n\t5. Flores.\n\tIngrese una opción: ", "ERROR! Ingrese una localidad existente: ", 1, 5);
		}
	}

	return Return;
}

int removeClient(sClient* list, int len, int id){
	int Return;
	int index;
	int r;
	Return = 0;

	if(list != NULL && len > 0){
		index = findClientById(list, len, id);
		if(index != -1){
			if(list[index].pendingRequests > 0){
				printf("Este cliente tiene pedidos pendientes!\n");
			}
			r = getConfirmation("Esta acción no puede deshacerse. Escriba 'CONFIRMAR' para eliminar: ", "CONFIRMAR", "CANCELAR", 10, 3);
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

int checkAClient(sClient* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL){
				Return = 0;
				break;
			}
		}
	}
	return Return;
}

int initPendingRequests(sClient* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			Return = 0;
			list[i].pendingRequests = 0;
		}
	}

	return Return;
}

int initCompletedRequests(sClient* list, int len){
	int Return;
	Return = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			Return = 0;
			list[i].completedRequests = 0;
		}
	}

	return Return;
}

sClient searchClientById(sClient* list, int len, int id){
	sClient aux;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].status == FULL && list[i].id == id){
				aux = list[i];
				break;
			}
		}
	}

	return aux;
}

int calcMostRequests(sClient* list, int len, int reqStatus, int* max){
	int Return;
	int maxRequests;
	Return = -1;
	maxRequests = 0;

	if(list != NULL && len > 0){
		switch(reqStatus){
		case PENDING:
			for(int i = 0; i < len; i++){
				if(list[i].status == FULL && list[i].pendingRequests > maxRequests){
					maxRequests = list[i].pendingRequests;
//					*client = list[i];
					*max = maxRequests;
					Return = 0;
				}
			}
			break;
		case COMPLETED:
			for(int i = 0; i < len; i++){
				if(list[i].status == FULL && list[i].completedRequests > maxRequests){
					maxRequests = list[i].completedRequests;
//					*client = list[i];
					*max = maxRequests;
					Return = 0;
				}
			}
			break;
		case BOTH:
			for(int i = 0; i < len; i++){
				if(list[i].status == FULL && (list[i].pendingRequests + list[i].completedRequests) > maxRequests){
					maxRequests = list[i].pendingRequests + list[i].completedRequests;
//					*client = list[i];
					*max = maxRequests;
					Return = 0;
				}
			}
			break;
		}
	}

	return Return;
}

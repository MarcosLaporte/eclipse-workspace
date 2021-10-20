/*
 * Nexus.c
 *      Author: Marcos
 */
#include "Nexus.h"

int printProductsWithType(sProduct* prodList, int prodLen, sType* typeList, int typeLen, sNation* nationList, int natLen){
	int Return;
	Return = -1;

	if(prodList != NULL && prodLen > 0 && typeList != NULL && typeLen > 0){
		for(int i = 0; i < prodLen; i++){
			if(prodList[i].status == FULL){
				if(printOnlyOne(prodList[i], typeList, typeLen, nationList, natLen) == -1){
					printf("Falló :(\n");
				}
				Return = 0;
			}
		}
	}

	return Return;
}

int printOnlyOne(sProduct prodList, sType* typeList, int typeLen, sNation* nationList, int natLen){
	int isOkay;
	sNation auxN;
	sType auxT;
	isOkay = -1;

	if(typeList != NULL && typeLen > 0){
		isOkay = 0;
		auxN = searchNationById(nationList, natLen, prodList.nationality);
		auxT = searchTypeById(typeList, typeLen, prodList.type);
		printf("|%4d|%15s|%6s|%11s|%7.2f|\n", prodList.idProduct, prodList.description,
										auxN.descriptionNation, auxT.description, prodList.price);
	}

	return isOkay;
}

int printProductsById(sProduct* prodList, int prodLen, sType* typeList, int typeLen, sNation* nationList, int natLen, int id){
	int Return;
	Return = -1;

	if(prodList != NULL && prodLen > 0 && typeList != NULL && typeLen > 0){
		for(int i = 0; i < prodLen; i++){
			if(prodList[i].status == FULL && prodList[i].idProduct == id){
				printOnlyOne(prodList[i], typeList, typeLen, nationList, natLen);
				Return = 0;
				break;
			}
		}
	}

	return Return;
}

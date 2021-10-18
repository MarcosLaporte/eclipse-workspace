/*
 * Input.c
 *      Author: Marcos
 */

#include "Input.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getInt(char message[]){
	int number;

	printf("%s", message);
	scanf("%d", &number);

	return number;
}

int getLimitedInt(char message[], char errorMessage[], int min, int max){
	int number;

	printf("%s", message);
	scanf("%d", &number);
	while(number < min || number > max){
			printf("%s", errorMessage);
			scanf("%d", &number);
	}

	return number;
}

float getFloat(char message[]){
	float number;

	printf("%s", message);
	scanf("%f", &number);

	return number;
}

float getLimitedFloat(char message[], char errorMessage[], int min, int max){
	float number;

	printf("%s", message);
	scanf("%f", &number);
	while(number < min || number > max){
		printf("%s", errorMessage);
		scanf("%f", &number);
	}

	return number;
}

//Vectores
void getSequentialArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max){
	int i;

	for(i = 0; i < length; i++){
		printf("%s", message);
		scanf("%d", &list[i]);
		while(list[i] < min || list[i] > max){
			printf("%s", errorMessage);
			scanf("%d", &list[i]);
		}
	}
}

void getRandomArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max){
	int i;
	char keepGoing;

	do{
		printf("En qué posición desea ingresar el número?: ");
		scanf("%d", &i);
		while(i < 1 || i > length){
			printf("Ingrese una posición entre 1 y %d: ", length);
			scanf("%d", &i);
		}
		printf("%s", message);
		scanf("%d", &list[i-1]);
		while(list[i-1] < min || list[i-1] > max){
			printf("%s", errorMessage);
			scanf("%d", &list[i-1]);
		}

		printf("Desea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &keepGoing);
		keepGoing = tolower(keepGoing);
		while(!(keepGoing == 's' || keepGoing == 'n')){
			printf("Si desea continuar escriba 's', si no, 'n': ");
			fflush(stdin);
			scanf("%c", &keepGoing);
			keepGoing = tolower(keepGoing);
		}
	}while(keepGoing == 's');
}

void printArrayInt(char message[], int list[], int length){
	int i;

	printf("%s\n", message);
	for(i = 0; i < length; i++){
		printf("%d\n", list[i]);
	}
}

void getSequentialArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max){
	int i;

	for(i = 0; i < length; i++){
		printf("%s", message);
		scanf("%f", &list[i]);
		while(list[i] < min || list[i] > max){
			printf("%s", errorMessage);
			scanf("%f", &list[i]);
		}
	}
}

void getRandomArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max){
	int i;
	char keepGoing;

	do{
		printf("En qué posición desea ingresar el número?: ");
		scanf("%d", &i);
		while(i < 1 || i > length){
			printf("Ingrese una posición entre 1 y %d: ", length);
			scanf("%d", &i);
		}
		printf("%s", message);
		scanf("%f", &list[i-1]);
		while(list[i-1] < min || list[i-1] > max){
			printf("%s", errorMessage);
			scanf("%f", &list[i-1]);
		}

		printf("Desea continuar? s/n: ");
		fflush(stdin);
		scanf("%c", &keepGoing);
		keepGoing = tolower(keepGoing);
		while(!(keepGoing == 's' || keepGoing == 'n')){
			printf("Si desea continuar escriba 's', si no, 'n': ");
			fflush(stdin);
			scanf("%c", &keepGoing);
			keepGoing = tolower(keepGoing);
		}
	}while(keepGoing == 's');
}

void printArrayFloat(char message[], float list[], int length){
	int i;

	printf("%s\n", message);
	for(i = 0; i < length; i++){
		printf("%.2f\n", list[i]);
	}
}

void getString(char message[], char input[], int length){
	printf("%s", message);
	fflush(stdin);
	fgets(input, length, stdin);
	length = strlen(input);
	input[length-1] = '\0';
}

int getMenuOption(){
	int option;

	printf("\n1. Dar de alta\n");
	printf("2. Modificar\n");
	printf("3. Dar de baja\n");
	printf("4. Informar\n");
	printf("5. Salir\n");

	option = getLimitedInt("Elija una opción: ", "ERROR. Elija una opción entre 1 y 5: ", 1, 5);

	return option;
}

int getModificationMenu(){
	int option;

	printf("  1. Nombre\n");
	printf("  2. Apellido\n");
	printf("  3. Salario\n");
	printf("  4. Sector\n");
	printf("  0. Cancelar\n");

	option = getLimitedInt("Elija una opción para modificar: ", "ERROR. Elija una opción entre 0 y 4: ", 0, 4);

	return option;
}

void formatName(char input[]){
	int length;
	length = strlen(input);

	if(input != NULL){
		strlwr(input);
		for(int i = 0; i < length; i++){
			if(i == 0 || isspace(input[i-1])){
				input[i] = toupper(input[i]);
			}
		}
	}
}

int checkAlphabetAndSpace(char input[]){
	int length = strlen(input);
	int Return = 0;
	for(int i = 0; i < length; i++){
		if(length == 0 || (isalpha(input[i]) == 0 && isspace(input[i]) == 0)){
			Return = -1;
			break;
		}
	}
	return Return;
}

int myGets(char input[], int length){
	int Return;
	char aux[3000];
	Return = -1;
	if(input != NULL && length > 0) {
		fflush(stdin);
		scanf("%[^\n]", aux);
		if(strnlen(aux, sizeof(aux)) <= length){
			strncpy(input, aux, length);
			Return = 0;
		}
	}

	return Return;
}

int isAnInt(char input[], int length){
	int Return;
	int i;
	Return = 0;
	for(i = 0; i < length  && input[i] != '\0' ; i++){
		if(i == 0 && (input[i] == '-' || input[i] == '+')){
			continue;
		}
		if(input[i] > '9' || input[i] < '0'){
			Return = -1;
			break;
		}
	}

	return Return;
}

int getAnInt(int* refResult){
	int Return;
	char aux[3000];
	Return = -1;

	if(refResult != NULL && myGets(aux, sizeof(aux)) == 0 && isAnInt(aux, sizeof(aux)) == 0){
		*refResult = atoi(aux);
		Return = 0;
	}

	return Return;
}

int getFinalInt(int* refResult, char message[], char errorMessage[], int min, int max){
	int Return;
	int number;
	int auxNumber;
	Return = -1;
	if (refResult != NULL && message != NULL && errorMessage != NULL && min <= max){
		printf("%s", message);
		auxNumber=getAnInt(&number);
		while(auxNumber != 0 || number < min || number > max){
			printf("%s", errorMessage);
			auxNumber = getAnInt(&number);
		}
		*refResult = number;
		Return = 0;
	}

	return Return;
}

int isAFloat(char input[], int length){
	int Return;
	int i;
	int pointCont;
	Return = 0;
	pointCont = 0;
	for(i = 0; i < length  && input[i] != '\0' ; i++){
		if(input[i] == '.'){
			pointCont++;
		}
		if((i == 0 && (input[i] == '-' || input[i] == '+')) || input[i] == '.'){
			continue;
		}
		if(input[i] > '9' || input[i] < '0' || pointCont > 1){
			Return = -1;
			break;
		}
	}

	return Return;
}

int getAFloat(float* refResult){
	int Return;
	char aux[3000];
	Return = -1;

	if(refResult != NULL && myGets(aux, sizeof(aux)) == 0 && isAFloat(aux, sizeof(aux)) == 0){
		*refResult = atof(aux);
		Return = 0;
	}

	return Return;
}

int getFinalFloat(float* refResult, char message[], char errorMessage[], int min, int max){
	int Return;
	float number;
	float auxNumber;
	Return = -1;
	if (refResult != NULL && message != NULL && errorMessage != NULL && min <= max){
		printf("%s", message);
		auxNumber=getAFloat(&number);
		while(auxNumber != 0 || number < min || number > max){
			printf("%s", errorMessage);
			auxNumber = getAFloat(&number);
		}
		*refResult = number;
		Return = 0;
	}

	return Return;
}

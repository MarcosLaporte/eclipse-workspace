/*
 * Input.c
 *      Author: Marcos
 */

#include "Input.h"

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
		printf("En qu� posici�n desea ingresar el n�mero?: ");
		scanf("%d", &i);
		while(i < 1 || i > length){
			printf("Ingrese una posici�n entre 1 y %d: ", length);
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
		printf("En qu� posici�n desea ingresar el n�mero?: ");
		scanf("%d", &i);
		while(i < 1 || i > length){
			printf("Ingrese una posici�n entre 1 y %d: ", length);
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
	int Return = 1;
	for(int i = 0; i < length; i++){
		if(length == 0 && isalpha(input[i]) == 0 && isspace(input[i]) == 0){
			Return = 0;
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

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int printMenu(){
	int option;

	printf("\n0) SALIR\n");
	printf("1) Alta Producto\n");
	printf("2) Baja Producto\n");
	printf("3) Modificaci�n\n");
	printf("4) Listado Productos\n");
	printf("5) Listado ordenado por precio\n");
	printf("6) Listado ordenado por descripci�n\n");
	printf("7) El/los productos m�s caros\n");
	printf("8) Los productos que cuestan 700\n");
	printf("9) Precio promedio por tipo de producto\n");
	printf("10) De los Iphone el m�s barato\n");
	printf("11) Los productos 'MADE IN CHINA'\n");
	printf("12) Las MAC que cuestan m�s de 700 USD\n");
	printf("13) El/Los Accesorios m�s caros\n");


	getFinalInt(&option, "Elija una opci�n: ", "ERROR! Elija una opci�n existente: ", 0, 13);

	return option;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Date getDate(char message[]){
	Date entireDate;

	entireDate.day = getLimitedInt("Ingrese el d�a: ", "ERROR! Ingrese un d�a entre 1 y 31: ", 1, 31);
	entireDate.month = getLimitedInt("Ingrese el mes: ", "ERROR! Ingrese un mes entre 1 y 12: ", 1, 12);
	entireDate.year = getLimitedInt("Ingrese el a�o: ", "ERROR! Ingrese una fecha entre %min y %max:", 1900, 2021);

	return entireDate;
}

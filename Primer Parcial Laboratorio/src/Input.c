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

void formatString(char input[]){
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
		if(length == 0 || (isalpha(input[i]) == 0 && isspace(input[i]) == 0)){
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

int getConfirmation(char message[], char* confirmation, char* cancel, int length, int tries){
	int Return;
	char input[length];

	printf("%s", message);
	myGets(input, length);

	do{
		if(strcmpi(input, confirmation) != 0 && strcmpi(input, cancel) != 0){
			printf("ERROR! Asegúrese de escribir '%s' si desea confirmar o '%s' para cancelar la acción.\nLe quedan %d intentos: ", confirmation, cancel, tries);
			myGets(input, length);
			tries--;
		}else{
			if(strcmpi(input, confirmation) == 0){
				Return = 1;
			}else{
				if(strcmpi(input, cancel) == 0){
					Return = -1;
				}
			}
		}
	}while(tries > 0 && Return != 1 && Return != -1);

	if(tries == 0){
		Return = 0;
		printf("Muchos intentos fallidos. ");
	}

	return Return;
}

//-------------------------------------------------------------
int printMenu(){
	int option;

	printf("\n0) SALIR\n");
	printf("1) Alta Cliente\n");
	printf("2) Modificación Cliente\n");
	printf("3) Baja Cliente\n");
	printf("4) Crear pedido de recolección\n");
	printf("5) Procesar residuos\n");
	printf("6) Listado Clientes\n");
	printf("7) Imprimir Pedidos pendientes\n");
	printf("8) Imprimir Pedidos procesados\n");
	printf("9) Cantidad de pedidos pendientes por localidad\n");
	printf("10) Kilos de polipropileno reciclado por cliente\n");
	printf("11) Cliente con más pedidos pendientes.\n");
	printf("12) Cliente con más pedidos completados.\n");
	printf("13) Cliente con más pedidos.\n");


	getFinalInt(&option, "Elija una opción: ", "ERROR! Elija una opción existente: ", 0, 13);

	return option;
}
//-------------------------------------------------------------


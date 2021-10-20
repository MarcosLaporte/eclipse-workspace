/*
 ============================================================================
 Name        : 1er Parcial Laboratorio.c
 Author      : Marcos Laporte
 ============================================================================
 */

#include "Nexus.h"

int main(void){
	setbuf(stdout, NULL);

	printf("\t\t#=======================================#\n"
		   "\t\t|\t   Parcial Laboratorio 1\t|\n"
		   "\t\t|\t    --Marcos Laporte--\t\t|\n"
		   "\t\t#=======================================#\n");

	int option;
	sClient arrayClients[MAX_CLIENT];
	int ids;
	ids = 1;

	do{
		option = printMenu();
		switch(option){
		case 1:
			addClient(arrayClients, MAX_CLIENT, ids);
			break;
		case 2:

			break;
		case 4:

			break;
		case 3:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		case 8:

			break;
		case 9:

			break;
		case 10:

			break;
		case 0:
			printf("Ha salido del programa.\n");
			break;
		}

	}while(option != 0);

	return 0;
}

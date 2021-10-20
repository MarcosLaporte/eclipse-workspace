/*
 ============================================================================
 Name        : Primer Parcial Laboratorio.c
 Author      : Marcos Laporte
 ============================================================================
 */

#include "Nexus.h"

int main(void) {
	setbuf(stdout, NULL);

	printf("\t\t#=======================================#\n"
		   "\t\t|\t   Parcial Laboratorio 1\t|\n"
		   "\t\t|\t    --Marcos Laporte--\t\t|\n"
		   "\t\t#=======================================#\n");

	int option;
	sClient arrayClients[MAX_CLIENT] /*= {{1, "Neum�ticos SA", "23-44816742-9", {"California", 1371, "CABA"}, 1, FULL},
										{2, "Piedritas SA", "15-24912740-4", {"Salm�n Feij�o", 1266, "Barracas"}, 5, FULL},
										{3, "Joaquin", "30-21035468-7", {"Per�n", 520, "San Telmo"}, 2, FULL}
										{}}*/;
	int contIds;
	int id;
	int r;
	contIds = 1;

	initClients(arrayClients, MAX_CLIENT);

	do{
		option = printMenu();
		switch(option){
		case 1:
			if(addClient(arrayClients, MAX_CLIENT, contIds) == -1){
				printf("Ya se han ingresado la cantidad m�xima de clientes.\n");
			}else{
				printf("El ID del cliente es %d.\n", contIds);
				contIds++;
			}
			break;
		case 2:
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				printList(arrayClients, MAX_CLIENT);
				id = getInt("Ingrese el ID a del cliente a modificar: ");
				if(modifyClient(arrayClients, MAX_CLIENT, id) == -1){
					printf("ERROR! No existe un cliente con ese ID.\n");
				}else{
					printf("El cliente ha sido modificado!\n");
				}
			}
			break;
		case 3:
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				printList(arrayClients, MAX_CLIENT);
				id = getInt("Ingrese el ID del cliente a dar de baja: ");
				r = removeClient(arrayClients, MAX_CLIENT, id);
				if(r == -1){
					printf("La acci�n se ha cancelado.\n");
				}else{
					if(r == 0){
						printf("ERROR! No existe un cliente con ese ID.\n");
					}else{
						printf("El cliente ha sido dado de baja!\n");
					}
				}
			}
			break;
		case 4:

			break;
		case 5:

			break;
		case 6:
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				printList(arrayClients, MAX_CLIENT);
			}
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
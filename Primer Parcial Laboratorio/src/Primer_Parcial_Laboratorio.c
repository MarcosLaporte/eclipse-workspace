/*
 ============================================================================
 Name        : Primer Parcial Laboratorio.c
 Author      : Marcos Laporte
 ============================================================================
 */

/*===========================================================================
1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit, direcci�n y localidad.
	Se generar� un ID �nico para este cliente que se imprimir� por pantalla si el alta es correcta.

2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitir� cambiar la direcci�n y la localidad.

3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntar� si se quiere confirmar la eliminaci�n.

4) Crear pedido de recolecci�n: Se imprimir�n los clientes por pantalla y se pedir� que se ingrese el ID de un
	cliente existente y la cantidad de kilos totales que se recolectar�n del cliente. Se generar� un ID para el pedido
	y el mismo quedar� en estado �Pendiente� hasta que se obtengan los residuos del cliente y se trasladen a la empresa.

5) Procesar residuos: Se elegir� esta opci�n cuando los residuos que volvieron a la empresa se hayan procesado y separado
	en los diferentes tipos de pl�stico que la empresa puede reciclar. Se imprimir�n los pedidos por pantalla y se pedir�
	seleccionar el ID de uno de ellos. Luego deber�n ingresarse la cantidad de kilos de pl�stico de cada uno de los 3 tipos
	que la empresa puede procesar que se obtuvieron de los kilos totales que se recolectaron. Por �ltimo, se marcar� al pedido como �Completado�.

6) Imprimir Clientes: Se imprimir� una lista de clientes con todos sus datos junto con la cantidad de �pedidos de recolecci�n� que posee en estado �Pendiente�.

7) Imprimir Pedidos pendientes: Se imprimir� una lista de los pedidos que se encuentren en estado
	�Pendiente� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos a recolectar.

8) Imprimir Pedidos procesados: Se imprimir� una lista de los pedidos que se encuentren en estado �Completado�
	con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos reciclados de cada tipo de pl�stico.

9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.

10)  Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
===========================================================================*/

#include "Nexus.h"

int main(void) {
	setbuf(stdout, NULL);

	printf("\t\t#=======================================#\n"
		   "\t\t|\t   Parcial Laboratorio 1\t|\n"
		   "\t\t|\t    --Marcos Laporte--\t\t|\n"
		   "\t\t#=======================================#\n");

	sClient arrayClients[MAX_CLIENT];
	sRequest arrayRequest[MAX_REQUEST];
	sLocality arrayLocality[MAX_LOCAL] = {{1, "Barracas"}, {2, "Avellaneda"}, {3, "MicroCentro"}, {4, "Once"}, {5, "Flores"}};

	int option;
	int clientsId;
	int id;
	int r;
	int reqId;
	float averagePP;
	sClient mostPendingRequest;
	sClient mostCompletedRequest;
	clientsId = 1;
	reqId = 1;

	initClients(arrayClients, MAX_CLIENT);
	initRequests(arrayRequest, MAX_REQUEST);
	initCompletedRequests(arrayClients, MAX_CLIENT);
	hardcodeClients(arrayClients, arrayRequest, 100, &clientsId, 1000, &reqId);

	do{
		option = printMenu();
		switch(option){
		case 1: //Alta
			if(addClient(arrayClients, MAX_CLIENT, clientsId) == -1){
				printf("Ya se ha ingresado la cantidad m�xima de clientes.\n");
			}else{
				printf("El ID del cliente es %d.\n", clientsId);
				clientsId++;
			}
			break;
		case 2: //Modificaci�n
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				printClientList(arrayClients, MAX_CLIENT, arrayLocality, MAX_LOCAL);
				getFinalInt(&id, "Ingrese el ID del cliente a modificar: ", "ERROR! Ingrese un ID num�rico mayor a 0: ", 1, 99999);
				if(modifyClient(arrayClients, MAX_CLIENT, id) == -1){
					printf("ERROR! No existe un cliente con ese ID.\n");
				}else{
					printf("El cliente ha sido modificado!\n");
				}
			}
			break;
		case 3: //Baja
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				printClientList(arrayClients, MAX_CLIENT, arrayLocality, MAX_LOCAL);
				getFinalInt(&id, "Ingrese el ID del cliente a dar de baja: ", "ERROR! Ingrese un ID num�rico mayor a 0: ", 1, 99999);
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
		case 4: //Crear pedido
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				r = addRequest(arrayClients, MAX_CLIENT, arrayRequest, MAX_REQUEST, reqId, arrayLocality, MAX_LOCAL);
				if(r == -1){
					printf("ERROR! No existe un cliente con ese ID.\n");
				}else{
					if(r == 0){
						printf("Ya se ha ingresado la cantidad m�xima de pedidos.\n");
					}else{
						printf("El pedido ha sido creado! El ID del pedido es %d.\n", reqId);
						reqId++;
					}
				}
			}
			break;
		case 5: //Procesar
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(checkARequest(arrayRequest, MAX_REQUEST, PENDING) == -1){
					printf("ERROR! No hay pedidos para procesar.\n");
				}else{
					if(loadRequest(arrayClients, MAX_CLIENT, arrayRequest, MAX_REQUEST) == -1){
						printf("ERROR! No existe un pedido con ese ID.\n");
					}else{
						printf("El pedido ha sido procesado!\n");
					}
				}
			}
			break;
		case 6: //Mostrar lista
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				printClientList(arrayClients, MAX_CLIENT, arrayLocality, MAX_LOCAL);
			}
			break;
		case 7: //Pedidos pendientes
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(checkARequest(arrayRequest, MAX_REQUEST, PENDING) == -1){
					printf("ERROR! No hay pedidos pendientes.\n");
				}else{
					printPendingRequestList(arrayClients, MAX_CLIENT, arrayRequest, MAX_REQUEST);
				}
			}
			break;
		case 8: //Pedidos procesados
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(checkARequest(arrayRequest, MAX_REQUEST, COMPLETED) == -1){
					printf("ERROR! No hay pedidos procesados.\n");
				}else{
					printCompletedRequests(arrayClients, MAX_CLIENT, arrayRequest, MAX_REQUEST);
				}
			}
			break;
		case 9: //Pedidos pendientes por localidad
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(checkARequest(arrayRequest, MAX_REQUEST, PENDING) == -1){
					printf("ERROR! No hay pedidos pendientes.\n");
				}else{
					if(printLocalityRequests(arrayClients, MAX_CLIENT, arrayLocality, MAX_LOCAL) == -1){
						printf("No hay pedidos en esa localidad.\n");
					}
				}
			}
			break;
		case 10: //Promedio de PP por cliente
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(checkARequest(arrayRequest, MAX_REQUEST, COMPLETED) == -1){
					printf("ERROR! No hay pedidos procesados.\n");
				}else{
					if(countAveragePP(arrayClients, MAX_CLIENT, arrayRequest, MAX_REQUEST, &averagePP) == 0){
						printf("El promedio de polipropeno por cliente es: %.2f.\n", averagePP);
					}
				}
			}
			break;
		case 11:
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(calcMostPendingRequestsClient(arrayClients, MAX_CLIENT, arrayLocality, MAX_LOCAL, &mostPendingRequest) == -1){
					printf("ERROR! No hay pedidos pendientes.\n");
				}else{
					printMostRequestsClient(mostPendingRequest, arrayLocality, MAX_LOCAL);
				}
			}
			break;
		case 12:
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(calcMostCompletedRequestsClient(arrayClients, MAX_CLIENT, arrayLocality, MAX_LOCAL, &mostCompletedRequest) == -1){
					printf("ERROR! No hay pedidos completados.\n");
				}else{
					printMostRequestsClient(mostCompletedRequest, arrayLocality, MAX_LOCAL);
				}
			}
			break;
		case 13:
			if(checkAClient(arrayClients, MAX_CLIENT) == -1){
				printf("ERROR! No se han ingresado clientes.\n");
			}else{
				if(calcMostRequestsClient(arrayClients, MAX_CLIENT, arrayLocality, MAX_LOCAL, &mostCompletedRequest) == -1){
					printf("ERROR! No hay pedidos de ning�n tipo.\n");
				}else{
					printMostRequestsClient(mostCompletedRequest, arrayLocality, MAX_LOCAL);
				}
			}
			break;
		case 0:
			printf("Ha salido del programa.\n");
			break;
		}

	}while(option != 0);

	return 0;
}

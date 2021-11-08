/*
 * Clients.h
 *      Author: Marcos
 */

#ifndef CLIENTS_H_
#define CLIENTS_H_

#include "Input.h"

typedef struct{
	char address[51];
	int number;
	int idLocal;
}sPlace;

typedef struct{
	int id; //PK
	char companyName[MAX_CHARAC];
	char cuit[14]; //20-44567890-9
	sPlace direction;
	int pendingRequests;
	int completedRequests;
	int status;
}sClient;

//---------------------------------------------------------------------------------
/// @brief Inicializa todas las posiciones del array como vacias, declarando la bandera "status" en 0 (EMPTY).
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int initClients(sClient* list, int len);
//---------------------------------------------------------------------------------
/// @brief Llama a las distintas funciones que piden los datos del cliente.
///
/// @return sClient - Retorna un dato del tipo 'sClient' con los datos pedidos.
sClient getClient(void);
//---------------------------------------------------------------------------------
/// @brief Pide una cadena de caracteres validando que sean sólo letras y espacios, y que no esté vacío.
///
/// @param input - El array donde se va a guardar la cadena.
void getName(char input[]);
//---------------------------------------------------------------------------------
/// @brief Pide una cadena de caracteres validando que sean tan solo números y que sean 11 caracteres.
///
/// @param input - El array donde se va a guardar la cadena.
void getCuit(char input[]);
//---------------------------------------------------------------------------------
/// @brief Le da formato a la cadena pasada por parámetro; pone un guión en las posiciones 2 y 11.
///
/// @param input - El array donde se va a guardar la cadena.
void formatCuit(char input[]);
//---------------------------------------------------------------------------------
/// @brief Pide una cadena de caracteres validando que no sean más de 51 caracteres.
///
/// @param input - El array donde se va a guardar la cadena.
void getAddress(char input[]);
//---------------------------------------------------------------------------------
/// @brief Pide una cadena de caracteres validando que sean sólo letras y espacios, y que no esté vacío ni pase los 51 caracteres.
///
/// @param input - El array donde se va a guardar la cadena.
void getLocal(char input[]);
//---------------------------------------------------------------------------------
/// @brief Llama a la función 'getClient' y asigna los datos a la primer posición vacía del array pasado por parámetro.
///
/// @param list - Puntero al array de clientes.
/// @param len - Tamaño del array.
/// @param id - Valor del ID a asignar.
/// @return int - Retorna -1 si no encuentra espacio, o 0 si está todo bien.
int addClient(sClient* list, int len, int id);
//---------------------------------------------------------------------------------
/// @brief Busca la posición del array donde se encuentra el cliente con el ID pasado por parámetro.
///
/// @param list - Puntero al array de clientes.
/// @param len - Tamaño del array.
/// @param id - ID a buscar.
/// @return int - Retorna la posición del id si lo encuentra, y -1 si no.
int findClientById(sClient* list, int len, int id);
//---------------------------------------------------------------------------------
/// @brief Permite modificar el campo de dirección y localidad de un cliente por su ID.
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @param id - El ID del cliente a modificar.
/// @return int - Retorna -1 si no existe ese ID, o 0 si está todo bien.
int modifyClient(sClient* list, int len, int id);
//---------------------------------------------------------------------------------
/// @brief Declara el campo 'status' del cliente en 0 (VACIO).
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @param id - El id del cliente a remover.
/// @return int - Retorna -1 si no existe ese ID, o 0 si está todo bien.
int removeClient(sClient* list, int len, int id);
//---------------------------------------------------------------------------------
/// @brief Revisa que haya al menos un cliente cargado.
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna -1 si no encuentra ningún cliente, o 0 si sí lo hace.
int checkAClient(sClient* list, int len);
//---------------------------------------------------------------------------------
/// @brief Inicializa el campo de pedidos pendientes de todos los clientes en 0.
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int initPendingRequests(sClient* list, int len);
//---------------------------------------------------------------------------------
/// @brief Busca los datos de un cliente por su ID pasado por parámetro.
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @param id - El ID del empleado a buscar.
/// @return sClient - Retorna los datos del cliente encontrado.
sClient searchClientById(sClient* list, int len, int id);
//---------------------------------------------------------------------------------
/// @brief Inicializa el campo de pedidos procesados de todos los clientes en 0.
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int initCompletedRequests(sClient* list, int len);
//---------------------------------------------------------------------------------
/// @brief Busca el cliente con la mayor cantidad de pedidos en el estado pasado por parámetro.
///
/// @param list - Puntero al array de clientes.
/// @param len - Indica el tamaño del array.
/// @param reqStatus - Estado del pedido a buscar su mayor.
/// @param client - Puntero a guardar el cliente con más pedidos.
/// @return int - Retorna -1 si no encuentra ningún cliente que supere las condiciones, o 0 si sí.
int calcMostRequests(sClient* list, int len, int reqStatus, int* max);
//---------------------------------------------------------------------------------

#endif /* CLIENTS_H_ */

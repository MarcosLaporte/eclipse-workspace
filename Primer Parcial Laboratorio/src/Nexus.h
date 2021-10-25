/*
 * Nexus.h
 *      Author: Marcos
 */

#ifndef NEXUS_H_
#define NEXUS_H_

#include "Input.h"
#include "Clients.h"
#include "Request.h"

//---------------------------------------------------------------------------------
/// @brief Crea un pedido de recolecci�n en el primer lugar vac�o del array, pidiendo el ID
/// 	del cliente al que se le quiere asiganer el pedido, y si luego de 3 intentos el usuario
/// 	ingresa mal el ID, se cancela. Si acepta el ID, lo a asigna 'clientId'. El ID del pedido
/// 	lo toma del par�metro. Pide el total de kilos, cambia el estado e 'isEmpty' a 1.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @param requestId - Valor del ID a asignar al pedido.
/// @return int - Retorna -1 si no existe el ID ingresado, 0 si no encuentra espacio, o 1 si est� todo bien.
int addRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int requestId);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos pendientes con encabezado, llamando a la funci�n printPendingRequests()
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @return int - Retorna -1 si alg�n puntero es nulo o alg�n tama�o es inv�lido, o 0 si est� todo bien.
int printPendingRequestList(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos pendientes, validando que los IDs de ambas estructuras concuerden.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @return int - Retorna -1 si alg�n puntero es nulo o alg�n tama�o es inv�lido, o 0 si est� todo bien.
int printPendingRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Cambia el estado del pedido indicado a 1 (COMPLETED). Pide el ID del pedido, y si luego de 3
/// 	intentos no ingresa uno v�lido, la acci�n se cancela. Pide la cantidad de los 3 tipos de pl�stico
/// 	y los asigna a sus respectivos campos en la posici�n del array indicada.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @return int - Retorna -1 si no existe ese ID, o 0 si est� todo bien.
int loadRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Se encarga de sumar la cantidad de pedidos pendientes de cada cliente. Esta funci�n se llama
/// 	junto a initPendingRequests() cada vez que se ingresa o se procesa un pedido.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @param clientId - El ID del cliente a contar sus pedidos pendientes.
/// @return int - Retorna -1 si el pedido no est� cargado, pendiente y el ID de su cliente
/// 	no concuerda con el mismo pasado por par�metro.
int countRequestsByClient(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int clientId);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos procesados con encabezado, llamando a la funci�n printCompletedRequestByClientId().
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @return int - Retorna -1 si alg�n puntero es nulo o alg�n tama�o es inv�lido, o 0 si est� todo bien.
int printCompletedRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos procesados, validando que los IDs de ambas estructuras concuerden.
///
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param clientId - El Id del cliente a comparar con el de la lista de pedidos.
/// @return int - Retorna -1 si el pedido no est� cargado, procesado y el ID de su cliente
/// 	no concuerda con el mismo pasado por par�metro.
int printCompletedRequestByClientId(sRequest* requestList, int reqLen, sClient* clientsList, int cliLen, int clientId);
//---------------------------------------------------------------------------------
/// @brief Acumula los kilos de polipropileno y cuenta la cantidad de clientes asociados con estos.
/// 	Luego divide ambos para tener un promedio de polipropileno por cliente
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tama�o del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tama�o del array de pedidos.
/// @param average - Puntero a guardar el promedio.
/// @return int - Retorna -1 si no encontr� ning�n cliente con un pedido procesado, o 0 si s�.
int countAveragePP(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, float* average);
//---------------------------------------------------------------------------------
/// @brief Datos hardcodeados para probar el c�digo.
///
/// @param clientsList - Puntero al array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param maxClients - Cantidad de clientes a hardcodear.
/// @param ids - Puntero a los IDs.
/// @param maxRequests - Cantidad de pedidos a hardcodear.
/// @param reqIds - Puntero a los IDs de pedidos.
void hardcodeClients(sClient* clientsList, sRequest* requestList, int maxClients, int* ids, int maxRequests, int* reqIds);
//---------------------------------------------------------------------------------

#endif /* NEXUS_H_ */

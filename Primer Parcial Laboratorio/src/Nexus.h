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
/// @brief Crea un pedido de recolección en el primer lugar vacío del array, pidiendo el ID
/// 	del cliente al que se le quiere asiganer el pedido, y si luego de 3 intentos el usuario
/// 	ingresa mal el ID, se cancela. Si acepta el ID, lo a asigna 'clientId'. El ID del pedido
/// 	lo toma del parámetro. Pide el total de kilos, cambia el estado e 'isEmpty' a 1.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @param requestId - Valor del ID a asignar al pedido.
/// @return int - Retorna -1 si no existe el ID ingresado, 0 si no encuentra espacio, o 1 si está todo bien.
int addRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int requestId);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos pendientes con encabezado, llamando a la función printPendingRequests()
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @return int - Retorna -1 si algún puntero es nulo o algún tamaño es inválido, o 0 si está todo bien.
int printPendingRequestList(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos pendientes, validando que los IDs de ambas estructuras concuerden.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @return int - Retorna -1 si algún puntero es nulo o algún tamaño es inválido, o 0 si está todo bien.
int printPendingRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Cambia el estado del pedido indicado a 1 (COMPLETED). Pide el ID del pedido, y si luego de 3
/// 	intentos no ingresa uno válido, la acción se cancela. Pide la cantidad de los 3 tipos de plástico
/// 	y los asigna a sus respectivos campos en la posición del array indicada.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @return int - Retorna -1 si no existe ese ID, o 0 si está todo bien.
int loadRequest(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Se encarga de sumar la cantidad de pedidos pendientes de cada cliente. Esta función se llama
/// 	junto a initPendingRequests() cada vez que se ingresa o se procesa un pedido.
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @param clientId - El ID del cliente a contar sus pedidos pendientes.
/// @return int - Retorna -1 si el pedido no está cargado, pendiente y el ID de su cliente
/// 	no concuerda con el mismo pasado por parámetro.
int countRequestsByClient(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, int clientId);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos procesados con encabezado, llamando a la función printCompletedRequestByClientId().
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @return int - Retorna -1 si algún puntero es nulo o algún tamaño es inválido, o 0 si está todo bien.
int printCompletedRequests(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen);
//---------------------------------------------------------------------------------
/// @brief Imprime la lista de pedidos procesados, validando que los IDs de ambas estructuras concuerden.
///
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param clientId - El Id del cliente a comparar con el de la lista de pedidos.
/// @return int - Retorna -1 si el pedido no está cargado, procesado y el ID de su cliente
/// 	no concuerda con el mismo pasado por parámetro.
int printCompletedRequestByClientId(sRequest* requestList, int reqLen, sClient* clientsList, int cliLen, int clientId);
//---------------------------------------------------------------------------------
/// @brief Acumula los kilos de polipropileno y cuenta la cantidad de clientes asociados con estos.
/// 	Luego divide ambos para tener un promedio de polipropileno por cliente
///
/// @param clientsList - Puntero al array de clientes.
/// @param cliLen - Tamaño del array de clientes.
/// @param requestList - Puntero al array de pedidos.
/// @param reqLen - Tamaño del array de pedidos.
/// @param average - Puntero a guardar el promedio.
/// @return int - Retorna -1 si no encontró ningún cliente con un pedido procesado, o 0 si sí.
int countAveragePP(sClient* clientsList, int cliLen, sRequest* requestList, int reqLen, float* average);
//---------------------------------------------------------------------------------
/// @brief Datos hardcodeados para probar el código.
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

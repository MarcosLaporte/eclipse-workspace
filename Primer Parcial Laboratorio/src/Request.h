/*
 * Request.h
 *      Author: Marcos
 */

#ifndef REQUEST_H_
#define REQUEST_H_

#include "Input.h"

typedef struct{
	int id; //PK
		float kilosTotal;
		float kilosHDPE;
		float kilosLDPE;
		float kilosPP;
		float kilosWaste;
	int clientId; //FK
	int status;
	int isEmpty;
}sRequest;

//---------------------------------------------------------------------------------
/// @brief Inicializa todas las posiciones del array como vacias, declarando la bandera "isEmpty" en 0 (EMPTY).
///
/// @param list - Puntero al array de pedidos.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna -1 si el puntero es nulo o el tamaño es inválido, o 0 si está todo bien.
int initRequests(sRequest* list, int len);
//---------------------------------------------------------------------------------
/// @brief Revisa que haya al menos un pedido del estado indicado cargado.
///
/// @param list - Puntero al array de pedido.
/// @param len - Indica el tamaño del array.
/// @param status - Indica el estado del pedido que hay que buscar.
/// @return int - Retorna -1 si no encuentra ningún cliente, o 0 si sí lo hace.
int checkARequest(sRequest* list, int len, int status);
//---------------------------------------------------------------------------------
/// @brief Busca la posición del array donde se encuentra el pedido con el ID pasado por parámetro.
///
/// @param list - Puntero al array de pedidos.
/// @param len - Tamaño del array.
/// @param id - ID a buscar.
/// @return int - Retorna la posición del id si lo encuentra, y -1 si no.
int findRequestById(sRequest* list, int len, int id);
//---------------------------------------------------------------------------------
/// @brief Pide la cantidad de los distintos tipos de plástico, siempre que no pasen el total ingresado.
///
/// @param total - El total de kilos que no puede superar la suma de los 3 tipos.
/// @param HDPE - Puntero a donde guardar los kilos del tipo Alta Densidad.
/// @param LDPE - Puntero a donde guardar los kilos del tipo Baja Densidad.
/// @param PP - Puntero a donde guardar los kilos del tipo Polipropileno.
/// @param waste - Puntero a donde guardar los kilos del tipo desperdicio
void getPlasticTypes(float total, float* HDPE, float* LDPE, float* PP, float* waste);
//---------------------------------------------------------------------------------
/// @brief Encuentra un espacio vacío en el array del tipo 'sRequest'.
///
/// @param list - Puntero al array de pedidos.
/// @param len - Indica el tamaño del array.
/// @return int - Retorna la posición vacía si es que hay, o -1 si no hay.
int findFreeSpaceRequest(sRequest* list, int len);
//---------------------------------------------------------------------------------

#endif /* REQUEST_H_ */

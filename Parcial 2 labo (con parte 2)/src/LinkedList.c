#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size;
    }

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		auxNode = this->pFirstNode;
		for(int i = 0; i < nodeIndex; i++){
			auxNode = auxNode->pNextNode;
		}
	}
	return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* lastNode;
    Node* auxNode = (Node*)malloc(sizeof(Node));
    auxNode->pElement = pElement;
    auxNode->pNextNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
    	if(nodeIndex == 0){
    		auxNode->pNextNode = this->pFirstNode;
    		this->pFirstNode = auxNode;
    	}else{
    		lastNode = getNode(this, nodeIndex-1);
    		if(lastNode != NULL){
				auxNode->pNextNode = lastNode->pNextNode;
				lastNode->pNextNode = auxNode;
    		}
    	}
		this->size++;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if(!addNode(this, ll_len(this), pElement)){
			returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	auxNode = getNode(this, index);
    	if(auxNode != NULL){
    		returnAux = auxNode->pElement;
    	}
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	auxNode = getNode(this, index);
    	if(auxNode != NULL){
			auxNode->pElement = pElement;
			returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNode;
    Node* nodoAnterior;

    if(this != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);
		if(auxNode != NULL){
			if(index == 0){
				this->pFirstNode = auxNode->pNextNode;
			}else{
				nodoAnterior = getNode(this, index-1);
				nodoAnterior->pNextNode = auxNode->pNextNode;
			}
			free(auxNode);
			this->size--;
			returnAux = 0;
		}
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	for(int i = ll_len(this); i >= 0; i--){
    		ll_remove(this, i);
    	}
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	if(ll_clear(this) == 0){
    		free(this);
    	}
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL){
    	for(int i = 0; i < ll_len(this); i++){
    		auxNode = getNode(this, i);
    		if(auxNode != NULL && auxNode->pElement == pElement){
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = 0;
    	if(this->size == 0){
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if(!addNode(this, index, pElement)){
			returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this ,int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	auxNode = getNode(this, index);
    	if(auxNode != NULL){
			returnAux = auxNode->pElement;
			ll_remove(this, index);
    	}
    }

    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = 0;
		if(ll_indexOf(this, pElement) > -1){
			returnAux = 1;
		}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement;

    if(this != NULL && this2 != NULL){
		returnAux = 1;
    	for(int i = 0; i < ll_len(this2); i++){
    		auxElement = ll_get(this2, i);
    		if(!ll_contains(this, auxElement)){
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;
    void* auxElement;

    if(this != NULL && from >= 0 && from < to
    		&& to > from && to <= ll_len(this)){
    	cloneArray = ll_newLinkedList();
    	for(int i = from; i < to; i++){
    		auxElement = ll_get(this, i);
			ll_add(cloneArray, auxElement);
    	}
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL){
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* auxElement1;
    void* auxElement2;
    void* aux;
    int comparison;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){
		for(int i = 0; i < ll_len(this)-1; i++){
			for(int j = i+1; j < ll_len(this); j++){
				auxElement1 = ll_get(this, i);
				auxElement2 = ll_get(this, j);
				comparison = pFunc(auxElement1, auxElement2);
				if((comparison > 0 && order == 1) ||
						(comparison < 0 && order == 0)){
					aux = auxElement1;
					ll_set(this, i, auxElement2);
					ll_set(this, j, aux);
				}
			}
		}
		returnAux = 0;
    }

    return returnAux;
}

/// @brief Se deber? iterar todos los elementos de la lista y pasarlos a la funci?n ?fn?.
/// La funci?n ?fn? devolver? 1 si ese ?tem se debe agregar a la lista resultado o 0 si no debe agregarse.
/// La funci?n ?ll_filter? generar? la nueva lista resultado, agregar? a la misma los ?tems correspondientes y la devolver?.
///
/// @param this Puntero a la LL.
/// @param fn Puntero a funci?n criterio.
/// @return
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element)){
	LinkedList* result = NULL;
	void* auxElement = NULL;


	if(this != NULL){
		result = ll_newLinkedList();
		if(result != NULL){
			for(int i = 0; i < ll_len(this); i++){
				auxElement = ll_get(this, i);
				if(fn(auxElement) == 1){
					ll_add(result, auxElement);
				}
			}
		}
	}

	return result;
}

//LinkedList* ll_map(LinkedList* this, int (*fn)(void* element)){}
/** \brief La funci?n map ejecutar? la funci?n recibida como par?metro por cada item de la lista, y le pasar? en
cada llamada, uno de los items.
 *
 * \param LinkedList* lista : Puntero a la lista
 * \return int ll_map(LinkedList* lista,int : la funci?n pasada como par?metro (funci?n criterio) podr? realizar el c?lculo aleatorio de
    un puntaje (entre 1 y 10) y se lo asignar? al atributo puntajeSegundaRonda del concursante pasado como
    par?metro.
 * @return  (-1) Error: si el puntero a la listas es NULL
            (1) Error: si la funcion pasada como parametro falla
            ( 0) Si ok
 */
int ll_map(LinkedList* lista,int (*pFunc)(void*))
{
    int retorno = -1;
    if(lista != NULL && pFunc != NULL){
        if(ll_len(lista) > 0){
            int i;
            retorno = 0;
            for(i = 0; i < ll_len(lista);i++){
               if(pFunc(ll_get(lista,i)) != 0){
                   retorno = 1;
                   break;
               }
            }
        }
    }
    return retorno;
}

/** \brief Recorre los elementos de la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                               ( 0) Si ok
 */

int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
    void* pElemento;
    if(this!=NULL){
    	for (int i = 0; i < ll_len(this); i++){
    		pElemento=ll_get(this, i);
    		pFunc(pElemento);
    		returnAux=0;
    	}
    }
    return returnAux;
}

LinkedList* ll_map(LinkedList* this, int (*pFunc)(void* pElement))
{
	int i;
	if(this!=NULL && pFunc!=NULL)
	{
		for(i=0;i<ll_len(this);i++)
		{
			pFunc(ll_get(this, i));
		}
	}
	return this;
}

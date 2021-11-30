#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

//Crea un nuevo LinkedList en memoria de manera dinamica
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
//  Crea espacio en memoria para una LL
    if(this != NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
//    	Inicializa los campos de la estructura para que el tamaño sea 0
//    	y no apunta a nada (ya que no tiene nodos).
    }

    return this;
//    Retorna el puntero a la LL.
}

//Retorna la cantidad de nodos (elementos) de la lista
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = this->size;
//    	Entra al campo 'size' de la estructura LL.
    }

    return returnAux;
}

//Obtiene un nodo de la lista
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)){
		auxNode = this->pFirstNode;
//		Apunta al primer nodo
		for(int i = 0; i < nodeIndex; i++){
			auxNode = auxNode->pNextNode;
//			Si el índice es 5, el bucle va a llegar hasta el 4to nodo y
//			va a tomar el nodo al que apunta el campo 'pNextNode'
		}
	}
	return auxNode;
}

//Agrega y enlaza un nuevo nodo a la lista
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* lastNode;
    Node* auxNode = (Node*)malloc(sizeof(Node));
//    Crea espacio en memoria para un nodo nuevo.
    auxNode->pElement = pElement;
//    El elemento de este nodo va a ser el pasado por parámetro.
    auxNode->pNextNode = NULL;
//    No apunta a nada.

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)){
    	if(nodeIndex == 0){
    		auxNode->pNextNode = this->pFirstNode;
    		this->pFirstNode = auxNode;
//    		Si el índice es 0, el campo de próximo nodo del auxiliar apunta al primer nodo
//    		para luego reemplazar el primer nodo por el auxiliar.
    	}else{
    		lastNode = getNode(this, nodeIndex-1);
    		auxNode->pNextNode = lastNode->pNextNode;
    		lastNode->pNextNode = auxNode;
//    		Si el índice es distinto de 0, toma el nodo anterior al del índice, para asignar
//    		su próximo nodo al del auxiliar y luego el próximo del anterior pasa a ser el aux.
    	}
		this->size++;
    	returnAux = 0;
    }

    return returnAux;
}

//Agrega un elemento a la lista
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	addNode(this, ll_len(this), pElement);
//    	Se pasa ll_len() como índice para que lo agregue al final de la LL.
    	returnAux = 0;
    }

    return returnAux;
}

//Retorna el elemento del nodo solicitado
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	auxNode = getNode(this, index);
//    	Busca el nodo de ese índice.
    	returnAux = auxNode->pElement;
//    	Saca el dato de pElement y lo guarda en returnAux.
    }

    return returnAux;
}

//Modifica un elemento de la lista
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
    	auxNode = getNode(this, index);
//    	Busca el nodo de ese índice.
    	auxNode->pElement = pElement;
//    	Pisa el dato que hay en pElement por el pasado por parámetro.
    	returnAux = 0;
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
    Node* lastNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);
//    	Busca el nodo de ese índice.
    	if(index == 0){
    		this->pFirstNode = auxNode->pNextNode;
//    		Si es el primer nodo, a lo que apunta la LL lo cambiamos por el siguiente nodo.
    	}else{
    		lastNode = getNode(this, index-1);
//    		Si es otro, toma el anterior.
    		lastNode->pNextNode = auxNode->pNextNode;
//    		Hacemos que el nodo anterior apunte al que apunta el nodo indicado.
    	}
		free(auxNode);
//		Liberamos el espacio en memoria donde se encuentra el auxiliar.
		this->size--;
//		Reducimos el campo size en 1.
		returnAux = 0;
    }

    return returnAux;
}

//Elimina todos los elementos de la lista
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
    	for(int i = 0; i < ll_len(this); i++){
    		ll_remove(this, i);
    	}
//    	for(int i = ll_len(this); i >= 0 ; i--){
//    		ll_remove(this, i);
//    	}
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
//    		Borra todos los elementos.
    		free(this);
//    		Libera el espacio en memoria donde se encuentra la LL.
    	}
    	returnAux = 0;
    }
    return returnAux;
}

//Busca el indice de la primer ocurrencia del elemento pasado como parametro
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    void* auxElement;

    if(this != NULL){
    	for(int i = 0; i < ll_len(this); i++){
//    		auxNode = getNode(this, i);
    		auxElement = ll_get(this, i);
//	    	Busca el elemento de ese índice (cada vez que entra).
    		if(auxElement == pElement){ //DIR MEMORIA
//    			Si el elemento del nodo es el mismo que el del parámetro:
    			returnAux = i;
//    			Retorna su posición.
    			break;
    		}
    	}
    }

    return returnAux;
}

//Indica si la lista esta o no vacia
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL){
		returnAux = 0;
		if(this->size == 0){
			returnAux = 1;
//			Si la lista tiene tamaño 0, está vacía.
		}
	}

    return returnAux;
}

//Inserta un nuevo elemento en la lista en la posicion indicada
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	if(addNode(this, index, pElement) == 0){
			returnAux = 0;
//    		Agrega el elemento a la lista y si fue exitoso, retorna 0.
    	}
    }

    return returnAux;
}

//Elimina el elemento de la posicion indicada y retorna su puntero
void* ll_pop(LinkedList* this ,int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this)){
		auxNode = getNode(this, index);
//	    Busca el elemento de ese índice.
		returnAux = auxNode->pElement;
//		Guarda el elemento.
		ll_remove(this, index);
//		Borra ese nodo.
	}

    return returnAux;
}

//Determina si la lista contiene o no el elemento pasado como parametro
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL){
    	returnAux = 0;
//    	Por defecto devuelve que no lo contiene.
		if(ll_indexOf(this, pElement) > -1){
			returnAux = 1;
//			Si lo encuentra, retorna 1.
		}
    }

    return returnAux;
}


//Determina si todos los elementos de this2 estan contenidos en this
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* auxElement;

    if(this != NULL && this2 != NULL){
		returnAux = 1;
//		Por defecto retorna que existe.
    	for(int i = 0; i < ll_len(this2); i++){
    		auxElement = ll_get(this2, i);
//	    	Toma el elemento de la segunda lista.
    		if(ll_contains(this, auxElement) == 0){
    			returnAux = 0;
//    			Si algún elemento no existe en la primer lista, retorna 0.
    			break;
    		}
    	}
    }

    return returnAux;
}

//Crea y retorna una nueva lista con los elementos indicados
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;
    void* auxElement;

    if(this != NULL && from >= 0 && from < ll_len(this)
    		&& to > from && to <= ll_len(this)){
    	cloneArray = ll_newLinkedList();
//    	Crea una nueva LL.
    	for(int i = from; i < to; i++){
//    		Recorre dentro de los parámetros dados.
    		auxElement = ll_get(this, i);
//    		Busca el elemento de cada índice.
			ll_add(cloneArray, auxElement);
//			Agrega cada nodo a la nueva LL.
    	}
    }

    return cloneArray;
}

//Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL){
    	cloneArray = ll_subList(this, 0, ll_len(this));
//    	Pasa como índice de inicio 0 y como final, el final de la LL.
//    		Toda la Linked.
    }

    return cloneArray;
}

//Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
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
//				Recorro dos veces (tipo burbujeo)
				auxElement1 = ll_get(this, i);
//				Agarro el primer elemento.
				auxElement2 = ll_get(this, j);
//				Y acá el siguiente.
				comparison = pFunc(auxElement1, auxElement2);
//				Asignamos el retorno de la función criterio a la variable.
				if((comparison > 0 && order == 1) ||
						(comparison < 0 && order == 0)){
//					Validamos alguna de las dos posibilidades.
//						(element1 mayor y orden ascendente / element1 menor y orden descendente)
					aux = auxElement1;
//					Un auxiliar para que no se pierda el dato.
					ll_set(this, i, auxElement2);
//					Asignamos element2 donde estaría element1.
					ll_set(this, j, aux);
//					Asignamos el auxiliar (que tiene el valor de element1)
//					donde estaría element2.
				}
			}
		}
		returnAux = 0;
    }

    return returnAux;
}


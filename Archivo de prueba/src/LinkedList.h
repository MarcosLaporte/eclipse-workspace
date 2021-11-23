/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST

struct Node{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif


//Crea una lista nueva
LinkedList* ll_newLinkedList(void);

//Cuántos nodos conectados hay
int ll_len(LinkedList* this);

//
Node* test_getNode(LinkedList* this, int nodeIndex);

//Agrega un nodo
int test_addNode(LinkedList* this, int nodeIndex, void* pElement);

//Agrega un elemento a la lista
int ll_add(LinkedList* this, void* pElement);

//Recibe una dirección de cualquier cosa y devuelve un dato de la lista
void* ll_get(LinkedList* this, int index);

//Reemplaza un elemento por uno nuevo
int ll_set(LinkedList* this, int index, void* pElement);

//Borra un nodo
int ll_remove(LinkedList* this, int index);

//Suelta todos los nodos
int ll_clear(LinkedList* this);

//Borra toda la lista
int ll_deleteLinkedList(LinkedList* this);

//Retorna el índice del elemento en el que se encuentra
int ll_indexOf(LinkedList* this, void* pElement);

//Retorna
int ll_isEmpty(LinkedList* this);

//Crea un nodo detrás del indicado
int ll_push(LinkedList* this, int index, void* pElement);

//Saca el dato del nodo y lo devuelve
void* ll_pop(LinkedList* this, int index);

//Llama a indexOf
int ll_contains(LinkedList* this, void* pElement);

//Busca si la primer lista está en la otra
int ll_containsAll(LinkedList* this, LinkedList* this2);

//
LinkedList* ll_subList(LinkedList* this, int from, int to);

//
LinkedList* ll_clone(LinkedList* this);

/// @brief Ordena la lista LinkedList
///
/// @param this - Array LL
/// @param pFunc - Puntero a función, devuelve como strcmp(),
/// @param order - 0 para Z-A, 1 para A-Z
/// @return
int ll_sort(LinkedList* this, int (*pFunc)(void*, void*), int order);

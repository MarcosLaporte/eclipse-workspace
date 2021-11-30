/*
 * Editorial.c
 *
 *  Created on: 26 nov. 2021
 *      Author: Marcos
 */

#include "Editorial.h"

/// @brief Crea espacio en memoria para una editorial
///
/// @return Edit* Puntero a la editorial
Edit* edit_new(){
	Edit* myEdit;

	myEdit = (Edit*)calloc(1, sizeof(Edit));

	return myEdit;
}

/// @brief Llama a edit_new() y guarda los datos pasados por parámetro (ya convertidos) a la editorial del puntero
///
/// @param idStr Cadena de caracteres del Id de la editorial
/// @param descrStr Cadena de caracteres de la descripción de la editorial
/// @return Edit* Puntero al editorial
Edit* edit_newParam(char* idStr, char* descrStr){
	Edit* myEdit;

	myEdit = edit_new();
	if(idStr != NULL && descrStr != NULL){
		edit_setId(myEdit, atoi(idStr));
		edit_setName(myEdit, descrStr);
	}

	return myEdit;
}

///////////////////////////////////////////////////////

/// @brief Asigna el valor 'id' pasado por parámetro al campo idEdit en la estructura Edit
///
/// @param this Puntero a la editorial
/// @param id ID a asignar
/// @return int Retorna 0 si los punteros son nulos, sino 1
int edit_setId(Edit* this, int id){
	int returnAux = 0;

	if(this != NULL){
		this->idEdit = id;
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma el valor guardado en el campo idEdit de la estructura Edit y lo guarda en el puntero 'id' del parámetro
///
/// @param this Puntero a la editorial
/// @param id Puntero a donde guardar la cadena
/// @return int Retorna 0 si los punteros son nulos, sino 1
int edit_getId(Edit* this, int* id){
	int returnAux = 0;

	if(this != NULL){
		*id = this->idEdit;
		returnAux = 1;
	}

	return returnAux;
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////

/// @brief Asigna la cadena 'name' pasado por parámetro al campo descr en la estructura Edit
///
/// @param this Puntero a la editorial
/// @param name Descripción a asignar
/// @return int Retorna 0 si los punteros son nulos, sino 1
int edit_setName(Edit* this, char* name){
	int returnAux = 0;

	if(this != NULL && name != NULL){
		strcpy(this->descr, name);
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma la cadena guardada en el campo descr de la estructura Edit y lo guarda en el puntero 'name' del parámetro
///
/// @param this Puntero a la editorial
/// @param title Puntero a donde guardar la cadena
/// @return int Retorna 0 si los punteros son nulos, sino 1
int edit_getName(Edit* this, char* name){
	int returnAux = 0;

	if(this != NULL && name != NULL){
		strcpy(name, this->descr);
		returnAux = 1;
	}

	return returnAux;
}
///////////////////////////////////////////////////////

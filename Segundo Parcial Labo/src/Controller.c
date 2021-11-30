#include "Controller.h"

/// @brief Carga los datos de los libros del archivo.
///
/// @param path Ruta del archivo.
/// @param bookArray LinkedList donde se guardan los datos.
/// @return int Retorna 0 si los punteros son nulos, sino 1
int controller_loadFromText(char* path , LinkedList* bookArray){
	int returnAux = 0;
	FILE* pFile;

	if(path != NULL && bookArray != NULL){
		pFile = fopen(path, "r");
		if(parser_BookFromText(pFile, bookArray)){
			returnAux = 1;
		}
		fclose(pFile);
	}

    return returnAux;
}

/// @brief Carga los datos de las editoriales del archivo
///
/// @param path Ruta del archivo.
/// @param editArray LinkedList donde se guardan los datos.
/// @return int Retorna 0 si los punteros son nulos, sino 1
int controller_EditFromText(char* path, LinkedList* editArray){
	int returnAux = 0;
	FILE* pFile;

	if(path != NULL && editArray != NULL){
		pFile = fopen(path, "r");
		if(parser_EditFromText(pFile, editArray)){
			returnAux = 1;
		}
		fclose(pFile);
	}

    return returnAux;
}

/// @brief Imprime la lista de libros
///
/// @param bookArray LinkedList de libros
/// @param editArray LinkedList de editoriales
/// @return int Retorna 0 si los punteros son nulos, sino 1
int controller_ListBook(LinkedList* bookArray, LinkedList* editArray){
	int returnAux = 0;

	if(bookArray != NULL && editArray != NULL){
		printf("#=====+===============================+===============================+==========+====================#\n");
		printf("|%-5s|%-31s|%-31s|%-10s|%-20s|\n", "ID", "Título del libro", "Autor del libro", "Precio", "Editorial");
		printf("#=====+===============================+===============================+==========+====================#\n");
		for(int i = 0; i < ll_len(bookArray); i++){
			printOneBook((Book*)ll_get(bookArray, i), editArray);
		}
		printf("#=====================================================================================================#\n");
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Imprime los datos de UN libro, utilizado geters
///
/// @param this Elemento con los datos del libro
/// @param editArray LinkedList de editoriales
/// @return int Retorna 0 si los punteros son nulos, sino 1
int printOneBook(Book* this, LinkedList* editArray){
	int returnAux = 0;
	int id;
	char title[BOOK_LEN];
	char author[AUTH_LEN];
	float price;
	int idEdit;
	char edit[EDIT_LEN];

	if(this != NULL){
		book_getId(this, &id);
		book_getTitle(this, title);
		book_getAuthor(this, author);
		book_getPrice(this, &price);
		book_getIdEdit(this, &idEdit);
		controller_findEditName(editArray, idEdit, edit);

		printf("|%5d|%31s|%31s|%10.2f|%20s|\n", id, title, author, price, edit);
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma la descripción de la editorial validando el id pasado por parámetro
///
/// @param editArray LinkedList de editoriales
/// @param id El ID de la editorial a buscar
/// @param name Puntero donde se guarda la descripción de la editorial
/// @return int Retorna 0 si los punteros son nulos, sino 1
int controller_findEditName(LinkedList* editArray, int id, char* name){
	int returnAux = 0;
	int auxId;
	Edit* this;

	if(editArray != NULL && ll_len(editArray) > 0){
		for(int i = 0; i < ll_len(editArray); i++){
			this = ll_get(editArray, i);
			//Toma todos los nodos, uno por uno
			edit_getId(this, &auxId);
			//Toma el id guardado en ese nodo
			if(auxId == id){
				edit_getName(this, name);
				//Cuando concuerde con alguno de los 6  (ya que recorre los 6)
					//Toma la decripción de este.
				returnAux = 1;
				break;
			}
		}
	}

	return returnAux;
}

/// @brief Ordena la lista de libros por el criterio pasado por parámetro
///
/// @param bookArray LinkedList de libros
/// @param sortType Por qué dato se va a ordenar la lista (1-ID / 2-Título / 3-Autor / 4-Precio)
/// @param order Orden en el qiue se va a ordenar (1-Ascendente / 0-Descendente)
/// @return int Retorna 0 si los punteros son nulos o el orden o criterio son inválidos, sino 1
int controller_sortBook(LinkedList* bookArray, int sortType, int order)
{
	int returnAux = 0;

	if(bookArray != NULL && sortType > 0 && sortType < 4 && (order == 0 || order == 1)){
		switch(sortType){
		case ID:
			if(!ll_sort(bookArray, book_compareId, order)){
				returnAux = 1;
			}
			break;
		case TITLE:
			if(!ll_sort(bookArray, book_compareTitle, order)){
				returnAux = 1;
			}
			break;
		case AUTHOR:
			if(!ll_sort(bookArray, book_compareAuthor, order)){
				returnAux = 1;
			}
			break;
		case PRICE:
			if(!ll_sort(bookArray, book_comparePrice, order)){
				returnAux = 1;
			}
			break;
		}
	}

    return returnAux;
}

int controller_mapBook(char* path, LinkedList* bookArray){
	int returnAux = 0;
	FILE* pFile;

	if(path != NULL && bookArray != NULL){
		pFile = fopen(path, "w");
			ll_map(bookArray, book_discountByEdit);
			parser_TextFromBook(pFile, bookArray);
		fclose(pFile);
		returnAux = 1;
	}

	return returnAux;
}

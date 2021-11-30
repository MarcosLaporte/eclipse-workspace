#include "parser.h"

/// @brief Parsea los datos de libro desde el csv a la Linked
///
/// @param pFile Puntero al archivo
/// @param bookArray LinkedList de libros
/// @return int Retorna 0 si los punteros son nulos, sino 1
int parser_BookFromText(FILE* pFile, LinkedList* bookArray){
	int returnAux = 0;
	Book* aux;
	char idBook[ID_LEN];
	char title[BOOK_LEN];
	char author[AUTH_LEN];
	char price[PRICE_LEN];
	char idEdit[ID_LEN];

	if(pFile != NULL && bookArray != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idBook, title, author, price, idEdit);
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idBook, title, author, price, idEdit) == 5){
				if(isAnInt(idBook, ID_LEN) && isAlphaSpace(title) && isAlphaSpace(author)
						&& isAFloat(price, PRICE_LEN) && isAnInt(idEdit, ID_LEN)){
					aux = book_newParam(idBook, title, author, price, idEdit);
					ll_add(bookArray, aux);
				}
			}
		}
		returnAux = 1;
	}

	return returnAux;
}

int parser_TextFromBook(FILE* pFile, LinkedList* bookArray){
	int returnAux = 0;
	Book* aux;
	int id;
	char title[BOOK_LEN];
	char author[AUTH_LEN];
	float price;
	int idEdit;

	if(pFile != NULL && bookArray != NULL){
		fprintf(pFile, "Id,Titulo,Autor,PrecioDesc,IdEdit\n");
		for(int i = 0; i < ll_len(bookArray); i++){
			aux = (Book*)ll_get(bookArray, i);
			book_getId(aux, &id);
			book_getTitle(aux, title);
			book_getAuthor(aux, author);
			book_getPrice(aux, &price);
			book_getIdEdit(aux, &idEdit);
			fprintf(pFile, "%d,%s,%s,%.2f,%d\n", id, title, author, price, idEdit);
		}
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Parsea los datos de editoriales desde el csv a la Linked
///
/// @param pFile Puntero al archivo
/// @param editArray LinkedList de editoriales
/// @return int Retorna 0 si los punteros son nulos, sino 1
int parser_EditFromText(FILE* pFile, LinkedList* editArray){
	int returnAux = 0;
	Edit* aux;
	char id[ID_LEN];
	char descr[EDIT_LEN];

	if(pFile != NULL && editArray != NULL){
		fscanf(pFile, "%[^,],%[^\n]\n", id, descr);
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^\n]\n", id, descr) == 2){
				if(isAnInt(id, ID_LEN) && isAlphaSpace(descr)){
					aux = edit_newParam(id, descr);
					if(!ll_add(editArray, aux)){
						returnAux = 1;
					}
				}
			}
		}
	}

	return returnAux;
}

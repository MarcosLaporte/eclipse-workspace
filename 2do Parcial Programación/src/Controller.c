#include "Controller.h"

//int controller_loadFromText(char* path, Weather* pWeather){
//	int returnAux = 0;
//	FILE* pFile;
//
//	if(path != NULL && pWeather != NULL){
//		pFile = fopen(path, "r");
//		if(parser_BookFromText(pFile, pWeather)){
//			returnAux = 1;
//		}
//		fclose(pFile);
//	}
//
//    return returnAux;
//}

int controller_loadFromBinary(char* path, Weather* pWeather)
{
	int returnAux = 0;
	FILE* pFile;

	if(path != NULL && pWeather != NULL){
		pFile = fopen(path, "rb");
		if(parser_WeatherFromBinary(pFile, pWeather)){
			returnAux = 1;
		}
		fclose(pFile);
	}

    return returnAux;
}

int controller_loadToBinary(char* path, Weather* pWeather){
	int returnAux = 0;
	FILE* pFile;

	if(path != NULL && pWeather != NULL){
		pFile = fopen(path, "wb");
		if(parser_BinaryFromWeather(pFile, pWeather)){
			returnAux = 1;
		}
		fclose(pFile);
	}

	return returnAux;
}

int controller_ListWeather(Weather* today){
	int returnAux = 0;

	if(today != NULL){
		printf("#=====+===============================+===============================+==========+====================#\n");
		printf("|%-5s|%-25s|%-11s|\n", "ID", "Clima", "Temperatura");
		printf("#=====+===============================+===============================+==========+====================#\n");
		printf("|%5d|%25s|%11.2f|", today->id, today->forecast, today->temp);
		printf("#=====================================================================================================#\n");
		returnAux = 1;
	}

	return returnAux;
}

/*
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
}*/

/*
 * Books.c
 *
 *  Created on: 26 nov. 2021
 *      Author: Marcos
 */

#include "Books.h"

/// @brief Crea espacio en memoria para un libro
///
/// @return Book* Puntero al libro
Book* book_new(){
	Book* myBook;

	myBook = (Book*)calloc(1, sizeof(Book));

	return myBook;
}

/// @brief Llama a book_new() y guarda los datos pasados por parámetro (ya convertidos) al libro del puntero
///
/// @param idStr Cadena de caracteres del Id del libro
/// @param titleStr Cadena de caracteres del título del libro
/// @param authorStr Cadena de caracteres del autor del libro
/// @param priceStr Cadena de caracteres del precio del libro
/// @param editStr Cadena de caracteres del id de la editorial del libro
/// @return Book* Puntero al libro
Book* book_newParam(char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editStr){
	Book* myBook;

	myBook = book_new();
	if(idStr != NULL && titleStr != NULL && authorStr != NULL
			&& priceStr != NULL && editStr != NULL){
		book_setId(myBook, atoi(idStr));
		camelStr(titleStr);
		book_setTitle(myBook, titleStr);
		camelStr(authorStr);
		book_setAuthor(myBook, authorStr);
		book_setPrice(myBook, atof(priceStr));
		book_setIdEdit(myBook, atoi(editStr));
	}

	return myBook;
}

///////////////////////////////////////////////////////

/// @brief Asigna el valor 'id' pasado por parámetro al campo id en la estructura Book
///
/// @param this Puntero al libro
/// @param id ID a asignar
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_setId(Book* this, int id){
	int returnAux = 0;

	if(this != NULL){
		this->id = id;
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma el valor guardado en el campo id de la estructura Book y lo guarda en el puntero 'id' del parámetro
///
/// @param this Puntero al libro
/// @param id Puntero a donde guardar el valor
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_getId(Book* this, int* id){
	int returnAux = 0;

	if(this != NULL && id != NULL){
		*id = this->id;
		returnAux = 1;
	}

	return returnAux;
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////

/// @brief Asigna la cadena 'title' pasado por parámetro al campo title en la estructura Book
///
/// @param this Puntero al libro
/// @param title Título a asignar
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_setTitle(Book* this, char* title){
	int returnAux = 0;

	if(this != NULL && title != NULL){
		strcpy(this->title, title);
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma la cadena guardada en el campo title de la estructura Book y lo guarda en el puntero 'title' del parámetro
///
/// @param this Puntero al libro
/// @param title Puntero a donde guardar la cadena
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_getTitle(Book* this, char* title){
	int returnAux = 0;

	if(this != NULL && title != NULL){
		strcpy(title, this->title);
		returnAux = 1;
	}

	return returnAux;
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////

/// @brief Asigna la cadena 'author' pasado por parámetro al campo author en la estructura Book
///
/// @param this Puntero al libro
/// @param author Autor a asignar
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_setAuthor(Book* this, char* author){
	int returnAux = 0;

	if(this != NULL && author != NULL){
		strcpy(this->author, author);
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma la cadena guardada en el campo author de la estructura Book y lo guarda en el puntero 'author' del parámetro
///
/// @param this Puntero al libro
/// @param author Puntero a donde guardar la cadena
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_getAuthor(Book* this, char* author){
	int returnAux = 0;

	if(this != NULL && author != NULL){
		strcpy(author, this->author);
		returnAux = 1;
	}

	return returnAux;
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////

/// @brief Asigna el valor 'price' pasado por parámetro al campo price en la estructura Book
///
/// @param this Puntero al libro
/// @param price Precio a asignar
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_setPrice(Book* this, float price){
	int returnAux = 0;

	if(this != NULL){
		this->price = price;
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma el valor guardado en el campo precio de la estructura Book y lo guarda en el puntero 'precio' del parámetro
///
/// @param this Puntero al libro
/// @param price Puntero a donde guardar el valor
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_getPrice(Book* this, float* price){
	int returnAux = 0;

	if(this != NULL && price != NULL){
		*price = this->price;
		returnAux = 1;
	}

	return returnAux;
}
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////

/// @brief Asigna el valor 'idEdit' pasado por parámetro al campo idEdit en la estructura Book
///
/// @param this Puntero al libro
/// @param idEdit ID de editor a asignar
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_setIdEdit(Book* this, int id){
	int returnAux = 0;

	if(this != NULL){
		this->idEdit = id;
		returnAux = 1;
	}

	return returnAux;
}

/// @brief Toma el valor guardado en el campo idEdit de la estructura Book y lo guarda en el puntero 'id' del parámetro
///
/// @param this Puntero al libro
/// @param idEdit Puntero a donde guardar el valor
/// @return int Retorna 0 si los punteros son nulos, sino 1
int book_getIdEdit(Book* this, int* id){
	int returnAux = 0;

	if(this != NULL && id != NULL){
		*id = this->idEdit;
		returnAux = 1;
	}

	return returnAux;
}
///////////////////////////////////////////////////////

/// @brief Compara los ids obtenidos con el geter
///
/// @param this Puntero a void donde se pasa el Libro
/// @param that Puntero a void donde se pasa el Libro
/// @return int Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es
int book_compareId(void* this, void* that){
	int returnAux = 0;
	Book* book1;
	Book* book2;
	int id1;
	int id2;

	if(this != NULL && that != NULL){
		book1 = (Book*)this;
		book2 = (Book*)that;

		book_getId(book1, &id1);
		book_getId(book2, &id2);

		if(id1 > id2){
			returnAux = 1;
		}else{
			if(id1 < id2){
				returnAux = -1;
			}
		}
	}

	return returnAux;
}

/// @brief Compara los títulos obtenidos con el geter
///
/// @param this Puntero a void donde se pasa el Libro
/// @param that Puntero a void donde se pasa el Libro
/// @return int Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es
int book_compareTitle(void* this, void* that){
	int returnAux = 0;
	Book* book1;
	Book* book2;
	char name1[BOOK_LEN];
	char name2[BOOK_LEN];

	if(this != NULL && that != NULL){
		book1 = (Book*)this;
		book2 = (Book*)that;

		book_getTitle(book1, name1);
		book_getTitle(book2, name2);

		returnAux = strcmpi(name1, name2);
	}

	return returnAux;
}

/// @brief Compara los autores obtenidos con el geter
///
/// @param this Puntero a void donde se pasa el Libro
/// @param that Puntero a void donde se pasa el Libro
/// @return int Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es
int book_compareAuthor(void* this, void* that){
	int returnAux = 0;
	Book* book1;
	Book* book2;
	char name1[BOOK_LEN];
	char name2[BOOK_LEN];

	if(this != NULL && that != NULL){
		book1 = (Book*)this;
		book2 = (Book*)that;

		book_getAuthor(book1, name1);
		book_getAuthor(book2, name2);

		returnAux = strcmpi(name1, name2);
	}

	return returnAux;
}

/// @brief Compara los precios obtenidos con el geter
///
/// @param this Puntero a void donde se pasa el Libro
/// @param that Puntero a void donde se pasa el Libro
/// @return int Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es
int book_comparePrice(void* this, void* that){
	int returnAux = 0;
	Book* book1;
	Book* book2;
	float price1;
	float price2;

	if(this != NULL && that != NULL){
		book1 = (Book*)this;
		book2 = (Book*)that;

		book_getPrice(book1, &price1);
		book_getPrice(book2, &price2);

		if(price1 > price2){
			returnAux = 1;
		}else{
			if(price1 < price2){
				returnAux = -1;
			}
		}
	}

	return returnAux;
}

/// @brief Compara los ids de editoriales obtenidos con el geter
///
/// @param this Puntero a void donde se pasa el Libro
/// @param that Puntero a void donde se pasa el Libro
/// @return int Retorna 0 si los elementos comparados son iguales, 1 si el primero es mayor, y -1 si el segundo lo es
int book_compareIdEdit(void* this, void* that){
	int returnAux = 0;
	Book* book1;
	Book* book2;
	int id1;
	int id2;

	if(this != NULL && that != NULL){
		book1 = (Book*)this;
		book2 = (Book*)that;

		book_getIdEdit(book1, &id1);
		book_getIdEdit(book2, &id2);

		if(id1 > id2){
			returnAux = 1;
		}else{
			if(id1 < id2){
				returnAux = -1;
			}
		}
	}

	return returnAux;
}


/// @brief Compara el id de editorial del libro de parámetro para ver si es 4 (Minotauro)
///
/// @param pElement Puntero a void donde se pasa el libro
/// @return int Retorna 1 si el elemento es el mismo, o 0 si no
int book_filterByEdit(void* pElement){
	int returnAux = 0;
	Book* auxBook = (Book*) pElement;
	int id;

	if(pElement != NULL){
		book_getIdEdit(auxBook, &id);
		if(id == 4){
			returnAux = 1;
		}
	}

	return returnAux;
}

int book_discountByEdit(void* pElement){
	int returnAux = 0;
	Book* auxBook = (Book*) pElement;
	float price;
	int id;

	if(pElement != NULL){
		book_getIdEdit(auxBook, &id);
		if(id == 1){
			book_getPrice(auxBook, &price);
			if(price >= 300){
				book_setPrice(auxBook, (price - (price * 0.2)));
				returnAux = 1;
			}
		}else{
			if(id == 2){
				book_getPrice(auxBook, &price);
				if(price <= 200){
					book_setPrice(auxBook, (price - (price * 0.1)));
					returnAux = 1;
				}
			}
		}
	}

	return returnAux;
}

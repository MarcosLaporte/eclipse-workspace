/*
 * Books.h
 *
 *  Created on: 26 nov. 2021
 *      Author: Marcos
 */

#ifndef BOOKS_H_
#define BOOKS_H_
#include "Input.h"

typedef struct{
	int id;
	char title[BOOK_LEN];
	char author[AUTH_LEN];
	float price;
	int idEdit;
}Book;

Book* book_new();
Book* book_newParam(char* idStr, char* titleStr, char* authorStr, char* priceStr, char* editStr);

int book_setId(Book* this, int id);
int book_getId(Book* this, int* id);

int book_setTitle(Book* this, char* title);
int book_getTitle(Book* this, char* title);

int book_setAuthor(Book* this, char* author);
int book_getAuthor(Book* this, char* author);

int book_setPrice(Book* this, float price);
int book_getPrice(Book* this, float* price);

int book_setIdEdit(Book* this, int id);
int book_getIdEdit(Book* this, int* id);

int book_compareId(void* this, void* that);
int book_compareTitle(void* this, void* that);
int book_compareAuthor(void* this, void* that);
int book_comparePrice(void* this, void* that);
int book_compareIdEdit(void* this, void* that);

int book_filterByEdit(void* pElement);
int book_discountByEdit(void* pElement);

#endif /* BOOKS_H_ */

#ifndef PARSER_H_
#define PARSER_H_

#include "Input.h"
#include "LinkedList.h"
#include "Books.h"
#include "Editorial.h"

int parser_BookFromText(FILE* pFile , LinkedList* bookArray);
int parser_TextFromBook(FILE* pFile, LinkedList* bookArray);
int parser_EditFromText(FILE* pFile, LinkedList* editArray);

//int parser_TextFromBook(FILE* pFile, LinkedList* bookArray);
#endif /* PARSER_H_ */

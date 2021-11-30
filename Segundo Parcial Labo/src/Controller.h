#include "LinkedList.h"
#include "parser.h"
#include "Input.h"
#include "Books.h"
#include "Editorial.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_EditFromText(char* path, LinkedList* editArray);
int controller_ListBook(LinkedList* bookArray, LinkedList* editArray);
int printOneBook(Book* this, LinkedList* editArray);
int controller_findEditName(LinkedList* editArray, int id, char* name);
int controller_sortBook(LinkedList* bookArray, int sortType, int order);
int controller_mapBook(char* path, LinkedList* bookArray);

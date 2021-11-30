/*
 ============================================================================
 Name        : Segundo Parcial Laboratorio 1.c
 Author      : Marcos Laporte
 ============================================================================
 */

/*===========================================================================
1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades
eLibro.
2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades
eEditorial.
3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de
ordenamiento �Autor� de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACI�N: Se deber� imprimir la descripci�n de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber� utilizar la
funci�n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
===========================================================================*/
#include "Controller.h"
#define F_BOOK "Libros.csv"
#define F_EDIT "Editoriales.csv"
#define F_MAP "mapeado.csv"

int main(void) {
	setbuf(stdout, NULL);

	printf("\t\t#=======================================#\n"
		   "\t\t|\t   Parcial Laboratorio 2\t|\n"
		   "\t\t|\t    --Marcos Laporte--\t\t|\n"
		   "\t\t#=======================================#\n");

	LinkedList* bookArray = ll_newLinkedList();
	LinkedList* editArray = ll_newLinkedList();
	LinkedList* filteredArray = ll_newLinkedList();
	int option;
	int flagBooks = 0;
	int flagEdit = 0;
	int sortOption;
	int order;

	do{
		option = printMenu();
		switch(option){
		case 1:
			if(!flagBooks){
				if(controller_loadFromText(F_BOOK, bookArray)){
					printf("Los libros se han cargado con �xito!\n");
					flagBooks = 1;
				}
			}else{
				printf("ERROR! Ya se ha cargado la lista.\n");
			}
			break;
		case 2:
			if(!flagEdit){
				if(controller_EditFromText(F_EDIT, editArray)){
					printf("Las editoriales se han cargado con �xito!\n");
					flagEdit = 1;
				}
			}else{
				printf("ERROR! Ya se ha cargado la lista.\n");
			}
			break;
		case 3:
			if(!ll_len(bookArray) || !ll_len(editArray)){
				printf("ERROR! No se han cargado las listas.\n");
			}else{
				getInt(&sortOption, "\n1. ID\n2. T�tulo\n3. Autor\n4. Precio\n0. Cancelar\nElija un orden: ",
						"ERROR! Elija una opci�n existente: ", 0, 4);
				if(!sortOption){
					printf("Se ha cancelado la opci�n.\n");
				}else{
					getInt(&order, "Desea ordenar de forma Ascendente (1) o Descendente (0)?: ", "ERROR! Ingrese una opci�n v�lida: ", 0, 1);
					if(!controller_sortBook(bookArray, sortOption, order)){
						printf("ERROR! Hubo un problema con la lista.\n");
					}else{
						printf("La lista se ha ordenado con �xito!\n");
					}
				}
			}
			break;
		case 4:
			if(!ll_len(bookArray) || !ll_len(editArray)){
				printf("ERROR! No se han cargado las listas.\n");
			}else{
				if(!controller_ListBook(bookArray, editArray)){
					printf("ERROR! Hubo un problema con las listas.\n");
				}
			}
			break;
		case 5:
			if(!ll_len(bookArray) || !ll_len(editArray)){
				printf("ERROR! No se han cargado las listas.\n");
			}else{
				filteredArray = ll_filter(bookArray, book_filterByEdit);
				if(!controller_ListBook(filteredArray, editArray)){
					printf("ERROR! Hubo un problema con las listas.\n");
				}
			}
			break;
		case 6:
			if(!ll_len(bookArray) || !ll_len(editArray)){
				printf("ERROR! No se han cargado las listas.\n");
			}else{
				if(!controller_mapBook(F_MAP, bookArray)){
					printf("ERROR! Hubo un problema con las listas.\n");
				}else{
					printf("Los libros se han mapeado con �xito!\n");
				}
			}
			break;
		case 0:
			printf("Ha salido del programa.\n");
			break;
		}
	}while(option != 0);


	return EXIT_SUCCESS;
}

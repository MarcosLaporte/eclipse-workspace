/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
 1-Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer carácter recibido,
por el segundo. Retornando la cantidad de reemplazos o -1 en caso de error.
Versión 2. Utilizar aritmetica de punteros
============================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int characterChange(char* name, char charToChange, char charToPut);

int main(void) {
	setbuf(stdout, NULL);

	char name[40] = "Sarapnatasa";
	char firstChar = 'a';
	char secondChar = 'X';
	int changes;

	changes = characterChange(name, firstChar, secondChar);

	printf("Cadena: %s\nCambios: %d\n", name, changes);

	return EXIT_SUCCESS;
}

int characterChange(char* name, char charToChange, char charToPut){
	int Return;
	Return = -1;

	if(name != NULL){
		Return = 0;
		for(int i = 0; i < strlen(name); i++){
			if(*(name+i) == charToChange){
				*(name+i) = charToPut;
				Return++;
			}
		}
	}

	return Return;
}

#include "Ingreso_de_datos.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

void PedirCadena(char mensaje[], char input[]){
	printf("%s", mensaje);
	fflush(stdin);
	gets(input);
}

void MostrarCadena(char mensaje[]){
	printf("%s\n", mensaje);
}

int MostrarNombreCompleto(char nombre[], char apellido[], char nombreCompleto[]){
	int retorno = 0;

	if(nombre != NULL && apellido != NULL){
		strcpy(nombreCompleto, apellido);
		strcat(nombreCompleto, ", ");
		strcat(nombreCompleto, nombre);

		ModificarNombreCompleto(nombreCompleto);

		retorno = 1;
	}
	printf("\nEl nombre completo es: %s", nombreCompleto);

	return retorno;
}

int ModificarNombreCompleto(char cadena[]){
	int retorno = 0;
	int i;
	int tam;
	tam = strlen(cadena);

	if(cadena != NULL){
		strlwr(cadena);
		for(i = 0; i < tam; i++){
			if(i == 0 || isspace(cadena[i-1])){
				cadena[i] = toupper(cadena[i]);
			}
		}
		retorno = 1;
	}

	return retorno;
}

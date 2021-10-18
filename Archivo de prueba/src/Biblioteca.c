#include "Input.h"
#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//Enteros
int SumarEnteros(int num1, int num2){
	int suma;

	suma = num1 + num2;

	return suma;
}

int RestarEnteros(int num1, int num2){
	int resta;

	resta = num1 - num2;

	return resta;
}

float DividirEnteros(int num1, int num2, float* refCociente){
	float divide;
	divide = 1;

	if(num2 == 0){
		divide = 0;
	}

	*refCociente = (float)num1 / num2;

	return divide;
}

int MultiplicarEnteros(int num1, int num2){
	int multiplicacion;

	multiplicacion = num1 * num2;

	return multiplicacion;
}

// Flotantes
float SumarFlotantes(float num1, float num2){
	float suma;

	suma = num1 + num2;

	return suma;
}

float RestarFlotantes(float num1, float num2){
	float resta;

	resta = num1 - num2;

	return resta;
}

float DividirFlotantes(float num1, float num2, float* refCociente){
	float divide;
	divide = 1;

	if(num2 == 0){
		divide = 0;
	}

	*refCociente = num1 / num2;

	return divide;
}

float MultiplicarFlotantes(float num1, float num2){
	float multiplicacion;

	multiplicacion = num1 * num2;

	return multiplicacion;
}

//------------------------------------

//float CalcularFactorial(float num){
/*	float factorial = 1;
	int i;

	if(num > 0){
		if(num - (int)num == 0){
			for(i = num; i > 1; i--){
				factorial = factorial * i;
			}
		}
	}else{
		if(num < 0){
			factorial = -1;
		}
	}
*/

int CalcularFactorial(float num, float* refFactorial){
	int retornoFactorial = 0;
	int i;
	*refFactorial = 1;

	if(num > 0){
		if(num - (int)num == 0){
			for(i = num; i > 1; i--){
				retornoFactorial = 1;
				*refFactorial = *refFactorial * i;
			}
		}else{
			retornoFactorial = 2;
			if(num == 0.5){
				retornoFactorial = 3;
				*refFactorial = (1/2)*sqrt(M_PI);
			}else{
				if(num == 1.5){
					retornoFactorial = 4;
					*refFactorial = (3/4)*sqrt(M_PI);
				}else{
					if(num == 2.5){
						retornoFactorial = 5;
						*refFactorial = (15/8)*sqrt(M_PI);
					}
				}
			}
		}
	}else{
		if(num < 0){
			retornoFactorial = -1;
			if(num == -0.5){
				retornoFactorial = -2;
				*refFactorial = sqrt(M_PI);
			}
		}
	}

	return retornoFactorial;
}
/* --------------------------MAL-----------------------------
int CalcularFactorial(float num, float* refFactorial){
	int retornoFact;
	retornoFact = 0; //Si ingresa 0

	if(num == 0){
		*refFactorial = 1;
	}else{
		if(num > 0){
			retornoFact = 1; //Si es positivo
			*refFactorial = num * CalcularFactorial(num - 1, refFactorial); //
			if(num-(int)num != 0){ // Si el positivo tiene decimal...
				if(num == 0.5){
					retornoFact = 3;
					*refFactorial = 1/2 * sqrt(M_PI);
				}else{
					if(num == 1.5){
						retornoFact = 4;
						*refFactorial = 3/4 * sqrt(M_PI);
					}else{
						if(num == 2.5){
							retornoFact = 5;
							*refFactorial = 15/8 * sqrt(M_PI);
						}else{
							retornoFact = 2;
						}
					}
				}
			}
			if(num > 12){
				retornoFact = 6; //
			}
		}else{
			retornoFact = -1; //Si ingresa negativo
			if(num == -0.5){
				retornoFact = -2;
				*refFactorial = sqrt(M_PI);
			}
		}
	}
	return retornoFact;
}

void ResultadoPrimerFactorial(float num, int respFactorial, float factorial){
	switch(respFactorial){
	case -1:
		printf("e) No existe el factorial de un número negativo (%f).\n", num);
		break;
	case 2:
		printf("e) No se pudo calcular el factorial del número ya que lleva decimales (%f).\n", num);
		break;
	case 6:
		printf("e) No se pudo calcular el factorial del número ya que es mayor a 12 (%f).\n", num);
		break;
	default: // -2, 0, 1, 3, 4, 5
		printf("El factorial de %f es: %f\n", num, factorial);
	}
}
---------------------------------------------------------*/
int OrdenarArrayEnteros(int* listaValores, int tam){
	int flagSwap;
	int i;
	int cont;
	int retorno;
	int aux;
	int nuevoLimite;
	cont = 0;
	retorno = -1;

	if(listaValores != NULL && tam >= 0){
		nuevoLimite = tam - 1;
		do{
			flagSwap = 0;
			for(i = 0; i < nuevoLimite; i++){
				if(listaValores[i]<listaValores[i+1]){
					flagSwap = 1;
					aux = listaValores[i];
					listaValores[i] = listaValores[i+1];
					listaValores[i+1] = aux;
				}
				cont++;
			}
		}while(flagSwap);
		retorno = cont;
	}

	return retorno;
}

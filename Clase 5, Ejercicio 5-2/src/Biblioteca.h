/*
 * Biblioteca.h
 *
 *  Created on: 5 sep. 2021
 *      Author: Marcos
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#define T 10

void PedirArrayEnteroSec(int lista[], int tam, char mensaje[], char mensajeError[], int min, int max);
void ContadorPosYNeg(int lista[], int tam);
int DeterminarPositividad(int numero);
int SumarPares(int lista[], int tam, int* refPares);
int DeterminarParidad(int numero);
int MayorImpares(int lista[], int tam, int* refImpar);
void MostrarArrayEntero(char mensaje[], int numero[], int tam);
void MostrarPares(char mensaje[], int numero[], int tam);
void MostrarNumerosPosicionesImpares(int lista[], int tam);

#endif /* BIBLIOTECA_H_ */

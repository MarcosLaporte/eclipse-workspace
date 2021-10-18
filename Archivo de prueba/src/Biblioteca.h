/*
 * Biblioteca.h
 *
 *  Created on: 15 sep. 2021
 *      Author: Marcos
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_


int SumarEnteros(int num1, int num2);
int RestarEnteros(int num1, int num2);
float DividirEnteros(int num1, int num2, float* refCociente);
int MultiplicarEnteros(int num1, int num2);
//-----------------------------------------//
float SumarFlotantes(float num1, float num2);
float RestarFlotantes(float num1, float num2);
float DividirFlotantes(float num1, float num2, float* refCociente);
float MultiplicarFlotantes(float num1, float num2);

int CalcularFactorial(float num, float* refFactorial);
//void ResultadoPrimerFactorial(float num, int respFactorial, float factorial);
int OrdenarArrayEnteros(int* listaValores, int tam);

#endif /* BIBLIOTECA_H_ */

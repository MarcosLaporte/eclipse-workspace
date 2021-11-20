/*
 * Input.h
 *      Author: Marcos Laporte
 */

#ifndef INPUT_H_
#define INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//-----------------
#define EMPTY 0
#define FULL 1
//-----------------

int myGets(char input[], int length);
int isAnInt(char input[], int length);
int getAnInt(int* refResult);
int getInt(int* refResult, char message[], char errorMessage[], int min, int max);
int isAFloat(char input[], int length);
int getAFloat(float* refResult);
int getFloat(float* refResult, char message[], char errorMessage[], int min, int max);
void getRandomArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max);
void getRandomArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max);
void camelStr(char input[]);
int isAlphaSpace(char input[]);
int getConfirmation(char message[], char* confirmation, char* cancel, int length, int tries);
int myGetName(char* input, char* message, char* errorMessage, int len);
int printMenu();

#endif /* INPUT_H_ */

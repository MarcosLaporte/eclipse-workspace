/*
 * Input.h
 *      Author: Marcos
 */

#ifndef INPUT_H_
#define INPUT_H_

/// @brief Pide un entero con un mensaje pasado por parámetro.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el entero.
/// @return int - El entero pedido por scanf.
int getInt(char message[]);

/// @brief Pide un entero y lo valida entre un mínimo y un máximo.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el entero.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los parámetros dados.
/// @param min - El mínimo que puede ser el entero.
/// @param max - El máximo que puede ser el entero.
/// @return int - El entero pedido por scanf.
int getLimitedInt(char message[], char errorMessage[], int min, int max);

/// @brief Pide un flotante con un mensaje pasado por parámetro.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el flotante.
/// @return float - El flotante pedido por scanf.
float getFloat(char message[]);

/// @brief Pide un flotante y lo valida entre un mínimo y un máximo.
///
/// @param message - El mensaje a mostrar en pantalla al momento de pedir el flotante.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los parámetros dados.
/// @param min - El mínimo que puede ser el entero.
/// @param max - El máximo que puede ser el entero.
/// @return float - El flotante pedido por scanf.
float getLimitedFloat(char message[], char errorMessage[], int min, int max);

/// @brief Pide un array de enteros de manera secuencial.
///
/// @param list - El array donde se van a guardar los enteros.
/// @param length - El tamaño del array.
/// @param message - El mensaje a mostrar al momento de pedir los enteros.
/// @param errorMessage - El mensaje a mostrar si el entero ingresado no entra en los parámetros dados.
/// @param min - El mínimo que puede ser el entero.
/// @param max - El máximo que puede ser el entero.
void getSequentialArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Pide un array de enteros de manera aleatoria.
///
/// @param list - El array donde se van a guardar los enteros.
/// @param length - El tamaño del array.
/// @param message - El mensaje a mostrar al momento de pedir los enteros.
/// @param errorMessage - El mensaje a mostrar en pantalla si el entero ingresado no entra en los parámetros dados.
/// @param min - El mínimo que puede ser el entero.
/// @param max - El máximo que puede ser el entero.
void getRandomArrayInt(int list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Muestra en pantalla el array de enteros pasado por parámetro.
///
/// @param message - El mensaje a mostrar antes que el array.
/// @param number - El array a imprimir.
/// @param length - El tamaño de la lista.
void printArrayInt(char message[], int list[], int length);

/// @brief Pide un array de flotantes de manera secuencial.
///
/// @param list - El array donde se van a guardar los flotantes.
/// @param length - El tamaño del array.
/// @param message - El mensaje a mostrar al momento de pedir los flotantes.
/// @param errorMessage - El mensaje a mostrar si el flotante ingresado no entra en los parámetros dados.
/// @param min - El mínimo que puede ser el flotante.
/// @param max - El máximo que puede ser el flotante.
void getSequentialArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Pide un array de flotantes de manera aleatoria.
///
/// @param list - El array donde se van a guardar los flotantes.
/// @param length - El tamaño del array.
/// @param message - El mensaje a mostrar al momento de pedir los flotantes.
/// @param errorMessage - El mensaje a mostrar en pantalla si el flotante ingresado no entra en los parámetros dados.
/// @param min - El mínimo que puede ser el flotante.
/// @param max - El máximo que puede ser el flotante.
void getRandomArrayFloat(float list[], int length, char message[], char errorMessage[], int min, int max);

/// @brief Muestra en pantalla el array de flotantes pasado por parámetro.
///
/// @param message - El mensaje a mostrar antes que el array.
/// @param list - El array a imprimir.
/// @param length - El tamaño de la lista.
void printArrayFloat(char message[], float list[], int length);

/// @brief Pide una cadena de caracteres.
///
/// @param message - El mensaje a mostrar antes que el array.
/// @param input - El array donde se va a guardar la cadena.
/// @param length - El tamaño máximo de la cadena.
void getString(char message[], char input[], int length);

/// @brief Imprime las distintas opciones del menú de la lista.
///
/// @return int - Retorna el entero pedido con "getLimitedInt()"
int getMenuOption();

/// @brief Imprime las distintas opciones del menú de modificaciones.
///
/// @return int - Retorna el entero pedido con "getLimitedInt()"
int getModificationMenu();

/// @brief Pone la primer letra de cada palabra en mayúscula y el resto en minúscula.
///
/// @param input - El array a modificar y donde se va a guardar la cadena.
void formatName(char input[]);

/// @brief Revisa que la cadena
///
/// @param input - La cadena de caracteres a revisar.
/// @return int - Retorna 1 si está todo bien, o 0 si alguno de los caracteres
/// 			no cumple con la función isalpha o isspace.
int checkAlphabetAndSpace(char input[]);

#endif /* INPUT_H_ */

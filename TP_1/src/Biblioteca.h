/*
 * Biblioteca.h
 *      Author: Marcos
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @brief Pide un entero y lo valida.
///
/// @param char[] - El primer mensaje a mostrar.
/// @param char[] - El mensaje a mostrar en la validación.
/// @param int - El parámetro de mínimo de la validación.
/// @param int - El parámetro de máximo de la validación.
/// @return int - El entero recibido.
int PedirEntero(char[], char[], int, int);

/// @brief Pide la opción a seleccionar del menú y la muestra en la consola.
///
/// @param float - Primer floatante ingresado, para mostrarlo en el menú.
/// @param float - Segundo floatante ingresado, para mostrarlo en el menú.
/// @param int - Una bandera para determinar si se ingresó o no el primer número a mostrar.
/// @param int - Una bandera para determinar si se ingresó o no el segundo número a mostrar.
/// @return int - El número de la opción elegida.
int PedirOpcion(float, float, int, int);

// Resultados------------------------------------------------

/// @brief Muestra en consola el mensaje de resultado de suma.
///
/// @param float - El primer número de la operación a mostrar.
/// @param float - El segundo número de la operación a mostrar.
/// @param float - El resultado de la operación a mostrar.
void ResultadoSuma(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de resta.
///
/// @param float - El primer número de la operación a mostrar.
/// @param float - El segundo número de la operación a mostrar.
/// @param float - El resultado de la operación a mostrar.
void ResultadoResta(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de división.
///
/// @param float - El primer número de la operación a mostrar.
/// @param float - El segundo número de la operación a mostrar.
/// @param float - El resultado de la operación a mostrar.
void ResultadoDivision(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de división si es posible, sino, muestra mensaje de error.
///
/// @param float - El primer número de la operación a mostrar.
/// @param float - El segundo número de la operación a mostrar.
/// @param float - El resultado o error de la operación a mostrar.
void ResultadoMultiplicacion(float, float, float);

/// @brief Muestra en consola el mensaje de resultado de factorial si es posible, sino, muestra mensaje de error.
///
/// @param float - El número de la operación a mostrar.
/// @param float - El resultado de la operación a mostrar.
void ResultadoFactorial(float, float);

#endif /* BIBLIOTECA_H_ */

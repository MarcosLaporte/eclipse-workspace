#include "Conversion.h"
#include <stdio.h>

float Celsius_Farenheit(float celsius){
	float numero;

	numero = ((celsius * 9/5) + 32);

	return numero;
}

float Farenheit_Celsius(float farenheit){
	float numero;

	numero = ((farenheit - 32) * 5/9);

	return numero;
}

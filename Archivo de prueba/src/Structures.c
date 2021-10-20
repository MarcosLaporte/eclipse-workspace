/*
 * Structures.c
 *      Author: Marcos
 */

Date getDate(char message[]){
	Date entireDate;

	entireDate.day = getLimitedInt("Ingrese el d�a: ", "ERROR! Ingrese un d�a entre 1 y 31: ", 1, 31);
	entireDate.month = getLimitedInt("Ingrese el mes: ", "ERROR! Ingrese un mes entre 1 y 12: ", 1, 12);
	entireDate.year = getLimitedInt("Ingrese el a�o: ", "ERROR! Ingrese una fecha entre %min y %max:", 1900, 2021);

	return entireDate;
}

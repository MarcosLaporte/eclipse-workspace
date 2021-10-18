/*===========================================================================
 Name        : TP N°1
 Author      : Marcos Laporte
===========================================================================*/

/*===========================================================================
Consigna:
	1. Ingresar 1er operando (A=x)
	2. Ingresar 2do operando (B=y)
	3. Calcular todas las operaciones
		a) Calcular la suma (A+B)
		b) Calcular la resta (A-B)
		c) Calcular la division (A/B)
		d) Calcular la multiplicacion (A*B)
		e) Calcular el factorial (A!)
	4. Informar resultados
		a) “El resultado de A+B es: r”
		b) “El resultado de A-B es: r”
		c) “El resultado de A/B es: r” o “No es posible dividir por cero”
		d) “El resultado de A*B es: r”
		e) “El factorial de A es: r1 y El factorial de B es: r2”
	5. Salir
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Operaciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcionElegida;
	int flagA;
	int flagB;
	flagA = 0;
	flagB = 0;
	float primerNumero;
	primerNumero = 0;
	float segundoNumero;
	segundoNumero = 0;
	int flagCalcular;
	flagCalcular = 0;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	float factorial1;
	float factorial2;

	printf("\t\t#=======================================#\n"
		   "\t\t|\t    TP 1 - CALCULADORA\t\t|\n"
		   "\t\t|\t    --Marcos Laporte--\t\t|\n"
		   "\t\t#=======================================#\n");

	do{
		opcionElegida = PedirOpcion(primerNumero, segundoNumero, flagA, flagB);
		switch(opcionElegida){
		case 1:
			primerNumero = PedirFlotante("Ingrese el primer operando: ");
			flagA = 1;
			break;
		case 2:
			segundoNumero = PedirFlotante("Ingrese el segundo operando: ");
			flagB = 1;
			break;
		case 3:
			if(flagA && flagB){
				suma = SumarNumeros(primerNumero, segundoNumero);
				resta = RestarNumeros(primerNumero, segundoNumero);
				DividirNumeros(primerNumero, segundoNumero, &division);
				multiplicacion = MultiplicarNumeros(primerNumero, segundoNumero);
				factorial1 = CalcularFactorial(primerNumero);
				factorial2 = CalcularFactorial(segundoNumero);
				printf("Las operaciones ya fueron calculadas!\n");
				flagCalcular = 1;
			}else{
				printf("ERROR! No se han ingresado ambos operandos. Reingrese.\n");
			}
			break;
		case 4:
			if(flagCalcular){
				ResultadoSuma(primerNumero, segundoNumero, suma);
				ResultadoResta(primerNumero, segundoNumero, resta);
				ResultadoDivision(primerNumero, segundoNumero, division);
				ResultadoMultiplicacion(primerNumero, segundoNumero, multiplicacion);
				ResultadoFactorial(primerNumero, factorial1);
				ResultadoFactorial(segundoNumero, factorial2);
			}else{
				printf("ERROR! Antes de mostrar los resultados, hay que calcularlos! Reingrese.\n");
			}
			break;
		case 5:
			printf("Salió de la calculadora.");
			break;
		}
	}while(opcionElegida != 5);

	return 0;
}

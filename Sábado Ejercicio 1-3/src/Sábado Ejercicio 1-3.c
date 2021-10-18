/*
 ============================================================================
 Name        : Sábado Ejercicio 1-3
 Author      : Marcos Laporte
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*===========================================================================
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de
la UTN FRA, los datos solicitados son:
	¬Legajo
	¬Tipo cursada(L: libre - P: presencial – R: remota)
	¬Cantidad de materias( mas de cero y menos de 8)
	¬Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
	¬Nota promedio (entre 0 y 10)
	¬Edad (validar)
		Se debe informar de existir, o informar que no existe , en el caso que corresponda.
			a) El Legajo del mejor promedio femenino.
			b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
			c) El promedio de nota por sexo.
			d) La edad y legajo del que cursa más materias. (Sin importar su género)
===========================================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
	setbuf(stdout, NULL);

	char seguir;
	int legajo;
	char tipoCursada;
	int cantMat;
	char sexo;
	int nota;
	int edad;
	int mejorNotaFem;
	int legajoMNF;
	int jovenMascLibre;
	int legajoJML;
	int acumNotaFem;
	int contFem;
	float promNotaFem;
	int acumNotaMasc;
	int contMasc;
	float promNotaMasc;
	int contNoBi;
	int acumNotaNoBi;
	float promNotaNoBi;
	int masMat;
	int edadMasMat;
	int legajoMasMat;

	mejorNotaFem = 0;
	jovenMascLibre = 0;
	acumNotaFem = 0;
	acumNotaMasc = 0;
	acumNotaNoBi = 0;
	contFem = 0;
	contMasc = 0;
	contNoBi = 0;
	masMat = 0;

	do{
//		Legajo
		printf("Ingrese su legajo: ");
		scanf("%d", &legajo);
//		Tipo de cursada
		printf("Ingrese tipo de cursada: ");
		fflush(stdin);
		scanf("%c", &tipoCursada);
		tipoCursada = toupper(tipoCursada);
		while(!(tipoCursada == 'L' || tipoCursada == 'P' || tipoCursada == 'R')){
			printf("Ingrese tipo de cursada (L: libre/P: presencial/R: remota): ");
			fflush(stdin);
			scanf("%c", &tipoCursada);
			tipoCursada = toupper(tipoCursada);
		}
//		Cantidad de materias
		printf("Ingrese cantidad de materias: ");
		scanf("%d", &cantMat);
		while(cantMat < 1 || cantMat > 8){
			printf("Ingrese cantidad de materias (1-8): ");
			scanf("%d", &cantMat);
		}
//		Sexo
		printf("Ingrese su sexo: ");
		fflush(stdin);
		scanf("%c", &sexo);
		sexo = toupper(sexo);
		while(!(sexo == 'F' || sexo == 'M' || sexo == 'O')){
			printf("Ingrese su sexo (F: “femenino”/M: “masculino”/O: “no binario”): ");
			fflush(stdin);
			scanf("%c", &sexo);
			sexo = toupper(sexo);
		}
//		Nota promedio
		printf("Ingrese su nota: ");
		scanf("%d", &nota);
		while(nota < 0 || nota > 10){
			printf("Ingrese su nota (0-10): ");
			scanf("%d", &nota);
		}
//		Edad
		printf("Ingrese su edad: ");
		scanf("%d", &edad);
		while(edad < 17 || edad > 100){
			printf("Ingrese una edad válida: ");
			scanf("%d", &edad);
		}

//		a)
		if(sexo == 'F' && nota > mejorNotaFem){
			mejorNotaFem = nota;
			legajoMNF = legajo;
		}
//		b)
		if(sexo == 'M' && tipoCursada == 'L' && (jovenMascLibre == 0 || edad < jovenMascLibre)){
			jovenMascLibre = edad;
			legajoJML = legajo;
		}
//		c)
		switch(sexo){
		case 'F':
			acumNotaFem += nota;
			contFem++;
			break;
		case 'M':
			acumNotaMasc += nota;
			contMasc++;
			break;
		default:
			acumNotaNoBi += nota;
			contNoBi++;
		}
//		d)
		if(cantMat > masMat){
			masMat = cantMat;
			edadMasMat = edad;
			legajoMasMat = legajo;
		}

		printf("Desea continuar?: ");
		fflush(stdin);
		scanf("%c", &seguir);
		seguir = tolower(seguir);
		while(!(seguir == 's' || seguir == 'n')){
			printf("Desea continuar? s/n: ");
			fflush(stdin);
			scanf("%c", &seguir);
			seguir = tolower(seguir);
		}
	}while(seguir == 's');

	if(mejorNotaFem == 0){
		printf("a) No se ingresaron femeninos.\n");
	}else{
		printf("a) El legajo del mejor promedio femenino (%d) es: %d.\n", mejorNotaFem, legajoMNF);
	}

	if(jovenMascLibre == 0){
		printf("b) No se ingresaron masculinos que cursen libre.\n");
	}else{
		printf("b) El legajo del masculino más joven que dan libre (%d años) es: %d.\n", jovenMascLibre, legajoJML);
	}

	if(contFem == 0){
		promNotaFem = 0;
	}else{
		promNotaFem = (float)acumNotaFem/contFem;
	}
	if(contMasc == 0){
		promNotaMasc = 0;
	}else{
		promNotaMasc = (float)acumNotaMasc/contMasc;
	}
	if(contNoBi == 0){
		promNotaNoBi = 0;
	}else{
		promNotaNoBi = (float)acumNotaNoBi/contNoBi;
	}
	printf("c) Los promedios de nota por sexo son:\nFemenino: %.2f.\nMasculino: %.2f.\nNo binario: %.2f.\n", promNotaFem, promNotaMasc, promNotaNoBi);
	printf("d) La persona que cursa más materias (%d) tiene %d años y su legajo es %d.", masMat, edadMasMat, legajoMasMat);

	return 0;
}

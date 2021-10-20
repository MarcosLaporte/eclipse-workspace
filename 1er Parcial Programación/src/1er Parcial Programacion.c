/*
 ============================================================================
 Name        : 1er Parcial Programación
 Author      : Marcos Laporte
 ============================================================================
 */

/*============================================================================
1. Realizar un párrafo en donde se pueda observar la/s relación/es entre los siguientes términos:
	vector, estructura repetitiva, dirección de memoria, pasaje por valor, pasaje por referencia.
	No esta permitido realizar definiciones de manual, es necesario que el párrafo demuestre las relaciones entre los términos.
2. Realizar una función que reciba como parámetro una cadena de caracteres. La misma permitirá intercambiar
	las vocales por un carácter comodín que también será recibido como parámetro.
	La función retornará la cantidad de reemplazos que se llevaron a cabo.
3. Realizar una función que reciba como parámetro el importe de un producto y un porcentaje de descuento.
	La función retornará el importe con el descuento aplicado. *
============================================================================*/

#include <stdio.h>
#include <stdlib.h>

// 1. Los vectores, ya sean palabras o vector de números, se definen dentro de la estructura repetitiva 'for', que recorre todo el vector para completar los datos pedidos.
//	Estos valores se pasan por referencia, que guarda loss datos en la dirección de memoria del vector, a diferencia de un dato solo, que puede igualarse a la variable, osea pasar por valor.

int intercambiarVocales(char palabra[], int tam, char comodin);
float calcularPrecioConDescuento(float precio, int descuento);

int main(void) {
	setbuf(stdout, NULL);

	char palabras[51] = "Aguante bokita";
	char comodin;
	int reemplazos;

	printf("Por qué caracater desea cambiar las vocales?: ");
	scanf("%c", &comodin);
	reemplazos = intercambiarVocales(palabras, 51, comodin);
	printf("La nueva palabra es: %s\n", palabras);
	printf("Hubo %d reemplazos.\n", reemplazos);

//3--------------------------------------------------------

	float importe = 25000;
	int porcDescuento = 75;
	float precioFinal;

	precioFinal = calcularPrecioConDescuento(importe, porcDescuento);
	printf("El precio $%f con descuento del %d es: %.2f", importe, porcDescuento, precioFinal);

	return EXIT_SUCCESS;
}

int intercambiarVocales(char palabra[], int tam, char comodin){
	int reemplazos;
	reemplazos = 0;

	if(palabra != NULL && tam > 0){
		for(int i = 0; i < tam; i++){
			if(palabra[i] == 'a' || palabra[i] == 'A'
			|| palabra[i] == 'e' || palabra[i] == 'E'
			|| palabra[i] == 'i' || palabra[i] == 'I'
			|| palabra[i] == 'o' || palabra[i] == 'O'
			|| palabra[i] == 'u' || palabra[i] == 'U'){
				palabra[i] = comodin;
				reemplazos++;
			}
		}
	}

	return reemplazos;
}

float calcularPrecioConDescuento(float precio, int descuento){
	float total;
	float porcentaje;
	porcentaje = (float)descuento/100;

	total = (precio - precio * porcentaje);

	return total;
}

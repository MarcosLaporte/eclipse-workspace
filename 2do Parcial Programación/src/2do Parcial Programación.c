/******************************************************************************
Marcos Laporte
1c

Consigna:
1. Crear una estructura con 3 campos: un entero (su id), una cadena y un flotante. Para dicha estructura:
    1-a. Crear getters y setters.
    1-b. Crear un constructor por defecto y uno parametrizado.
    1-c. Hardcodear un dato del tipo de la estructura en el main y guardarlo en un archivo binario (el nombre del archivo será su nombre y apellido.bin)
    1-d. Leer el dato guardado en el archivo binario y mostrarlo por pantalla.

Notas:
No se podrá utilizar LinkedList
Los puntos 1c y 1d deberán desarrollarse en funciones distintas, parametrizadas según corresponda.
No se puede utilzar ninguna estructura de las vistas en clase. Por ejemplo: empleados, productos, etc.
*******************************************************************************/
#include "Weather.h"
#define F_BIN "MarcosLaporte.bin"

int main(){
	setbuf(stdout, NULL);

    Weather climate = {1, "Soleado con granizo", 20.75};
    Weather auxClimate;

	controller_loadToBinary(F_BIN, &climate);
		printf("Los datos se subieron al archivo!\n");
	controller_loadFromBinary(F_BIN, &auxClimate);
		printf("Los datos se tomaron del archivo!\n");
	controller_ListWeather(&auxClimate);

    return 0;
}

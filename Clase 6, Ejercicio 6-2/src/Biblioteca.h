#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#define T 10

void PedirArrayEnteroSec(int lista[], int tam, char mensaje[], char mensajeError[], int min, int max);
int DeterminarPositividad(int numero);
int PositivosYNegativos(int numero[], int tam, int positivos[], int negativos[], int* refContPos, int* refContNeg);
void OrdenarPositivosCreciente(int numeros[], int tam);
void OrdenarNegativosDecreciente(int numeros[], int tam);

#endif /* BIBLIOTECA_H_ */

#ifndef INGRESO_DE_DATOS_H_
#define INGRESO_DE_DATOS_H_
//------------
#define T 5
//------------

int PedirEntero(char mensaje[], char mensajeError[], int min, int max);
void MostrarEntero(char mensaje[], int numero);
float PedirFlotante(char mensaje[], char mensajeError[], int min, int max);
void MostrarFlotante(char mensaje[], float numero);
void PedirArrayEnteroSec(int lista[], int tam, char mensaje[], char mensajeError[], int min, int max);
void PedirArrayEnteroAlea(int lista[], int tam, char mensaje[], char mensajeError[], int min, int max);
void MostrarArrayEntero(char mensaje[], int numero[], int tam);
void PedirArrayFlotanteSec(float lista[], int tam, char mensaje[], char mensajeError[], int min, int max);
void PedirArrayFlotanteAlea(float lista[], int tam, char mensaje[], char mensajeError[], int min, int max);
void MostrarArrayFlotante(char mensaje[], float numero[], int tam);
void PedirCadena(char mensaje[], char input[]);
void MostrarCadena(char mensaje[]);

#endif /* INGRESO_DE_DATOS_H_ */

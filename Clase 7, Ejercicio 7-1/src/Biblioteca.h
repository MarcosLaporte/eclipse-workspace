#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
//------------
#define T 5
//------------

// nacionalidad
#define EEUU 1
#define CHINA 2
#define OTRO 3
// tipo
#define IPHONE 1
#define MAC 2
#define IPAD 3
#define ACCESORIOS 4
//estado
#define VACIO 0
#define CARGADO 1

int PedirEntero(char mensaje[], char mensajeError[], int min, int max);
float PedirFlotante(char mensaje[], char mensajeError[], int min, int max);
void PedirCadena(char mensaje[], char input[]);

void PedirDatosProducto(int* id, char* desc[50], int* nacion, int* tipo, float* precio, int* estado);
int AltaProducto(int id[], char desc[][50], int nacion[], int tipo[], float precio[], int estado[], int tam);
void MostrarDatosProducto(int id[], char desc[][50], int nacion[], int tipo[], float precio[]);

#endif /* BIBLIOTECA_H_ */

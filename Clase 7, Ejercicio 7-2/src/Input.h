#ifndef INPUT_H_
#define INPUT_H_
//------------
#define T 5
//------------

int PedirEntero(char mensaje[], char mensajeError[], int min, int max);
void PedirDosArrayEnteros(int listaA[], int listaB[], int tam);
int BuscarNumero(int lista[], int tam, float valorBusqueda);
void MayorNumero(int primerLista[], int segundaLista[], int terceraLista[], int tam);
void OrdenarVectoresPorUnVector(int vectorC[], int tam, int vectorA[], int vectorB[]);
void MostrarTresArray(int listaA[], int listaB[], int listaC[], int tam);

#endif /* INPUT_H_ */

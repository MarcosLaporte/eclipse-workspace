#include "parser.h"

int parser_PilotFromText(FILE* pFile , LinkedList* pilotArray)
{
	int ans;
	char idFlight[5];
	char idPlane[5];
	char idPilot[5];
	char date[11];
	char dest[25];
	char passen[5];
	char depart[6];
	char arrival[6];

	if(pFile != NULL && pilotArray != NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^]%[^,],%[^,],%[^,],%[^\n]\n", idFlight, idPlane, idPilot, date, dest, passen, depart, arrival);
		while(!feof(pFile)){
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^]%[^,],%[^,],%[^,],%[^\n]\n", idFlight, idPlane, idPilot, date, dest, passen, depart, arrival) == 8){
				if(isAnInt(idFlight, ID_LEN) && isAnInt(idPlane, ID_LEN) && isAnInt(idPilot, ID_LEN) &&
						isDate(date, 11) && isAlphaSpace(dest) && isAnInt(passen, 5) && isAnInt(depart, 6) && isAnInt(arrival, 6)){

				}
			}
		}
	}

	return ans;
}

/** \brief Parsea los datos los datos de los pilotos desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pilotArray LinkedList*
 * \return int
 *
 */
int parser_PilotFromBinary(FILE* pFile , LinkedList* pilotArray)
{
	int ans;

    return ans;
}

/// @brief Imprime en el archivo 'pFile' los datos del piloto de la LL. (modo texto)
///
/// @param pFile - Puntero al archivo.
/// @param pilotArray - Puntero a la LinkedList.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está tod bien.
int parser_TextFromPilot(FILE* pFile, LinkedList* pilotArray){
	int ans;

	return ans;
}

/// @brief Imprime en el archivo 'pFile' los datos del piloto de la LL. (modo binario)
///
/// @param pFile - Puntero al archivo.
/// @param pilotArray - Puntero a la LinkedList.
/// @return int - Retorna 0 si el puntero es nulo, o 1 si está tod bien.
int parser_BinaryFromPilot(FILE* pFile, LinkedList* pilotArray){
	int ans;

	return ans;
}

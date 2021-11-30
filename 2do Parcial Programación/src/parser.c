#include "parser.h"

///// @brief Parsea los datos de libro desde el csv a la Linked
/////
///// @param pFile Puntero al archivo
///// @param bookArray LinkedList de libros
///// @return int Retorna 0 si los punteros son nulos, sino 1
//int parser_WeatherFromText(FILE* pFile, Weather today){
//	int returnAux = 0;
//	Weather aux;
//	char id[ID_LEN];
//	char forec[FOREC_LEN];
//	char temp[TEMP_LEN];
//
//	if(pFile != NULL && today != NULL){
//		fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, forec, temp);
//		while(!feof(pFile)){
//			if(fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, forec, temp) == 3){
//				if(isAnInt(id, ID_LEN) && isAlphaSpace(forec) && isAFloat(temp, TEMP_LEN)){
//					aux = book_newParam(id, forec, temp);
//				}
//			}
//		}
//		returnAux = 1;
//	}
//
//	return returnAux;
//}

int parser_WeatherFromBinary(FILE* pFile, Weather* pWeather){
	int returnAux = 0;
	Weather* climate;

	if(pFile != NULL && pWeather != NULL){
		while(!feof(pFile)){
			climate = weather_new();
			if(fread(climate, sizeof(Weather), 1, pFile) == 1){
				returnAux = 1;
			}
		}
	}

    return returnAux;
}

int parser_BinaryFromWeather(FILE* pFile, Weather* pWeather){
	int returnAux = 0;

	if(pFile != NULL){
		if(fwrite(pWeather, sizeof(Weather), 1, pFile) == 1){
			returnAux = 1;
		}
	}

	return returnAux;
}

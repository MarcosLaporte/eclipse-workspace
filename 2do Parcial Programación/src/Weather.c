/*
 * Weather.c
 *
 *  Created on: 29 nov. 2021
 *      Author: Marcos
 */

#include "Weather.h"

Weather* weather_new(){
	Weather* miEmpleado;

	miEmpleado = (Weather*)calloc(1, sizeof(Weather));

	return miEmpleado;
}

int weather_setId(Weather* this, int id){
    int returnAux = 0;

    if(this != NULL){
        this->id = id;
        returnAux = 1;
    }

    return returnAux;
}

int weather_getId(Weather* this, int* id){
    int returnAux = 0;

    if(this != NULL && id != NULL){
        *id = this->id;
        returnAux = 1;
    }

    return returnAux;
}

int weather_setForecast(Weather* this, char* forec){
    int returnAux = 0;

    if(this != NULL && forec != NULL){
        strcpy(this->forecast, forec);
        returnAux = 1;
    }

    return returnAux;
}

int weather_getForecast(Weather* this, char* forec){
    int returnAux = 0;

    if(this != NULL && forec != NULL){
        strcpy(forec, this->forecast);
        returnAux = 1;
    }

    return returnAux;
}

int weather_setTemp(Weather* this, float temp){
    int returnAux = 0;

    if(this != NULL){
        this->temp = temp;
        returnAux = 1;
    }

    return returnAux;
}

int weather_getTemp(Weather* this, float* temp){
    int returnAux = 0;

    if(this != NULL && temp != NULL){
        *temp = this->temp;
        returnAux = 1;
    }

    return returnAux;
}

Weather makeWeather(void){
	Weather auxWea = {99, "Soleado", 26.3};

	return auxWea;
}

Weather* getWeather(int id, char* forecast, float temp){
	Weather* auxWea = NULL;

	if(forecast != NULL){
		weather_setId(auxWea, id);
		weather_setForecast(auxWea, forecast);
		weather_setTemp(auxWea, temp);
	}

	return auxWea;
}

//Controller
//Saca del archivo y lo trae acá
int controller_loadFromBinary(char* path, Weather* pWeather){
	int returnAux = 0;
	FILE* pFile;

	if(path != NULL && pWeather != NULL){
		pFile = fopen(path, "rb");
		if(parser_WeatherFromBinary(pFile, pWeather)){
			returnAux = 1;
		}
		fclose(pFile);
	}

    return returnAux;
}

//Saca de acá y lleva al archivo
int controller_loadToBinary(char* path, Weather* pWeather){
	int returnAux = 0;
	FILE* pFile;

	if(path != NULL && pWeather != NULL){
		pFile = fopen(path, "wb");
		if(parser_BinaryFromWeather(pFile, pWeather)){
			returnAux = 1;
		}
		fclose(pFile);
	}

	return returnAux;
}

int controller_ListWeather(Weather* today){
	int returnAux = 0;
	int id;
	char forec[FOREC_LEN];
	float temp;

	if(today != NULL){
		printf("#===========================================#\n");
		printf("|%-5s|%-25s|%-11s|\n", "ID", "Clima", "Temperatura");
		printf("#=====+=========================+===========#\n");
		weather_getId(today, &id);
		weather_getForecast(today, forec);
		weather_getTemp(today, &temp);
		printf("|%5d|%25s|%8.2f °C|\n", id, forec, temp);
		printf("#===========================================#\n");
		returnAux = 1;
	}

	return returnAux;
}

//Parser

int parser_WeatherFromBinary(FILE* pFile, Weather* pWeather){
	int returnAux = 0;
	Weather* auxWeather;

	if(pFile != NULL && pWeather != NULL){
		while(!feof(pFile)){
			auxWeather = weather_new();
			if(fread(auxWeather, sizeof(Weather), 1, pFile) == 1){
				weather_setId(pWeather, auxWeather->id);
				weather_setForecast(pWeather, auxWeather->forecast);
				weather_setTemp(pWeather, auxWeather->temp);
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

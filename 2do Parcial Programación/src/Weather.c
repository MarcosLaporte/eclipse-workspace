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

Weather* makeWeather(void){
	Weather* auxWea = {99, "Soleado", 26.3};

	return auxWea;
}
Weather* getWeather(int id, char* forecast, float temp){
	Weather* auxWea;

	if(forecast != NULL){
		weather_setId(auxWea, id);
		weather_setForecast(auxWea, forecast);
		weather_setTemp(auxWea, temp);
	}

	return auxWea;
}

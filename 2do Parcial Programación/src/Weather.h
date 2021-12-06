/*
 * Weather.h
 *
 *  Created on: 29 nov. 2021
 *      Author: Marcos
 */

#ifndef WEATHER_H_
#define WEATHER_H_
#include "Input.h"

typedef struct{
	int id;
	char forecast[25];
	float temp;
}Weather;

Weather* weather_new();

int weather_setId(Weather* this, int id);
int weather_getId(Weather* this, int* id);

int weather_setForecast(Weather* this, char* forecast);
int weather_getForecast(Weather* this, char* forecast);

int weather_setTemp(Weather* this, float temp);
int weather_getTemp(Weather* this, float* temp);

Weather makeWeather(void);
Weather* getWeather(int id, char* forecast, float temp);

//Controller
int controller_loadFromBinary(char* path, Weather* pWeather);
int controller_loadToBinary(char* path, Weather* pWeather);
int controller_ListWeather(Weather* today);

//Parser
int parser_WeatherFromBinary(FILE* pFile, Weather* pWeather);
int parser_BinaryFromWeather(FILE* pFile, Weather* pWeather);

#endif /* WEATHER_H_ */

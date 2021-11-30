#ifndef PARSER_H_
#define PARSER_H_

#include "Input.h"
#include "Weather.h"

int parser_WeatherFromBinary(FILE* pFile, Weather* pWeather);
int parser_BinaryFromWeather(FILE* pFile, Weather* pWeather);

//int parser_TextFromBook(FILE* pFile, LinkedList* bookArray);
#endif /* PARSER_H_ */

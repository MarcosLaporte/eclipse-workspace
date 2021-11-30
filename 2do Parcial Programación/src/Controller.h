#include "parser.h"
#include "Input.h"
#include "Weather.h"

int controller_loadFromBinary(char* path, Weather* pWeather);
int controller_loadToBinary(char* path, Weather* pWeather);

int controller_ListWeather(Weather* today);

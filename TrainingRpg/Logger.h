#ifndef LOGGER_H
#define LOGGER_H
/*********************************************************************
*	Programmer: Dylan Morgan
*	Last Edit: 04/15/2020
*
*	Description: A custom logger for error messages or any other
*		type of data that needs to be logged
*********************************************************************/

#include "Globals.h"
class Logger
{
public:
	static void Log(std::string log, bool toFile = true, bool autoName = true, std::string fileName = "");
};

#endif // !LOGGER_H

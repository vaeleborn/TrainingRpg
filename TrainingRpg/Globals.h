#ifndef GLOBALS_H
#define GLOBALS_H
/*********************************************************************
*	Programmer: Dylan Morgan
*	Last Edit: 04/16/2020
*
*	Description: Contains some global includes and functions
*********************************************************************/
#define uint unsigned int

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include <iterator>

void Subtract(uint* x, uint y);

//generate a random integer inclusively
int RandomInt(int min, int max);

//Function that simulates a dice roll for any type of die
int DiceRoll(int multiplier, int dieType);

#endif // !GLOBALS_H


#ifndef STATS_H
#define STATS_H
/*********************************************************************
*	Programmer: Dylan Morgan
*	Last Edit: 04/05/2020
*
*	Description: Contains the Stats class which will hold all the 
*		basic stats needed for a character
*********************************************************************/
#include "Globals.h"
class Stats
{
public:

	//Getters
	uint GetStrength() { return mStrength; }
	uint GetHealth() { return mHealth; }

	//Setters
	void SetHealth(uint health) { mHealth = health; }
	void SetStrength(uint strength) { mStrength = strength; }

	//Modifier Functions
	void AddHealth(uint amt);
	void SubtractHealth(uint amt);
	void AddStrength(uint amt);
	void SubtractStrength(uint amt);

	/* A static function that will return an instance of the Stats class with random values
	Possibly add optional level var to be able to use for random encounters of any level */
	static Stats RandomInitialStats();

	//Constructors
	Stats();
	Stats(uint health, uint strength);
	Stats(Stats* s);

	//Operator Overloads
	Stats& operator=(const Stats& other);

private:
	//Stat variables
	uint mStrength;
	uint mHealth;
};

#endif

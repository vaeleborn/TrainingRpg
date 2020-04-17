#ifndef BASECHARACTER_H
#define BASECHARACTER_H
#include "Stats.h"

class BaseCharacter
{
public:

	Stats* GetStats() { return &mStats; }
	std::string GetName() { return mName; }
	uint GetID() { return mID; }

	void SetName(std::string name) { mName = name; }

	BaseCharacter();
	BaseCharacter(std::string name, Stats stats);

	//SFML functions

private:
	std::string mName;
	static uint mNEXT_ID;
	uint mID;

	Stats mStats;

	//SFML vars
	

	
};


#endif // !BASECHARACTER_H



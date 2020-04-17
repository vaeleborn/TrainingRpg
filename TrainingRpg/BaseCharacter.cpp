#include "BaseCharacter.h"

uint BaseCharacter::mNEXT_ID = 0;

BaseCharacter::BaseCharacter()
{
	mName = "Placeholder Name";
	mID = mNEXT_ID;
	mNEXT_ID++;
}

BaseCharacter::BaseCharacter(std::string name, Stats stats) : mName(name), mStats(&stats)
{
	mID = mNEXT_ID;
	mNEXT_ID++;
}

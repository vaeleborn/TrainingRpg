#pragma once
#include "Globals.h"
class Stats
{
public:
	uint GetStrength() { return mStrength; }
	uint GetHealth() { return mHealth; }

	void SetHealth(uint health) { mHealth = health; }
	void SetStrength(uint strength) { mStrength = strength; }

	void AddHealth(uint amt);
	void SubtractHealth(uint amt);
	void AddStrength(uint amt);
	void SubtractStrength(uint amt);

	Stats();
	Stats(uint health, uint strength);
	Stats(Stats* s);

private:
	uint mStrength;
	uint mHealth;
};


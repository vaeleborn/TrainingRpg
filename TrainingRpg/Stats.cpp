#include "Stats.h"

Stats::Stats()
{
	mStrength = 10;
	mHealth = 100;
}

Stats::Stats(Stats* stats)
{
	mStrength = stats->GetStrength();
	mHealth = stats->GetHealth();
}

Stats::Stats(uint health, uint strength)
{
	mStrength = strength;
	mHealth = health;
}

void Stats::AddHealth(uint amt)
{
	mHealth += amt;
}

void Stats::SubtractHealth(uint amt)
{
	Subtract(&mHealth, amt);
}

void Stats::AddStrength(uint amt)
{
	mStrength += amt;
}

void Stats::SubtractStrength(uint amt)
{
	Subtract(&mStrength, amt);
}
#include "Globals.h"

void Subtract(uint* x, uint y) {
if (y <= *x) {
	*x -= y;
}
else {
	*x = 0;
}
}

int RandomInt(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int DiceRoll(int multiplier, int dieType)
{
	int rtn = 0;

	for (int i = 0; i < multiplier; i++)
	{
		rtn += RandomInt(1, dieType);
	}
	return rtn;
}
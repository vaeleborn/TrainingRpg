#include "Globals.h"

void Subtract(uint* x, uint y) {
if (y <= *x) {
	*x -= y;
}
else {
	*x = 0;
}
}
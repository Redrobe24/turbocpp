#include <math.h>

double roundoff(double x) {
	if (x - floor(x) >= 5) {
		x = ceil(x);
	}
	else {
		x = floor(x);
	}
	return x;
}
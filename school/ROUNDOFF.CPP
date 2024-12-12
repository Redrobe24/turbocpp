#include <iostream.h>
#include <conio.h>
#include <math.h>

int main() {
	clrscr();
	double n;
	cout << "Enter a number with decimal value: ";
	cin >> n;
	if (n - floor(n) < 0.5) {
		n = floor(n);
	}
	else {
		n = ceil(n);
	}
	cout << n;
	getch();

	return 0;
}
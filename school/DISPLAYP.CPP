#include <iostream.h>
#include <conio.h>
#include <ctype.h>

int main()
{
	char rep;
	int factor, n1, n2, x;
	do {
	clrscr();

	cout << "Enter 1st number: ";
	cin >> n1;
	cout << "Enter 2nd number: ";
	cin >> n2;
	for (n1; n1 <= n2; n1++) {
		factor = 0;
		for (x = 1; x <= n1; x++) {
			if (n1 % x == 0) {
				factor++;
			}
		}
		if (factor == 2) {
			cout << n1 << ' ';
		}
	}

	cout << "\nPress [Y] to go again, press any keys to exit";
	rep = tolower(getch());
	} while (rep == 'y');

	return 0;
}
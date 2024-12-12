#include <iostream.h>
#include <conio.h>
#include <ctype.h>
					//prime or not
int main()
{
	int factor, number, x;
	char rep;
	do {
		factor = 0;
		x = 1;
		clrscr();
		cout << "Enter a number: ";
		cin >> number;
		while (x <= number) {
			if (number % x == 0) {
				factor += 1;
			}
			x++;
		}
		if (factor == 2) {
			cout << "It is a prime number";
		}
		else {
			cout << "It is not a prime number";
		}
		cout << "\nAgain? [Y][N]";
		rep = tolower(getch());
	} while (rep == 'y');
	return 0;
}
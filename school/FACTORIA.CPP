#include <iostream.h>
#include <conio.h>

int main() {
	clrscr();
	int number, x, result = 1;
	cout << "Enter a number: ";
	cin >> number;
	for (x = 1; x <= number; x++) {
		result *= x;
	}
	cout << "The factorial of " << number << " is " << result;
	getch();

	return 0;
}
#include <iostream.h>
#include <conio.h>

int main()
{
	clrscr();
	int n, sum, x;
	sum = 0;
	cout << "Enter a number: ";
	cin >> n;
	for (x = 1; x < n; x++) {
		if (n % x == 0) {
			sum += x;
		}
	}
	if (sum == n) {
		cout << n << " is a perfect number";
	}
	else {
		cout << n << " is not a perfect number";
	}
	getch();
	return 0;
}
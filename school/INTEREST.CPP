#include <iostream.h>
#include <conio.h>

double calculate_acc_balance(double b, double r, double w);

int main()
{
	double rate, weeks, balance;
	clrscr();
	cout << "Enter the amount of deposit: ";
	cin >> balance;
	cout << "Enter the interest rate: ";
	cin >> rate;
	cout << "Enter the duration in weeks: ";
	cin >> weeks;
	cout << "The balance after " << weeks << " weeks: $" << calculate_acc_balance(balance, rate, weeks);;
	getch();
	return 0;
}

double calculate_acc_balance(double b, double r, double w) {
	double days, rate, balance;
	balance = b;
	rate = r / 100;
	days = w * 7;
	for (int x = 1; x <= days; x++) {
		balance += ((balance * rate) / 365);
	}
	return balance;
}
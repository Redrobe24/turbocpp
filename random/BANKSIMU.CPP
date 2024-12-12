#include <iostream.h>

int main() {
	double choice, acc, deposit, withdraw;
	acc = 0;
	cout << "\033[2J\033[1;1H";
	cout << "Welcome to your bank account" << endl;

	while(1) {
		cout << "Current bank account balance: $" << acc
			 << "\nWhat do you want to do: "
			 << "\n(1)Deposit\n(2)Withdraw\n(3)Exit\n> ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "\033[2J\033[1;1H";
			cout << "Invalid Input" << endl;
			continue;
		}

		if (choice == 1.0) {
			cout << "How much do you want to deposit: ";
			cin >> deposit;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "\033[2J\033[1;1H";
				cout << "Invalid Input" << endl;
			}
			if (deposit < 0) {
				cout << "\033[2J\033[1;1H";
				cout << "Invalid number" << endl;
				continue;
			}
			else {
				acc = acc + deposit;
				cout << "\033[2J\033[1;1H";
				cout << "Successfuly deposited: $" << deposit << endl;
			}
		}
		else if (choice == 2.0) {
			cout << "How much do you want to withdraw: ";
			cin >> withdraw;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "\033[2J\033[1;1H";
				cout << "Invalid Input" << endl;
				continue;
			}
			if (withdraw < 0) {
				cout << "\033[2J\033[1;1H";
				cout << "Invalid number" << endl;
				continue;
			}
			if (withdraw > acc) {
				cout << "\033[2J\033[1;1H";
				cout << "Cannot withdraw amount" << endl;
			}
			else if (withdraw <= acc) {
				cout << "\033[2J\033[1;1H";
				cout << "Withdraw amount: $" << withdraw << endl;
				acc = acc - withdraw;
			}
		}
		else if (choice == 3.0) {
			break;
		}
		else {
			cout << "\033[2J\033[1;1H";
			cout << "Not in choice" << endl;
		}
	}
	cout << "Logging out...";

	return 0;
}

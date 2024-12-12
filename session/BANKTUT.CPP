#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <dos.h>

struct account {
  char username[20], password[10];
  double balance;
  int id;
};

int main() {
	clrscr();
	_setcursortype(_NOCURSOR);
	account stud[99];
	char rep;
	char input[99];
	double rep_money;
	int acc = 0;
	//system
	do {
		clrscr();
		//menu
		cout << "WELCOME TO THE BANK" << endl
			 << "[1] Login" << endl
			 << "[2] Sign up" << endl
			 << "[3] Exit";
		rep = getch();
		//switch
		switch (rep) {
			case '1':
				clrscr();
				//check if there is no account
				if (acc == 0) {
					cout << "NO ACCOUNTS FOUND";
					delay(1000);
					break;
				}
				//login sequence
				int index;
				int match = 0;
				//username checking
				cout << "LOGGING IN" << endl
					 << "Enter username: ";
				cin >> input;
				for (int x = 0; x < acc; x++) {
					if (strcmp(stud[x].username, input) == 0) {
						index = x;
						break;
					}
				}
				if (x == acc) {
					clrscr();
					cout << "Account not found";
					getch();
					break;
				}
				//password checking
				clrscr();
				cout << "ACCOUNT FOUND" << endl
					 << "Enter password: ";
				cin >> input;
				if (strcmp(stud[index].password, input) == 0) {
					cout << "Succesfully logged in";
					match = 1;
				}
				else {
					cout << "Wrong password";
				}
				getch();
				//if password and username match then go to account menu
				while (match) {
					clrscr();
					cout << "Welcome back, " << stud[index].username << endl
						 << "Account ID: " << stud[index].id << endl
						 << "[1] Deposit" << endl
						 << "[2] Withdraw" << endl
						 << "[3] Check Balance" << endl
						 << "[4] Exit";
					rep = getch();
					clrscr();
					switch (rep) {
						case '1':
							cout << "Enter amount to deposit: ";
							cin >> rep_money;
							stud[index].balance += rep_money;
							break;
						case '2':
							cout << "Enter amount to withdraw: ";
							cin >> rep_money;
							if (rep_money <= stud[index].balance) {
								cout << "Succesfully withdrawn the money";
								stud[index].balance -= rep_money;
							}
							else {
								cout << "Too much money to withdraw";
							}
							getch();
							break;
						case '3':
							cout << "BALANCE: P" << stud[index].balance;
							getch();
							break;
						case '4':
							cout << "Exiting...";
							delay(500);
							match = 0;
							break;
						default:
							cout << "Invalid input";
							getch();
					}
				}
				break;
			case '2':
				clrscr();
				cout << "SIGNING UP" << endl;
				//getting of username
				do {
					cout << "Please enter your name [4 - 20]: ";
					cin >> stud[acc].username;
					clrscr();
					cout << "INVALID NAME" << endl;
				} while (strlen(stud[acc].username) < 4 || strlen(stud[acc].username) > 20);
				clrscr();
				//getting of password
				cout << "USERNAME ACCEPTED" << endl;
				do {
					cout << "Please enter a password [4 - 10]: ";
					cin >> stud[acc].password;
					clrscr();
					cout << "INVALID PASSWORD" << endl;
				} while (strlen(stud[acc].password) < 4 || strlen(stud[acc].password) > 10);
				clrscr();
				//getting initial balance
				cout << "PASSWORD ACCEPTED" << endl
					 << "Enter initial balance in PHP: ";
				cin >> stud[acc].balance;
				//initialize acc id
				stud[acc].id = 1001 + acc;
				//display summary
				int state = 0;
				do {
					clrscr();
					cout << "ACCOUNT CREATED" << endl
						 << "ID: " <<  stud[acc].id << endl
						 << "Username: " << stud[acc].username << endl;
					//check if show[1] or hide[0]
					if (state == 1) {
						cout << "Password: " << stud[acc].password << endl;
					}
					else if (state == 0) {
						cout << "Password: ";
						for (int x = 1; x <= strlen(stud[acc].password); x++) {
							cout << "*";
						}
						cout << endl;
					}
					//
					cout << "Balance: P" << stud[acc].balance << endl << endl
						 << "Press space to show/hide password, press any key to continue!";
					rep = getch();
					// check if show[1] or hide[0]
					if (rep == ' ' && state == 0) {
						state = 1; //show
					}
					else if (rep == ' ' && state == 1) {
						state = 0; //hide
					}
					//
				} while (rep == ' ');
				// crucial to increment acc so bank can keep count of acc
				acc++;
				// crucial
				break;
			case '3':
				clrscr();
				cout << "Exiting...";
				delay(1000);
				break;
			default:
				// incase not in choice
				clrscr();
				cout << "Invalid Input";
				getch();
				break;
		};
	} while (rep != '3');

	return 0;
}
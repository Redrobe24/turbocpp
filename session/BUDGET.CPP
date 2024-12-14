#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>

struct acc {
	char name[20], item[99][20];
	double initial, current, price[99];
	int quantity[99], id, item_purchased;
};

int main() {
	acc stud[20];
	int num_stud = 0;
	int running = 1;
	int rep_id;
	char rep;
	_setcursortype(_NOCURSOR);
	while (running) {
		clrscr();
		cout << "BUDGETING SYSTEM" << endl
			 << "[1] Pick student" << endl
			 << "[2] View student" << endl
			 << "[3] Add student" << endl
			 << "[4] Exit";
		rep = getch();
		switch (rep) {
			case '1':
				int found = 0;
				clrscr();
				cout << "Which student, enter ID: ";
				cin >> rep_id;

				for (int x = 0; x < num_stud; x++) {
					if (rep_id == stud[x].id) {
						found = 1;
						break;
					}
				}
				if (found == 1) {
					int budgeting = 1;
					double percentage;
					while (budgeting) {
						clrscr();
						cout << stud[x].name << "'s Account" << endl
							 << "Intial Budget: " << stud[x].initial << endl
							 << "Current Budget: " << stud[x].current << endl
							 << "Condition: ";
						percentage = stud[x].current / stud[x].initial;
						//
						if (percentage <= 0.1) {
							cout << "WARNING, MONEY IS LOW" << endl;
						}
						else if (percentage < 0.5) {
							cout << "Below 50%, spend wisely" << endl;
						}
						else {
							cout << "Normal" << endl;
						}
						//
						cout << "[1] Buy" << endl
							 << "[2] View History" << endl
							 << "[3] Add money" << endl
							 << "[4] Exit";
						rep = getch();
						switch (rep) {
							case '1':
								if (stud[x].current <= 0) {
									cout << "No money";
									break;
								}
								int purch = stud[x].item_purchased;
								clrscr();
								cout << "Enter item: ";
								cin >> stud[x].item[purch];
								cout << "Enter item price: ";
								cin >> stud[x].price[purch];
								cout << "Enter item quantity: ";
								cin >> stud[x].quantity[purch];
								cout << "Total: " << stud[x].price[purch] * stud[x].quantity[purch] << endl;
								if (stud[x].price[purch] * stud[x].quantity[purch] <= stud[x].current) {
									cout << "Able to purchase, proceed? [Y][N]" << endl;
									rep = tolower(getch());
									if (rep == 'y') {
										cout << "Succesfully purchased!";
										stud[x].current -= stud[x].price[purch] * stud[x].quantity[purch];
										stud[x].item_purchased++;
									}
									else {
										cout << "Cancelled";
										strcpy(stud[x].item[purch], stud[x].item[purch + 1]);
										stud[x].price[purch] = stud[x].price[purch + 1];
										stud[x].quantity[purch] = stud[x].quantity[purch + 1];
									}
								}
								else {
									cout << "Costs too high";
								}
								getch();
								break;
							case '2':
								clrscr();
								gotoxy(5,3);
								cout << "ITEM";
								gotoxy(21, 3);
								cout << "PRICE";
								gotoxy(35, 3);
								cout << "QUANTITY";
								gotoxy(49, 3);
								cout << "TOTAL";
								int row = 5;
								double total = 0;
								for (int y = 0; y < stud[x].item_purchased; y++) {
									gotoxy(1, row + y);
									cout << y + 1 << ". " << stud[x].item[y];
									gotoxy(21, row + y);
									cout << stud[x].price[y];
									gotoxy(35, row + y);
									cout << stud[x].quantity[y];
									gotoxy(49, row + y);
									cout << stud[x].quantity[y] * stud[x].price[y];
									total += stud[x].quantity[y] * stud[x].price[y];
								}
								gotoxy(1, row + y);
								cout << endl << "Total money spent: " << total;
								getch();
								break;
							case '3':
								clrscr();
								double money;
								cout << "How much money do you want to add: ";
								cin >> money;
								stud[x].current += money;
								cout << "Done!";
								getch();
								break;
							case '4':
								budgeting = 0;
								break;
						}
					}
				}
				else {
					clrscr();
					cout << "NO STUDENTS FOUND";
				}
				break;
			case '2':
				clrscr();
				gotoxy(5,3);
				cout << "NAME";
				gotoxy(21, 3);
				cout << "INITIAL";
				gotoxy(35, 3);
				cout << "CURRENT";
				gotoxy(49, 3);
				cout << "ITEM PURCHASED";
				int row = 5;
				for (x = 0; x < num_stud; x++) {
					gotoxy(1, row + x);
					cout << "[" << stud[x].id << "] " << stud[x].name;
					gotoxy(21, row + x);
					cout << stud[x].initial;
					gotoxy(35, row + x);
					cout << stud[x].current;
					gotoxy(49, row + x);
					cout << stud[x].item_purchased;
				}
				getch();
				break;
			case '3':
				// name
				do {
					clrscr();
					cout << "Enter student name: ";
					cin >> stud[num_stud].name;
				} while (strlen(stud[num_stud].name) > 20);
				//money
				clrscr();
				cout << "Enter student's initial money: ";
				cin >> stud[num_stud].initial;
				// initialize current and id
				stud[num_stud].current = stud[num_stud].initial;
				stud[num_stud].id = num_stud + 1;
				stud[num_stud].item_purchased = 0;
				num_stud++;
				break;
			case '4':
				clrscr();
				cout << "Goodbye";
				delay(500);
				running = 0;
				break;
		}
	}
	return 0;
}
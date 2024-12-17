#include <iostream.h>
#include <conio.h>
#include <string.h>

struct department {
	char name[20];
	double budget, mr, travel, st, os, c;
};

int main() {
	clrscr();
	_setcursortype(_NOCURSOR);
	department dep[6];
	strcpy(dep[0].name, "Dean's");
	strcpy(dep[1].name, "Civil");
	strcpy(dep[2].name, "Mechanical");
	strcpy(dep[3].name, "Electrical");
	strcpy(dep[4].name, "Computer");
	strcpy(dep[5].name, "Electronics");

	int x;
	double annual;
	cout << "Enter annual budget: ";
	cin >> annual;
	dep[0].budget = annual * 0.2;
	for (x = 1; x < 6; x++) {
		dep[x].budget = (annual * 0.8) / 5;
	}

	for (x = 0; x < 6; x++) {
		dep[x].mr = dep[x].budget * 0.3;
		dep[x].travel = dep[x].budget * 0.25;
		dep[x].st = dep[x].budget * 0.15;
		dep[x].os = dep[x].budget * 0.1;
		dep[x].c = dep[x].budget * 0.2;
	}

	int running = 1;
	char rep;
	while (running) {
		clrscr();
		cout << "MAIN MENU" << endl
			 << "[1] Report" << endl
			 << "[2] Update" << endl
			 << "[3] Exit";
		rep = getch();
		switch (rep) {
			case '1':
				clrscr();
				gotoxy(43, 2);
				cout << "AREA";
				gotoxy(3, 3);
				cout << "DEPARTMENT";
				gotoxy(20, 3);
				cout << "MAINT/REP";
				gotoxy(31, 3);
				cout << "TRAVEL";
				gotoxy(40, 3);
				cout << "SEM/TRAIN";
				gotoxy(52, 3);
				cout << "OFFICE SUPP";
				gotoxy(66, 3);
				cout << "CONTINGENCY";
				int row = 5;
				for (x = 0; x < 6; x++) {
					gotoxy(3, row + x);
					cout << dep[x].name;
					gotoxy(20, row + x);
					cout << dep[x].mr;
					gotoxy(31, row + x);
					cout << dep[x].travel;
					gotoxy(40, row + x);
					cout << dep[x].st;
					gotoxy(52, row + x);
					cout << dep[x].os;
					gotoxy(66, row + x);
					cout << dep[x].c;
				}
				getch();
				break;
			case '2':
				int choose_dep = 1;
				int choose;
				while (choose_dep) {
					clrscr();
					cout << "CHOOSE DEPARTMENT" << endl
						 << "[1] Dean's Office" << endl
						 << "[2] Civil Engineering" << endl
						 << "[3] Mechanical Engineering" << endl
						 << "[4] Electrical Engineering" << endl
						 << "[5] Computer Engineering" << endl
						 << "[6] Electronics Engineering" << endl
						 << "[7] Exit";
					choose = getch();
					if (choose > 48 && choose < 55) {
						int select = 1;
						int area;
						int ind = choose - 49;
						while (select) {
							clrscr();
							cout << dep[ind].name;
							if (ind == 0) cout << " Office";
							else cout << " Engineering";
							cout << " Menu" << endl
								 << "[1] Report" << endl
								 << "[2] Update" << endl
								 << "[3] Exit";
							rep = getch();
							switch (rep) {
								case '1':
									clrscr();
									gotoxy(3, 3);
									cout << "AREA";
									gotoxy(32, 3);
									cout << "AMOUNT";
									gotoxy(1, 5);
									cout << "Maintenance/Repair" << endl
										 << "Travel" << endl
										 << "Seminar/Training" << endl
										 << "Office Supplies" << endl
										 << "Contigency";
									gotoxy(32, 5);
									cout << dep[ind].mr;
									gotoxy(32, 6);
									cout << dep[ind].travel;
									gotoxy(32, 7);
									cout << dep[ind].st;
									gotoxy(32, 8);
									cout << dep[ind].os;
									gotoxy(32, 9);
									cout << dep[ind].c;
									getch();
									break;
								case '2':
									area = 1;
									while (area) {
										double temp;
										clrscr();
										cout << "SELECT AREA" << endl
											 << "[1] Maintenance/Repair" << endl
											 << "[2] Travel" << endl
											 << "[3] Seminar/Training" << endl
											 << "[4] Office Supplies" << endl
											 << "[5] Contigency" << endl
											 << "[6] Exit";
										rep = getch();
										clrscr();
										switch (rep) {
											case '1':
												cout << "How much do you want to deduct: ";
												cin >> temp;
												if (temp > dep[ind].mr) {
													clrscr();
													cout << "Insufficent Fund";
												}
												else {
													dep[ind].mr -= temp;
													cout << "Succesfully deducted";
												}
												getch();
												break;
											case '2':
												cout << "How much do you want to deduct: ";
												cin >> temp;
												if (temp > dep[ind].travel) {
													clrscr();
													cout << "Insufficent Fund";
												}
												else {
													dep[ind].travel -= temp;
													cout << "Succesfully deducted";
												}
												getch();
												break;
											case '3':
												cout << "How much do you want to deduct: ";
												cin >> temp;
												if (temp > dep[ind].st) {
													clrscr();
													cout << "Insufficent Fund";
												}
												else {
													dep[ind].st -= temp;
													cout << "Succesfully deducted";
												}
												getch();
												break;
											case '4':
												cout << "How much do you want to deduct: ";
												cin >> temp;
												if (temp > dep[ind].os) {
													clrscr();
													cout << "Insufficent Fund";
												}
												else {
													dep[ind].os -= temp;
													cout << "Succesfully deducted";
												}
												getch();
												break;
											case '5':
												cout << "How much do you want to deduct: ";
												cin >> temp;
												if (temp > dep[ind].c) {
													clrscr();
													cout << "Insufficent Fund";
												}
												else {
													dep[ind].c -= temp;
													cout << "Succesfully deducted";
												}
												getch();
												break;
											case '6':
												area = 0;
												break;
										}
									}
									break;
								case '3':
									select = 0;
									break;
							}
						}
					}
					else if (choose == 55) {
						choose_dep = 0;
					}
				}
				break;
			case '3':
				running = 0;
				break;
		}
	}
	return 0;
}
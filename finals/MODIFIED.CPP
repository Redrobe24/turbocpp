#include <iostream.h>
#include <conio.h>
#include <string.h>

struct department {
	char name[20];
	double budget, areas[5];
};

void print(int x, int y, char word[]) {
	gotoxy(x, y);
	cout << word;
}

void printd(int x, int y, double number) {
	gotoxy(x, y);
	cout << number;
}

int main() {
	clrscr();
	_setcursortype(_NOCURSOR);
	department dep[6];
	char area_name[5][40];
	strcpy(area_name[0], "Maintenance");
	strcpy(area_name[1], "Travel");
	strcpy(area_name[2], "Seminar/Training");
	strcpy(area_name[3], "Office Supply");
	strcpy(area_name[4], "Contingency");
	strcpy(dep[0].name, "Dean's");
	strcpy(dep[1].name, "Civil");
	strcpy(dep[2].name, "Mechanical");
	strcpy(dep[3].name, "Electrical");
	strcpy(dep[4].name, "Computer");
	strcpy(dep[5].name, "Electronics");
	int x;
	double annual;
	cout << "Enter annual budget [2M - 3M]: ";
	cin >> annual;
	dep[0].budget = annual * 0.2;
	for (x = 1; x < 6; x++) {
		dep[x].budget = (annual * 0.8) / 5;
	}

	for (x = 0; x < 6; x++) {
		dep[x].areas[0] = dep[x].budget * 0.3;
		dep[x].areas[1] = dep[x].budget * 0.25;
		dep[x].areas[2] = dep[x].budget * 0.15;
		dep[x].areas[3] = dep[x].budget * 0.1;
		dep[x].areas[4] = dep[x].budget * 0.2;
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
				print(43, 2, "AREA");
				print(3,3, "DEPARTMENT");
				print(20, 3, "MAINT/REP");
				print(31, 3, "TRAVEL");
				print(40, 3, "SEM/TRAIN");
				print(52, 3, "OFFICE SUPP");
				print(66, 3, "CONTINGENCY");
				int row = 5;
				for (x = 0; x < 6; x++) {
					print(3, row + x, dep[x].name);
					printd(20, row + x, dep[x].areas[0]);
					printd(31, row + x, dep[x].areas[1]);
					printd(40, row + x, dep[x].areas[2]);
					printd(52, row + x, dep[x].areas[3]);
					printd(66, row + x, dep[x].areas[4]);
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
									print(3, 3, "AREA");
									print(32, 3, "AMOUNT");
									gotoxy(1, 5);
									cout << "Maintenance/Repair" << endl
										 << "Travel" << endl
										 << "Seminar/Training" << endl
										 << "Office Supplies" << endl
										 << "Contigency";
									printd(32, 5, dep[ind].areas[0]);
									printd(32, 6, dep[ind].areas[1]);
									printd(32, 7, dep[ind].areas[2]);
									printd(32, 8, dep[ind].areas[3]);
									printd(32, 9, dep[ind].areas[4]);
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
										if (int(rep) > 48 && int(rep) < 54) {
											cout << area_name[int(rep) - 49] << " Deduction" << endl
												 << "How much do you want to deduct: " ;
											cin >> temp;
											if (temp > dep[ind].areas[int(rep) - 49]) {
												clrscr();
												cout << "Insufficent fund in " << area_name[int(rep) - 49] << " Area";
											}
											else {
												clrscr();
												dep[ind].areas[int(rep) - 49] -= temp;
												cout << "Succesfully deducted " << temp << " from the " << area_name[int(rep) - 49] << " Area";
											}
											getch();
										}
										else if (int(rep) == 54) {
											area = 0;
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
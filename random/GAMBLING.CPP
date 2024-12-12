#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include "HORSEGAM.CPP"

int main() {
	int running = 1;
	double money = 1000;
	char choice, gamble_choice, again;
	int gambling, delays;
	// horse
	int turn1, turn2, turn3, horse_bet, win_horse, horse_money;
	// beg
	int beg_chance = 5, beg_gained;
	// slot machine
	int slot_money, q;
	// roulette
	int r_rate, r_bet, r_money, r_choice, r_win;
	srand(time(0));
	do {
		if (money <= 0 && beg_chance <= 0) {
			clrscr();
			cout << "YOU'VE GONE BANKRUPT!!!" << endl
				 << "WOMP WOMP";
			getch();
			break;
		}
		clrscr();
		cout << "Money: $" << money << endl
			 << "What do you want to do?" << endl
			 << "[1] Gamble" << endl
			 << "[2] Beg" << endl
			 << "[3] Exit";
		choice = getch();
		switch (choice) {
			case '1':
				gambling = 1;
				while (gambling == 1) {
					if (money <= 0) {
						break;
					}
					clrscr();
					cout << "Money: $" << money << endl
						 << "LETS GO GAMBLING!!!" << endl
						 << "[1] Slot Machine" << endl
						 << "[2] Roulette" << endl
						 << "[3] Horse racing" << endl
						 << "[4] Exit";
					gamble_choice = getch();
					switch (gamble_choice) {
						case '1':
							do {
								if (money <= 0) {
									break;
								}
								int n1, n2, n3;
								do {
									clrscr();
									cout << "Money: $" << money << endl
										 << "HOW MUCH MONEY DO YOU WANT TO BET: ";
									cin >> slot_money;
								} while (slot_money <= 0 || slot_money > money);
								for (int x = 1; x <= 30; x++) {
									clrscr();
									n1 = (rand() % 3) + 1;
									n2 = (rand() % 3) + 1;
									n3 = (rand() % 3) + 1;
									cout << "---------\n"
										 << "[" << n1 << "][" << n2 << "][" << n3 << "]"
										 << "\n---------";
									delay(10);
								}
								for (x = 1; x <= 40; x++) {
									clrscr();
									n2 = (rand() % 3) + 1;
									n3 = (rand() % 3) + 1;
									cout << "---------\n"
										 << "[" << n1 << "][" << n2 << "][" << n3 << "]"
										 << "\n---------";
									delay(10);
								}
								if (n1 == n2) {
									delays = 90;
								}
								else {
									delays = 50;
								}
								for (q = 10, x = 1; x <= delays; x++, q++) {
									clrscr();
									n3 = (rand() % 3) + 1;
									cout << "---------\n"
										 << "[" << n1 << "][" << n2 << "][" << n3 << "]"
										 << "\n---------\n";
									delay(q);
								}
								if (n1 == n2 && n2 == n3) {
									cout << "JACKPOT!!!" << endl
										 << "YOU WIN $" << slot_money * 5;
									money += slot_money * 5;
								}
								else {
									cout << "YOU LOSE $" << slot_money;
									money -= slot_money;
								}
								cout << "\nMoney: $" << money << endl
									 << "Press space to go again";
								again = getch();
							} while (again == ' ');
							break;
						case '2':
							do {
								if (money <= 0) {
									break;
								}
								clrscr();
								cout << "Money: $" << money << endl
									 << "Choose the odds:" << endl
									 << "[1] Straight bet (35:1)" << endl
									 << "[2] Split bet (17:1)" << endl
									 << "[3] Street bet (11:1)" << endl
									 << "[4] Corner bet (8:1)" << endl
									 << ">>> ";
								cin >> r_choice;
								if (r_choice == 1) {
									r_rate = 35;
								}
								else if (r_choice == 2) {
									r_rate = 17;
								}
								else if (r_choice == 3) {
									r_rate = 11;
								}
								else if (r_choice == 4) {
									r_rate = 8;
								}
								else {
									break;
								}
								do {
									clrscr();
									cout << "Money: $" << money << endl
										 << "BET MONEY: ";
									cin >> r_money;
								} while (r_money <= 0 || r_money > money);
								cout << "BET A NUMBER BETWEEN 1-" << r_rate << ": ";
								cin >> r_bet;
								for (int i = 1, d = 30; i <= 30; i++, d += 10) {
									clrscr();
									r_win = (rand() % r_rate) + 1;
									cout << "[" << r_win << "]";
									delay(d);
								}
								if (r_win == r_bet) {
									cout << "\nYOU WIN $" << r_money * r_rate;
									money += r_money * r_rate;
								}
								else {
									cout << "\nYOU LOSE $" << r_money;
									money -= r_money;
								}
								cout << "\nMoney: $" << money << endl
									 << "Press space to go again";
								again = getch();
							} while (again == ' ');
							break;
						case '3':
							do {
								if (money <= 0) {
									break;
								}
								do {
									clrscr();
									cout << "Money: $" << money << endl
										 << "CHOOSE A HORSE TO BET:\n|-[1]-|-[2]-|-[3]-|: ";
									cin >> horse_bet;
								} while (horse_bet < 1 || horse_bet > 3);
								do {
									clrscr();
									cout << "Money: $" << money << endl
										 << "HOW MUCH MONEY DO YOU WANT TO BET: ";
									cin >> horse_money;
								} while (horse_money <= 0 || horse_money > money);
								horse(turn1, turn2, turn3);
								if (turn1 == 0 && horse_bet == 1) {
									cout << "\nYOU WON $" << horse_money * 2;
									money += horse_money * 2;
								}
								else if (turn2 == 0 && horse_bet == 2) {
									cout << "\nYOU WON $" << horse_money * 2;
									money += horse_money * 2;
								}
								else if (turn3 == 0 && horse_bet == 3) {
									cout << "\nYOU WON $" << horse_money * 2;
									money += horse_money * 2;
								}
								else {
									cout << "\nYOU LOST $" << horse_money;
									money -= horse_money;
								}
								cout << "\nMoney: $" << money << endl
									 << "Press space to go again";
								again = getch();
								} while (again == ' ');
								break;
						case '4':
							gambling = 0;
							break;
					}
				}
				break;
			case '2':
				if (beg_chance > 0) {
					clrscr();
					beg_gained = rand() % 500 + 100;
					cout << "You managed to beg for $" << beg_gained;
					money += beg_gained;
					beg_chance--;
					getch();
				}
				else {
					clrscr();
					cout << "You cannot beg anymore";
					getch();
				}
				break;
			case '3':
				cout << "3";
				running = 0;
				break;
			default:
				cout << "Error";
		}
	} while (running == 1);
	return 0;
}
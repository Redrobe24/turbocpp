#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void print(int x, int y, char bruh[]) {
	gotoxy(x, y);
	cout << bruh;
}

void draw(int x, int y, int num, int suit) {
	gotoxy(x,y);
	cout << "ÉÍÍÍ»";
	char face[3] = {'J', 'Q', 'K'};
	gotoxy(x, y + 1);
	if (num > 10) {
		cout << "º " << face[num - 11] << char(suit) << "º";
	}
	else if (num == 10) {
		cout << "º" << num << char(suit) << "º";
	}
	else if (num == 1) {
		cout << "º A" << char(suit) << "º";
	}
	else {
		cout << "º " << num << char(suit) << "º";
	}
	gotoxy(x, y + 2);
	cout << "ÈÍÍÍ¼";
}

struct card {
	int number[13];
	int suits;
};

int main() {
	int x, y;
	srand(time(NULL));
	_setcursortype(_NOCURSOR);
	card hands[8], deck[4], temp, played[5];
	int high_score = 0;
	char rep;
	do {
		int no_cards = 52;
		for (x = 0; x < 4; x++) {
			for (int y = 0; y < 13; y++) {
				deck[x].number[y] = y + 1;
			}
		}
		deck[0].suits = 3;
		deck[1].suits = 4;
		deck[2].suits = 5;
		deck[3].suits = 6;
		int running = 1;
		int score = 0;

		// randomize
		int pick_num;
		int pick_suit;
		for (x = 0; x < 8; x++) {
			do {
				pick_num = rand() % 13;
				pick_suit = rand() % 4;
			} while (deck[pick_suit].number[pick_num] == 0);
			hands[x].number[0] = deck[pick_suit].number[pick_num];
			hands[x].suits = deck[pick_suit].suits;
			deck[pick_suit].number[pick_num] = 0;
			no_cards--;
		}
		// sort by num
		for (x = 0; x < 7; x++) {
			for (y = 0; y < 7; y++) {
				if (hands[y].number[0] < hands[y + 1].number[0]) {
					temp = hands[y];
					hands[y] = hands[y + 1];
					hands[y + 1] = temp;
				}
			}
		}
		int selected[8] = {0, 0, 0, 0, 0, 0, 0, 0};
		int select = 0;
		int no_select = 0;
		int sort_stat = 1;

		while (running) {
			// menu
			clrscr();
			print(30, 2, "POKER BALATRO STYLE");
			gotoxy(5, 3);
			cout << "High score: " << high_score;
			gotoxy(5, 4);
			cout << "Score: " << score;
			gotoxy(5, 5);
			cout << "Cards left: " << no_cards;
			print(5, 6, "Press 'C' for Controls");
			// draw the hands
			int column = 13;
			for (x = 0, y = 0; x < 8; x++, y += 7) {
				draw(column + y, 8, hands[x].number[0], hands[x].suits);
				gotoxy(column + y + 1, 11);
				cout << "[" << char(selected[x]) << "]";
			}
			gotoxy(15 + select * 7, 12);
			cout << char(30);

			rep = tolower(getch());
			switch (rep) {
				case 'q':
					running = 0;
					break;
				case 'r':
					for (x = 0; x < 4; x++) {
						for (int y = 0; y < 13; y++) {
							deck[x].number[y] = y + 1;
						}
					}
					no_cards = 52;
					for (x = 0; x < 8; x++) {
						do {
							pick_num = rand() % 13;
							pick_suit = rand() % 4;
						} while (deck[pick_suit].number[pick_num] == 0);
						hands[x].number[0] = deck[pick_suit].number[pick_num];
						hands[x].suits = deck[pick_suit].suits;
						deck[pick_suit].number[pick_num] = 0;
						no_cards--;
					}
					for (x = 0; x < 7; x++) {
						for (y = 0; y < 7; y++) {
							if (hands[y].number[0] < hands[y + 1].number[0]) {
								temp = hands[y];
								hands[y] = hands[y + 1];
								hands[y + 1] = temp;
							}
						}
					}
					score = 0;
					break;
				case 'c':
					// controls
					clrscr();
					print(30, 5, "CONTROLS");
					print(25, 8, "Q: Quit");
					print(25, 9, "S: Sort by rank/suit");
					print(25, 10, "A/D: Move left/right to select card");
					print(25, 11, "Space: Select card");
					print(25, 12, "P: To play selected cards");
					print(25, 13, "O: Discard selected cards");
					print(25, 14, "R: Reset deck, cards, and score");
					print(25, 15, "H: Show pokers hands and their score");
					print(25, 17, "Press anything to continue");
					getch();
					break;
				case 'h':
					clrscr();
					print(32, 3, "POKER HANDS");
					print(25, 6, "HIGH CARD: 50");
					print(25, 7, "PAIR: 100");
					print(25, 8, "TWO PAIR: 200");
					print(25, 9, "THREE OF A KIND: 300");
					print(25, 10, "STRAIGHT: 300");
					print(25, 11, "FLUSH: 350");
					print(25, 12, "FULL HOUSE: 400");
					print(25, 13, "FOUR OF A KIND: 600");
					print(25, 14, "STRAIGHT FLUSH: 1000");
					print(3, 17, "!!! DON'T SELECT UNNECESSARY CARDS OR THE POKER HAND WILL BE A HIGH CARD !!!");
					getch();
					break;
				case 'a':
					if (select != 0) select--;
					break;
				case 'd':
					if (select != 7) select++;
					break;
				case ' ':
					if (select >= 0 && select < 8) {
						if (selected[select] == 0 && no_select < 5) {
							selected[select] = 47;
							no_select++;
						}
						else if (selected[select] == 47) {
							selected[select] = 0;
							no_select--;
						}
					}
					break;
				case 's':
					if (sort_stat == 1) {
						for (x = 0; x < 7; x++) {
							for (y = 0; y < 7; y++) {
								if (hands[y].suits < hands[y + 1].suits) {
									temp = hands[y];
									hands[y] = hands[y + 1];
									hands[y + 1] = temp;
									selected[y] = selected[y] + selected[y + 1];
									selected[y + 1] = selected[y] - selected[y + 1];
									selected[y] = selected[y] - selected[y + 1];
								}
							}
						}
						sort_stat = 0;
					}
					else if (sort_stat == 0) {
						for (x = 0; x < 7; x++) {
							for (y = 0; y < 7; y++) {
								if (hands[y].number[0] < hands[y + 1].number[0]) {
									temp = hands[y];
									hands[y] = hands[y + 1];
									hands[y + 1] = temp;
									selected[y] = selected[y] + selected[y + 1];
									selected[y + 1] = selected[y] - selected[y + 1];
									selected[y] = selected[y] - selected[y + 1];
								}
							}
						}
						sort_stat = 1;
					}
					break;
				case 'o':
					if (no_select == 0) {
						break;
					}
					int index[5];
					int found = 0;
					for (x = 0; x < 8; x++) {
						if (selected[x] == 47) {
							index[found] = x;
							found++;
						}
					}
					// IMPORTANTTTT
					for (x = 0; x < found; x++) {
						do {
							pick_num = rand() % 13;
							pick_suit = rand() % 4;
						} while (deck[pick_suit].number[pick_num] == 0);
						hands[index[x]].number[0] = deck[pick_suit].number[pick_num];
						hands[index[x]].suits = deck[pick_suit].suits;
						deck[pick_suit].number[pick_num] = 0;
						no_cards--;
					}
					// IMPORTANTTTTT
					for (x = 0; x < 8; x++) {
						selected[x] = 0;
					}
					no_select = 0;
					// IMPORTANTTTTT
					for (x = 0; x < 7; x++) {
						for (y = 0; y < 7; y++) {
							if (hands[y].number[0] < hands[y + 1].number[0]) {
								temp = hands[y];
								hands[y] = hands[y + 1];
								hands[y + 1] = temp;
							}
						}
					}
					sort_stat = 1;
					break;
				case 'p':
					// get index
					if (no_select == 0) {
						break;
					}
					index[5];
					found = 0;
					for (x = 0; x < 8; x++) {
						if (selected[x] == 47) {
							index[found] = x;
							found++;
						}
					}
					for (x = 0; x < found; x++) {
						played[x].number[0] = hands[index[x]].number[0];
						played[x].suits = hands[index[x]].suits;
					}
					for (x = 0; x < found - 1; x++) {
						for (y = 0; y < found - 1; y++) {
							if (played[y].number[0] < played[y + 1].number[0]) {
								temp = played[y];
								played[y] = played[y + 1];
								played[y + 1] = temp;
								index[y] = index[y] + index[y + 1];
								index[y + 1] = index[y] - index[y + 1];
								index[y] = index[y] - index[y + 1];
							}
						}
					}
					clrscr();
					gotoxy(33, 8);
					// check straight flush
					if (found == 5) {
						if (played[0].number[0] == (played[1].number[0] + 1) && (played[1].number[0] + 1) == (played[2].number[0] + 2) && (played[2].number[0] + 2) == (played[3].number[0] + 3) && (played[3].number[0] + 3) == (played[4].number[0] + 4)) {
							if (played[0].suits == played[1].suits && played[1].suits == played[2].suits && played[2].suits == played[3].suits && played[3].suits == played[4].suits) {
								cout << "STRAIGHT FLUSH";
								score += 1000;
							}
							else {
								cout << "STRAIGHT" << endl;
								score += 300;
							}
						}
						else if (played[0].number[0] == played[1].number[0] && played[3].number[0] == played[4].number[0]) {
							if (played[2].number[0] == played[1].number[0] || played[2].number[0] == played[3].number[0]) {
								cout << "FULL HOUSE";
								score += 400;
							}
						}
						else if (played[0].suits == played[1].suits && played[1].suits == played[2].suits && played[2].suits == played[3].suits && played[3].suits == played[4].suits) {
							cout << "FLUSH";
							score += 350;
						}
						else {
							cout << "HIGH CARD";
							score += 50;
						}
					}
					else if (found == 4) {
						if (played[0].number[0] == played[1].number[0] && played[1].number[0] == played[2].number[0] && played[2].number[0] == played[3].number[0]) {
							cout << "FOUR OF A KIND";
							score += 600;
						}
						else if (played[0].number[0] == played[1].number[0] && played[2].number[0] == played[3].number[0]) {
							cout << "TWO PAIR";
							score += 200;
						}
						else {
							cout << "HIGH CARD";
							score += 50;
						}
					}
					else if (found == 3) {
						if (played[0].number[0] == played[1].number[0] && played[1].number[0] == played[2].number[0]) {
							cout << "THREE OF A KIND";
							score += 300;
						}
						else {
							cout << "HIGH CARD";
							score += 50;
						}
					}
					else if (found == 2) {
						if (played[0].number[0] == played[1].number[0]) {
							cout << "PAIR";
							score += 100;
						}
						else {
							cout << "HIGH CARD";
							score += 50;
						}
					}
					else {
						cout << "HIGH CARD";
						score += 50;
					}
					/* debugging
					for (x = 0; x < found; x++) {
						cout << played[x].number[0] << char(played[x].suits) << ", " << index[x] << endl;
					}
					*/
					getch();
					// IMPORTANTTTT
					for (x = 0; x < found; x++) {
						do {
							pick_num = rand() % 13;
							pick_suit = rand() % 4;
						} while (deck[pick_suit].number[pick_num] == 0);
						hands[index[x]].number[0] = deck[pick_suit].number[pick_num];
						hands[index[x]].suits = deck[pick_suit].suits;
						deck[pick_suit].number[pick_num] = 0;
						no_cards--;
					}
					// IMPORTANTTTTT
					for (x = 0; x < 8; x++) {
						selected[x] = 0;
					}
					no_select = 0;
					for (x = 0; x < 7; x++) {
						for (y = 0; y < 7; y++) {
							if (hands[y].number[0] < hands[y + 1].number[0]) {
								temp = hands[y];
								hands[y] = hands[y + 1];
								hands[y + 1] = temp;
							}
						}
					}
					sort_stat = 1;
					break;
			}
			if (no_cards <= 4) {
				running = 0;
			}
		}
		if (score > high_score) {
			high_score = score;
		}
		clrscr();
		gotoxy(30, 9);
		cout << "High score: " << high_score;
		gotoxy(30, 10);
		cout << "Your score: " << score;
		print(30, 11, "Press 'Y' to play again");
		rep = tolower(getch());
	} while (rep == 'y');
	return 0;
}
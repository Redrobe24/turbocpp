#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <dos.h>

int main() {
	clrscr();
	int rep, x_pos, y_pos, x_apple, y_apple, pre_x, pre_y;
	const int h = 10;
	const int w = 10;
	char board[h][w];
	char snake[h*w];
	do {
		srand(time(NULL));
		// board
		for (int i = 0; i <= h; i++) {
			for (int j = 0; j <= w; j++) {
				board[i][j] = ' ';
			}
		}
		do {
			x_pos = rand() % h;
			y_pos = rand() % w;
			x_apple = rand() % h;
			y_apple = rand() % w;
		} while (x_pos == x_apple || y_pos == y_apple);
		int running = 1;
		int points = 0;
		int dir = rand() % 4; // 0 = up, 1 = down , 2 = left, 3 = right
		while (running) {
			clrscr();
			// movement
			switch (dir) {
				case 0:          //up
					if (x_pos >= 0 && x_pos < h) {
						board[x_pos][pre_y] = ' ';
						pre_x = x_pos;
						pre_y = y_pos;
						for (int i = 0; i <= points; i++) {
							board[x_pos + i][y_pos] = ' ';
						}
						board[pre_x][y_pos] = ' ';
						x_pos -= 1;
						switch (x_pos) {
							case -1:
								x_pos = h-1;
								break;
							case h:
								x_pos = 0	;
								break;
						}
					}
					break;
				case 1:        //down
					if (x_pos >= 0 && x_pos <= h) {
						board[x_pos][pre_y] = ' ';
						pre_x = x_pos;
						pre_y = y_pos;
						for (int i = 0; i <= points; i++) {
							board[x_pos - i][y_pos] = ' ';
						}
						board[pre_x][y_pos] = ' ';
						x_pos += 1;
						switch (x_pos) {
							case -1:
								x_pos = h-1;
								break;
							case h:
								x_pos = 0;
								break;
						}
					}
					break;
				case 2:          //left
					if (y_pos >= 0 && y_pos < w) {
						board[pre_x][y_pos] = ' ';
						pre_x = x_pos;
						pre_y = y_pos;
						for (int i = 0; i <= points; i++) {
							board[x_pos][y_pos + 1] = ' ';
						}
						board[x_pos][pre_y] = ' ';
						y_pos -= 1;
						switch (y_pos) {
							case -1:
								y_pos = w-1;
								break;
							case w:
								y_pos = 0;
								break;
						}
					}
					break;
				case 3:          //right
					if (y_pos >= 0 && y_pos <= w) {
						board[pre_x][y_pos] = ' ';
						pre_x = x_pos;
						pre_y = y_pos;
						for (int i = 0; i < points; i++) {
							board[x_pos][y_pos - i] = 'B';
						}
						board[x_pos][pre_y] = ' ';
						y_pos += 1;
						switch (y_pos) {
							case -1:
								y_pos = w-1;
								break;
							case w:
								y_pos = 0;
								break;
						}
					}
					break;
				default:
					continue;
			}
			// apple collision
			if (x_pos == x_apple && y_pos == y_apple) {
				do{
					x_apple = rand() % h;
					y_apple = rand() % w;
				} while (x_pos == x_apple || y_pos == y_apple);
				points += 1;
				snake[points] = '#';
			}
			//display
			cout << "POS: " << x_pos << y_pos << endl << "PREPOS: " << pre_x << pre_y << endl;
			cout << "Points: " << points << endl;
			board[x_pos][y_pos] = '#';
			if (points > 0) {
				board[pre_x][pre_y] = 'A';
			}
			board[x_apple][y_apple] = '@';
			for (int x = 0; x < h; x++) {
				for (int y = 0; y < w; y++) {
					cout << board[x][y] << ' ';
				}
				cout << endl;
			}
			//input
		 //	if (kbhit()) {
			switch (tolower(getch())) {
				case 'q':
					running = 0;
					break;
				case 'w':
					dir = 0;
					break;
				case 'a':
					dir = 2;
					break;
				case 's':
					dir = 1;
					break;
				case 'd':
					dir = 3;
					break;
				default:
					continue;
			}
		  //	}
			//check if win
			if (points == 10) {
				running = 0;
				clrscr();
				cout << "\nYou win";
				break;
			}
			delay(150);
		}
		cout << "\nPlay Again[Y][N]?";
		rep = tolower(getch());
	}
	while (rep == 'y');

	return 0;
}
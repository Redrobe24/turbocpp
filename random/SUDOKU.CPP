#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>

int grid[9][9];

int possible(int row, int column, int num) {
	int bool = 1;
	int x0, y0;
	for (int i = 0; i < 9; i++) {
		if (grid[row][i] == num) {
			bool = 0;
		}
	}
	for (i = 0; i < 9; i++) {
		if (grid[i][column] == num) {
			bool = 0;
		}
	}
	x0 = (floor(column / 3)) * 3;
	y0 = (floor(row / 3)) * 3;
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[y0 + i][x0 + j] == num) {
				bool = 0;
			}
		}
	}
	return bool;
}

int solver() {
	for (int row = 0; row < 9; row++) {
		for (int column = 0; column < 9; column++) {
			if (grid[row][column] == 0) {
				for (int num = 1; num < 10; num++) {
					if (possible(row, column, num)) {
						grid[row][column] = num;
						if (solver()) {
							return 1;
						}
						grid[row][column] = 0;
					}
				}
				return 0;
			}
		}
	}
}

int main() {
	clrscr();
	int running = 1;
	int try;
	// grid

	for (int x = 0; x < 9; x++) {
		for (int y = 0; y < 9; y++) {
			grid[x][y] = 0;
		}
	 }
	char input;
	int p_x = 0, p_y = 0;
	// loop
	while (running) {
		clrscr();
		// draw grid
		for (int z = 0; z < 9 * 2; z++) {
			cout << " -";
		}
		cout << "\t\t ---- SUDOKU SOLVER ----" << endl;
		for (x = 0; x < 9; x++) {
			cout << "| ";
			for (int y = 0; y < 9; y++) {
				if (p_x == x && p_y == y) {
					cout << "#" << " | ";
				}
				else {
					if (grid[x][y] == 0) {
						cout << "  | ";
					}
					else {
						cout << grid[x][y] << " | ";
					}
				}
				if (y == 8 && x == 0) {
					if (p_y == 9) {
						cout << "\t\t> SOLVE\t\t  RESET";
					}
					else if (p_y == 10) {
						cout << "\t\t  SOLVE\t\t> RESET";
					}
					else {
						cout << "\t\t  SOLVE\t\t  RESET";
					}
				}
				if (y == 8 && x == 1) {
					cout << "\t\t  INPUT: 1-9";
				}
				if (y == 8 && x == 2) {
				cout << "\t\t  SELECTED: #";
			}
			}
			cout << endl;
			for (int z = 0; z < 9 * 2; z++) {
				cout << " -";
			}
			if (x == 1) {
				cout << "\t\t  ERASE: 0";
			}
			if (x == 2) {
				cout << "\t\t  QUIT: Q";\
			}
			cout << endl;
		}
		// player input
		if (kbhit) {
			input = tolower(getch());
			if (int(input) >= 48 && int(input) <= 57) {
				grid[p_x][p_y] = input - '0';
				continue;
			}
			switch (input) {
				case 'w':
					if (!(p_x == 0)) p_x--;
					break;
				case 'a':
					if (!(p_y == 0)) p_y--;
					break;
				case 's':
					if (!(p_x == 8)) p_x++;
					break;
				case 'd':
					if (p_y == 8) p_x = 0;
					if (!(p_y == 10)) p_y++;
					break;
				case ' ':
					if (p_y == 9) {
						solver();
					}
					if(p_y == 10) {
						for (int x = 0; x < 9; x++) {
							for (int y = 0; y < 9; y++) {
								grid[x][y] = 0;
							}
						 }
					}
					break;
				case 'q':
					running = 0;
					break;
			}
		}
	}
	return 0;
}

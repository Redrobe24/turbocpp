#include <iostream.h>
#include <conio.h>
#include <ctype.h>

int main() {
	clrscr();
	int running = 1;
	int solve = 0;
	int try;
	// grid
	const size_x = 9, size_y = 9;
	int num[size_x][size_y];
	char grid[size_x][size_y];
	for (int x = 0; x < size_x; x++) {
		for (int y = 0; y < size_y; y++) {
			num[x][y] = 0;
		}
	 }
	char input;
	int p_x = 0, p_y = 0;
	// loop
	while (running) {
		clrscr();
		// convert int grid to char grid
		for (int x = 0; x < size_x; x++) {
			for (int y = 0; y < size_y; y++) {
				if (num[x][y] == 0) {
					grid[x][y] = ' ';
				}
				else {
					grid[x][y] = num[x][y] + '0';
				}
			}
		}
		// draw grid
		for (int z = 0; z < size_x * 2; z++) {
			cout << " -";
		}
		cout << "\t\t ---- SUDOKU SOLVER ----" << endl;
		for (x = 0; x < size_x; x++) {
			cout << "| ";
			for (int y = 0; y < size_y; y++) {
				if (p_x == x && p_y == y) {
					cout << "#" << " | ";
				}
				else {
					cout << grid[x][y] << " | ";
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
			for (int z = 0; z < size_x * 2; z++) {
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
				num[p_x][p_y] = input - '0';
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
						solve = 1;
					}
					if(p_y == 10) {
						for (int x = 0; x < size_x; x++) {
							for (int y = 0; y < size_y; y++) {
								num[x][y] = 0;
							}
						 }
					}
					break;
				case 'q':
					running = 0;
					break;
			}
		}
		// solving
		while (solve) {
			for (int check_x = 0; check_x < size_x; check_x++) {
				for (int check_y = 0; check_y < size_y; check_y++) {
					try = 1;
					if (num[check_x][check_y] == 0) {
						for (int row = 0; row < size_y; row++) {
							if (num[check_x][check_y] == num[row][check_y]) {
								try++;
							}
							else {
								num[check_x][check_y] = try;
							}
						}
						try = 1;
						for (int column = 0; column < size_x; column++) {
							if (num[check_x][check_y] == num[check_x][column]) {
								try++;
							}
							else {
								num[check_x][check_y] = try;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

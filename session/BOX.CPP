#include <iostream.h>
#include <conio.h>

int main() {
	clrscr();
	char rep;
	int grid_size = 20;
	int x_pos = 3, y_pos = 3;
	int xbox = 5, ybox = 5;
	int xwin = 9, ywin = 9;
	int running = 1;
	_setcursortype(_NOCURSOR);
	while (running) {
		clrscr();
		for (int x = 1; x <= grid_size; x++) {
			for (int y = 1; y <= grid_size; y++) {
				if (x == 1 || x == grid_size) {
					cout << "# ";
				}
				else if (y == 1 || y == grid_size) {
					cout << "# ";
				}
				else if (x_pos == y && y_pos == x) {
					cout << "P ";
				}
				else if (xwin == y && ywin == x) {
					cout << "W ";
				}
				else if (xbox == y && ybox == x) {
					cout << "B ";
				}
				else {
					cout << "  ";
				}
			}
			cout << endl;
		}
		rep = getch();
		switch (rep) {
			case 'w':
				if (y_pos != 2) y_pos--;
				if (ybox == y_pos && ybox != 2 && xbox == x_pos) ybox--;
				if (ybox == y_pos && xbox == x_pos) y_pos++;
				break;
			case 'a':
				if (x_pos != 2) x_pos--;
				if (xbox == x_pos && xbox != 2 && ybox == y_pos) xbox--;
				if (ybox == y_pos && xbox == x_pos) x_pos++;
				break;
			case 's':
				if (y_pos != grid_size - 1) y_pos++;
				if (ybox == y_pos && ybox != grid_size - 1 && xbox == x_pos) ybox++;
				if (ybox == y_pos && xbox == x_pos) y_pos--;
				break;
			case 'd':
				if (x_pos != grid_size - 1) x_pos++;
				if (xbox == x_pos && xbox != grid_size - 1 && ybox == y_pos) xbox++;
				if (ybox == y_pos && xbox == x_pos) x_pos--;
				break;
			case 'q':
				running = 0;
				break;
		}
		if (xbox == xwin && ybox == ywin) {
			clrscr();
			gotoxy(37, 11);
			cout << "WIN!";
			getch();
			running = 0;
			break;
		}
	}
	return 0;
}
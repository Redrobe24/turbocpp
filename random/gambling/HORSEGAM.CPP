#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

void horse(int& a, int& b, int& c) {
	srand(time(0));
	a = 20;
	b = 20;
	c = 20;
	int turn;
	while (1) {
		clrscr();
		turn = (rand() % 3) + 1;
		cout << "||";
		for (int x = a; x >= 1; x--) {
			cout << " ";
		}
		cout << "7==," << endl;
		cout << "||";
		for (x = b; x >= 1; x--) {
			cout << " ";
		}
		cout << "7==," << endl;
		cout << "||";
		for (x = c; x >= 1; x--) {
			cout << " ";
		}
		cout << "7==," << endl;
		delay(250);
		if (turn == 1) {
			a--;
		}
		else if(turn == 2) {
			b--;
		}
		else {
			c--;
		}
		if (a == 0 || b == 0 || c == 0) {
			break;
		}
	}
}


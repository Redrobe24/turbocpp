#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

int main() {
	srand(time(NULL));
	char rep;
	int dice[6] = {1, 2, 3, 4, 5, 6}, running, choice, time, hit;
	do {
		clrscr();
		running = 1;
		hit = 0;
		time = 10;
		while (running) {
			for (int x = 0; x < 6; x++) {
				dice[x]++;
				if (dice[x] == 7) {
					dice[x] = 1;
				}
			}
			clrscr();
			cout << "DICE ROLLER" << endl;
			cout << "=================" << endl;
			textcolor(8);
			cprintf("%d - ",dice[0]);
			textcolor(7);
			cprintf("%d - ", dice[1]);
			textcolor(15);
			cprintf("%d", dice[2]);
			textcolor(7);
			cprintf(" - %d",dice[3]);
			textcolor(8);
			cprintf(" - %d",dice[4]);
			textcolor(15);
			cout << endl << "=================" << endl;
			if (hit == 0) cout << "PRESS SPACE TO STOP" << endl;
			else cout << "SPACE PRESSED!" << endl;
			delay(50);
			// 2nd
			clrscr();
			cout << "DICE ROLLER" << endl;
			cout << "=================" << endl;
			textcolor(8);
			cprintf(" - %d",dice[0]);            1 - 2 - 3 - 4 - 5
			textcolor(7);                        - 2 - 3 - 4 - 5
			cprintf(" - %df", dice[1]);          - 2 - 3 - 4 - 5 -
			textcolor(15);                       2 - 3 - 4 - 5 -
			cprintf("%d", dice[2]);             2 - 3 - 4 - 5 - 6
			textcolor(7);
			cprintf(" - %d",dice[3]);
			textcolor(8);
			cprintf(" - %d",dice[4]);
			textcolor(15);
			cout << endl << "=================" << endl;
			if (hit == 0) cout << "PRESS SPACE TO STOP" << endl;
			else cout << "SPACE PRESSED!" << endl;
			delay(time);
			if (kbhit()) {
				if (getch() == ' ') {
					hit = 1;
				}
			}
			if (time >= 300) {
				running = 0;
				break;
			}
			if (hit) {
				if (time < 300) time += 5;
				else if (time < 400) time += 4;
				else if (time < 300) time += 3;
				else if (time < 200) time += 2;
				else time+= 1;
			}
		}
		choice = dice[2];
		cout << "\nRESULT: " << choice << endl
			 << "PRESS SPACE TO GO AGAIN";
		rep = getch();
		} while (rep == ' ');
	return 0;
}
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>

void sing(char line[], int sec, int str) {
	delay(str);
	for (int x = 0; x < strlen(line); x++) {
		if (line[x] != ' ') {
			cout << line[x];
		}
		else {
			delay(sec);
			cout << ' ';
		}
	}
}

void word(char word[], int sec) {
	for (int i = 0; i < strlen(word); i++) {
		cout << word[i];
		delay(sec);
	}
}

int main() {
	clrscr();
	sing("SECRETS I HAVE HELD IN MY HEART<3\n", 370, 200);
	sing("ARE HARDER TO HIDE THAN I THOUGHT\n", 380, 1300);
	sing("MAYBE I JUST WANNA BE YOURS\n", 360, 1300);
	sing("I WANNA BE YOURS\n", 300, 1300);
	sing("I WANNA BE", 320, 1200);
	word(" YOOOOUUURS", 120);
	getch();
	return 0;
}
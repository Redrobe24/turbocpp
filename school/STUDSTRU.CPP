#include <iostream.h>
#include <conio.h>
#include <string.h>

struct grade {
	char name[20], elg;
	double aq, me, fe, fg;
};

double final_calc(double a, double b, double c) {
	return a * 0.35 + b * 0.3 + c * 0.35;
}

void print(int x, int y, char word[99], double res) {
	gotoxy(x, y);
	if (strcmp(word, "0") != 0) cout << word;
	else cout << res;
}

char letter_grade(double final) {
	char letter;
	if (final >= 90) {
		letter = 'A';
	}
	else if (final >= 80) {
		letter = 'B';
	}
	else if (final >= 70) {
		letter = 'C';
	}
	else if (final >= 60) {
		letter = 'D';
	}
	else {
		letter = 'F';
	}
	return letter;
}

int main() {
	clrscr();
	int num;
	cout << "Enter no. Student: ";
	cin >> num;
	grade stud[99], temp;
	//input
	for (int x = 0; x < num; x++) {
		clrscr();
		cout << "Enter student " << x + 1 << " details:" << endl
			 << "Name: ";
		cin >> stud[x].name;
		cout << "Average quiz score: ";
		cin >> stud[x].aq;
		cout << "Midterm exam score: ";
		cin >> stud[x].me;
		cout << "Finalterm exam score: ";
		cin >> stud[x].fe;
		stud[x].fg = final_calc(stud[x].aq, stud[x].me, stud[x].fe);
		stud[x].elg = letter_grade(stud[x].fg);
	}
	//sorting
	for (x = 0; x < num; x++) {
		for (int y = 0; y < num - 1; y++) {
			if (strcmpi(stud[y].name, stud[y + 1].name) > 0) {
				temp = stud[y];
				stud[y] = stud[y + 1];
				stud[y + 1] = temp;
			}
		}
	}
	//find hs
	int hs_index = 0;
	for (x = 0; x < num; x++) {
		if (stud[x].fg > stud[hs_index].fg) {
			hs_index = x;
		}
	}
	_setcursortype(_NOCURSOR);
	//display
	clrscr();
	int row = 5;
	print(5, 3, "NAME", 0);
	print(22, 3, "AVE QUIZ", 0);
	print(34, 3, "MIDTERM", 0);
	print(45, 3, "FINALS", 0);
	print(55, 3, "AVE GRADE", 0);
	print(68, 3, "LETTER GRADE", 0);
	for (x = 0; x < num; x++) {
		gotoxy(1, row + x);
		cout << x + 1 << ". " << stud[x].name;
		print(23, row + x, "0", stud[x].aq);
		print(35, row + x, "0", stud[x].me);
		print(45, row + x, "0", stud[x].fe);
		print(56, row + x, "0", stud[x].fg);
		gotoxy(72, row + x);
		cout << "'" << stud[x].elg << "'";
	}
	gotoxy(1, row + x);
	cout << endl << "'" << stud[hs_index].name << "' has the highest grade of "
		 << stud[hs_index].fg << " with an equivalent letter grade of "
		 << stud[hs_index].elg;
	getch();
	return 0;
}
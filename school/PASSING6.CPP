#include <iostream.h>
#include <conio.h>

int main()
{
	clrscr();
	int Q1, Q2, Q3, MT, FT;
	double TAVE, QAVE;
	cout << "Quiz 1 score: ";
	cin >> Q1;
	cout << "Quiz 2 score: ";
	cin >> Q2;
	cout << "Quiz 3 score: ";
	cin >> Q3;
	cout << "Midterm score: ";
	cin >> MT;
	cout << "Finalterm score: ";
	cin >> FT;
	QAVE = ((Q1 + Q2 + Q3)/3)*10;
	TAVE = (QAVE * 0.25) + (MT * 0.25) + (FT * 0.5);
	if (TAVE >= 60)
	{
		cout << "You passed with your grade of: " << TAVE << "%";
	}
	else
		cout << "You failed with you grade of: " << TAVE << "%";
	getch();

	return 0;
}
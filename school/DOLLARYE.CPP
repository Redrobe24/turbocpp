#include <iostream.h>
#include <conio.h>

int main()
{
	clrscr();
	double UI, M, R, CM;
	cout << "What do you want to convert?"
		 << "\n(1) Yen to Dollar"
		 << "\n(2) Dollar to Yen"
		 << "\n> ";
	cin >> UI;
	if (UI == 1)
	{
		cout << "Enter money in Yen: ";
		cin >> M;
		cout << "Enter Yen to Dollar Rate: ";
		cin >> R;
		CM = M * R;
		cout << "Converted money in Dollar: " << CM;
	}
	if (UI == 2)
	{
		cout << "Enter money in Dollar: ";
		cin >> M;
		cout << "Enter Dollar to Yen Rate: ";
		cin >> R;
		CM = M * R;
		cout << "Converted money in Yen: " << CM;
	if (UI != 1 && UI != 2)
		{
			cout << "Error";
		}
	}
	getch();

	return 0;
}
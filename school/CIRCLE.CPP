#include <iostream.h>
#include <conio.h>

int main()
{
	clrscr();
	double I, R, D, C;
	cout << "Enter radius of the circle: ";
	cin >> R;
	cout << "What do you want to calculate for?" << endl
		 << "(1) Diameter" << endl
		 << "(2) Circumference" << endl
		 << "> ";
	cin >> I;
	if (I == 1)
	{
		D = R*2;
		cout << "The diamater of the circle is " << D;
	}
	if (I == 2)
	{
		C = R*2*3.14;
		cout << "The circumference of the circle is " << C;
	}
	getch();

	return 0;
}
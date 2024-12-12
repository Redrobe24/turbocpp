#include <iostream.h>
#include <conio.h>

int main()
{
	clrscr();
	double HW, HR, GP, OTP;
	cout << "Enter hours worked: ";
	cin >> HW;
	cout << "Enter hourly rate: ";
	cin >> HR;
	if (HW > 40)
	{
		OTP = (HW - 40) * HR * 0.5;
		GP = (40 * HR) + OTP;
	}
	else
		GP = HW * HR;
	cout << "The gross pay is: $" << GP;
	getch();

	return 0;
}
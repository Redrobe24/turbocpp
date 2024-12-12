#include <iostream.h>

int main()
{
	int x, run;
	run = 0;
	while(run <= 10)
	{
		run++;
		cout << "Enter an integer: ";
		cin >> x;
		if (x % 2 == 0)
		{
			if (x % 10 == 0)
			{
				cout << "The integer " << x << " is even and divisible by 10\n";
			}
			else
			{
				cout << "The integer " << x << " is even but not divisble by 10\n";
			}
		}
		else
		{
			cout << "The integer " << x << " is odd\n";
		}
	}

	return 0;
}
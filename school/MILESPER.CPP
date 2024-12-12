#include <iostream.h>

int main() {
	double miles, liter, gallon, mperg;
	cout << "Enter liter the car consumed: ";
	cin >> liter;
	cout << "Enter miles the car traveled: ";
	cin >> miles;
	gallon = liter * 0.264179;
	mperg = miles / gallon;
	cout << "The number of miles per gallon the car delivered is: " << mperg << endl;

	return 0 ;
}
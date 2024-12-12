#include <iostream.h>
#include <conio.h>
#include <math.h>

double calculate_s(double a, double b, double c);
double calculate_area(double a, double b, double c);
double diff(double parameter, double n);

int main() {
	clrscr();
	double a, b, c, area;
	cout << "Enter the three sides of the triangle: " << endl
		 << "First side: ";
	cin >> a;
	cout << "Second side: ";
	cin >> b;
	cout << "Third side: ";
	cin >> c;
	area = calculate_area(a, b, c);
	cout << "The area of the triangle is " << area;
	getch();
	return 0;
}

double calculate_s(double a, double b, double c) {
	return (a + b + c) / 2;
}

double calculate_area(double a, double b, double c) {
	double parameter = calculate_s(a, b, c);
	double sa, sb, sc;
	sa = diff(parameter, a);
	sb = diff(parameter, b);
	sc = diff(parameter, c);
	return (sqrt(parameter * sa * sb * sc));
}

double diff(double parameter, double n) {
	return (parameter - n);
}
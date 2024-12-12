#include <iostream.h>
#include <conio.h>

double comp_rp(double prev_as);
double comp_na(double prev_as);
double comp_nm(double na);

int main() {
	clrscr();
	double pas, nm, na, rp;
	cout << "Please enter your previous annual salary: ";
	cin >> pas;
	rp = comp_rp(pas);
	na = comp_na(pas);
	nm = comp_nm(na);
	cout << "Your retroactive pay amount is: " << rp
		 << "\nYour new annual salary is: " << na
		 << "\nYour new monthly salary is: " << nm;
	getch();
	return 0;
}

double comp_rp(double prev_as) {
	return ((prev_as* 0.076) / 2);
}
double comp_na(double prev_as) {
	return (prev_as * 1.076);
}
double comp_nm(double na) {
	return (na / 12);
}

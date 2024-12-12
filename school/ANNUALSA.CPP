#include <iostream.h>

int main() {
	double previous_annual_salary, new_monthly, new_annual, retroactive_pay;
	cout << "Please enter your previous annual salary: ";
	cin >> previous_annual_salary;
	retroactive_pay = (previous_annual_salary * 0.076) / 2;
	new_annual = previous_annual_salary + (previous_annual_salary * 0.076);
	new_monthly = new_annual / 12;
	cout << "Your retroactive pay amount is: " << retroactive_pay
		 << "\nYour new annual salary is: " << new_annual
		 << "\nYour new monthly salary is: " << new_monthly <<endl;

	return 0;
}
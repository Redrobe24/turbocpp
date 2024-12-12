#include <iostream.h>
#include <conio.h>

int main()
{
	clrscr();
	double cost_of_item, coi_tax, pay, change;
	cout << "Enter cost of item: ";
	cin >> cost_of_item;
	coi_tax = (cost_of_item * 0.06) + cost_of_item;
	cout << "Total cost of item with 6% of tax: " <<  coi_tax
		 << "\nCash tendered: ";
	cin >> pay;
	change = pay - coi_tax;
	clrscr();
	cout << "TRANSACTION SUMMARY"
		 << "\nCost of item: " << cost_of_item
		 << "\nCost of item with tax: " << coi_tax
		 << "\nAmount recieved: " << pay
		 << "\nAmount of change: " << change << endl;

	getch();
	return 0;
}
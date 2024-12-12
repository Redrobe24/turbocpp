#include <iostream.h>
#include <string.h>
#include <conio.h>

int main() {
	struct product_info {
		int id;
		char name[99];
		int quantity;
		double price;
	};
	int running = 1;
	char rep;
	product_info list[50];
	int product = 0;
	double total, highest;
	int hs_id;

	while (running) {
		clrscr();
		cout << "INVENTORY SYSTEM" << endl
			 << "[1] Add product" << endl
			 << "[2] Display products" << endl
			 << "[3] Calculate total value in the inventory" << endl
			 << "[4] Display highest value in the inventory" << endl
			 << "[5] Exit";
		rep = getch();
		switch (rep) {
			case '1':
				clrscr();
				list[product].id = product + 1;
				cout << "Enter product name: ";
				cin >> list[product].name;
				cout << "Enter quantity: ";
				cin >> list[product].quantity;
				cout << "Enter price: ";
				cin >> list[product].price;
				product++;
				break;
			case '2':
				clrscr();
				for (int x = 0; x < product; x++) {
					cout << "ID: " << list[x].id << ", NAME: " << list[x].name << ", QUANTITY: $" << list[x].quantity
						 << ", PRICE: " << list[x].price << endl;
				}
				getch();
				break;
			case '3':
				total = 0;
				clrscr();
				cout << "Total value of inventory: $";
				for (x = 0; x < product; x++) {
					total += list[x].quantity * list[x].price;
				}
				cout << total;
				getch();
				break;
			case '4':
				clrscr();
				highest = 0;
				hs_id = 0;
				for (x = 0; x < product; x++) {
					if (highest < list[x].price * list[x].quantity) {
						highest = list[x].price * list[x].quantity;
						hs_id = x;
					}
				}
				cout << "Highest value:" << endl
					 << "PRODUCT NAME: " << list[hs_id].name << endl
					 << "PRODUCT TOTAL VALUE: " << highest;
				getch();
				break;
			case '5':
				running = 0;
				break;
		}
	}
	return 0;
}

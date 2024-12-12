#include <iostream.h>
#include <conio.h> // For getch()
#include <time.h>   // For time()

// Function to display the game status
void displayStatus(int cookies, int cps, int upgradeCost) {
	clrscr();
	cout << "=========== COOKIE CLICKER ===========\n";
    cout << "Cookies: " << cookies << "\n";
    cout << "Cookies per second (CPS): " << cps << "\n";
    cout << "Upgrade cost: " << upgradeCost << " cookies\n";
    cout << "--------------------------------------\n";
    cout << "Press Enter to click a cookie!\n";
    cout << "Press 'u' to buy an upgrade (if you can afford it).\n";
    cout << "Press 'q' to quit the game.\n";
    cout << "======================================\n";
}

int main() {
    int cookies = 0;         // Total number of cookies
    int cps = 0;             // Cookies per second
    int upgradeCost = 10;    // Initial cost of an upgrade
    char choice;
    time_t lastUpdateTime = time(0); // Track the last update time

	while (1) {
		// Calculate AFK cookies
		time_t currentTime = time(0);
		if (currentTime > lastUpdateTime) {
			cookies += cps * (currentTime - lastUpdateTime); // AFK cookie calculation
			lastUpdateTime = currentTime;
		}

		// Display the current game status
		displayStatus(cookies, cps, upgradeCost);

		// Wait for user input
		if (kbhit()) { // Check if a key has been pressed
			choice = getch();
			if (choice == '\r') { // Enter key to click a cookie
				cookies++;
			} else if (choice == 'u' || choice == 'U') { // 'u' key to upgrade
				if (cookies >= upgradeCost) {
					cookies -= upgradeCost;
					cps++;
					upgradeCost += 5; // Increase cost for the next upgrade
				} else {
					cout << "Not enough cookies for an upgrade!\n";
					getch();
				}
			} else if (choice == 'q' || choice == 'Q') { // 'q' key to quit
				break;
			}
		}
	}

	cout << "\nThanks for playing! Final cookie count: " << cookies << "\n";
	return 0;
}

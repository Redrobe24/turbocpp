#include <iostream.h>
#include <conio.h>
#include <string.h>

int main() {
	clrscr();
	char word1[99], word2[99];
	cout << "Enter two words please\n";
	cin >> word1 >> word2;
	int x = strlen(word1);
	for (int y = 0; y < x - 1; y++) {
		for (int z = y + 1; z < x; z++) {
			if (word1[y] == word1[z]) {
				word1[z] = '0';
			}
		}
	}
	cout << "Similar letters:\n";
	for (y = 0; y < x; y++) {
		if (word1[y] == '0') {
			continue;
		}
		else {
			for (int z = 0; z < x; z++) {
				if (word1[y] == word2[z]) {
					cout << word1[y] << " ";
					break;
				}
			}
		}
	}
	getch();
	return 0;
}
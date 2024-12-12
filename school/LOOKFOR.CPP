#include <iostream.h>
#include <conio.h>
#include <string.h>

int main() {
	clrscr();
	char c, word[99];
	int count = 0;
	cout << "Enter a word: ";
	cin >> word;
	cout << "Enter a letter to look for: ";
	cin >> c;
	if (strchr(word, c)) {
		for (int x = 0; x < strlen(word); x++) {
			if (word[x] == c) {
				count++;
			}
		}
	}
	if (count) {
		cout << "The word " << word << " has " << count << " '" << c << "'";
	}
	else {
		cout << "Letter not found in word";
	}
	getch();
	return 0;
}
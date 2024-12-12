#include <iostream.h>
#include <conio.h>
#include <string.h>

int main() {
	clrscr();
	char word[99];
	int count, z;
	cout << "Enter a word: ";
	cin >> word;
	strlwr(word);
	z = strlen(word);
	for (int x = 0; x < z; x++) {
		if (word[x] == '0') {
			continue;
		}
		count = 1;
		cout << word[x] << ": ";
		for (int y = x + 1; y < z; y++) {
			if (word[x] == word[y]) {
				count++;
				word[y] = '0';
			}
		}
		cout << count << endl;
	}
	getch();
	return 0;
}
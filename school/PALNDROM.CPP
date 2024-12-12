#include <iostream.h>
#include <conio.h>
#include <string.h>

int main() {
	clrscr();
	char word1[99], word2[99];
	cout << "Enter a word to check if it's a palyndrome: ";
	cin >> word1;

	// check for period
	if (strrchr(word1, '.')) {
		word1[((strrchr(word1, '.')) - word1)] = word1[strlen(word1)];
	}

	// convert to lower case
	strlwr(word1);

	// copy word1 to word2
	strcpy(word2, word1);

	// reverse the word2
	strrev(word2);

	// check if its palyndrome
	if (strcmp(word1, word2) == 0) {
		cout << "It is a palyndrome";
	}
	else {
		cout << "It is not a palyndrome";
	}

	getch();
	return 0;
}
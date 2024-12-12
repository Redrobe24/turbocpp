#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ask(char question[], char choice1[], char choice2[], char choice3[], char choice4[], char correctChoice) {
	int right;
	for (int i = 0; i < strlen(question); i++) {
		cout << question[i];
	}
	cout << endl
		 << "A. ";
	for (int a = 0; a < strlen(choice1); a++) cout << choice1[a];
	cout << endl << "B. ";
	for (int b = 0; b < strlen(choice2); b++) cout << choice2[b];
	cout << endl << "C. ";
	for (int c = 0; c < strlen(choice3); c++) cout << choice3[c];
	cout << endl << "D. ";
	for (int d = 0; d < strlen(choice4); d++) cout << choice4[d];
	cout << endl;
	char choice = tolower(getch());
	if (choice == correctChoice) right = 1;
	else right = 0;
	return right;
}

int main() {
	srand(time(NULL));
	clrscr();
	int isUnique;
	char rep;
	const int questionSize = 10;
	int itemsCorrect[questionSize];
	int questionOrder[questionSize];
	int order;
	do {
		clrscr();
		int bruh = 0;
		int score = 0;
		// question order randomizer
		for (int i = 0; i < questionSize; i++) {
			do {
				questionOrder[i] = (rand() % 10) + 1;
				isUnique = 1;
				for (int j = 0; j < i; j++) {
					if (questionOrder[i] == questionOrder[j]) {
						isUnique = 0;
						break;
					}
				}
			} while (isUnique != 1);
		}
		// logic
		do {
			clrscr();
			order = questionOrder[bruh];
			for (i = 0; i < bruh; i++) {
				if (itemsCorrect[i] == 1) {
					cout << "O ";
				}
				else if (itemsCorrect[i] == 0) cout << "X ";
			}
			cout << endl << endl;
			cout << bruh + 1 << ". ";
			switch(order) {
				case 1:
					if (ask("What is 1+1", "2", "3", "4", "5", 'a') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 2:
					if (ask("What is the capital of France?", "Breadland", "Weird Mustache City", "Oui Oui", "Baguette Town", 'c') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 3:
					if (ask("What is skibidi", "Toilet", "Plunger", "BRUH", "brainrot", 'd') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 4:
					if (ask("What is 5 + 7?", "More than 10", "A lot", "12, duh", "21", 'c') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 5:
					if (ask("Which planet is known as the Red Planet?", "That Hot One", "Angry Planet", "Mars Bar", "The One with Aliens", 'b') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 6:
					if (ask("What is the largest ocean on Earth?", "Big Puddle", "Not That Big Puddle", "Water Everywhere", "Pacific, I think?", 'd') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 7:
					if (ask("What is H2O commonly known as?", "Air Juice", "Sky Sauce", "Wet Stuff", "Breathing Liquid", 'c') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 8:
					if (ask("How many continents are there?", "Not Enough", "IDK, Lots", "Seven", "The Right Amount", 'c') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 9:
					if (ask("What color is a banana?", "Tomato Red", "Shrek Green", "Banana Yellow", "Invisible", 'c') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
				case 10:
					if (ask("Which is the fastest land animal?", "Speedy Boi", "Big Mane Dude", "Spotty Zoomer", "Fast Horse", 'c') == 1) itemsCorrect[bruh] = 1;
					else itemsCorrect[bruh] = 0;
					break;
			}
			bruh++;
		} while (bruh < questionSize);
		clrscr();
		// score calculate
		for (i = 0; i < bruh; i++) {
				if (itemsCorrect[i] == 1) score += 1;
			}
		// display score and ask if wanna do again
		cout << "Final results:\n";
		for (i = 0; i < bruh; i++) {
				if (itemsCorrect[i] == 1) {
					cout << "O ";
				}
				else if (itemsCorrect[i] == 0) cout << "X ";
			}
		cout << "\nYou got a score of: " << score
			 << "\nWanna try again?[Y/N]";
		rep = tolower(getch());
	} while (rep == 'y');
	return 0;
}
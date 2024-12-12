#include <iostream.h>
#include <conio.h>
#include <ctype.h>

int main()
{
	char rep;
	int x_input, o_input, turn, running, round, x_score, o_score;
	x_score = 0;
	o_score = 0;
	const int winning[8][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}};

	do {
		char cell[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
		turn = 0;
		round = 0;
		running = 1;
		while (running)
		{
			clrscr();
			cout << "X: " << x_score << "\t " << "O: " << o_score << endl;
			cout << cell[0] << " | " << cell[1] << " | " << cell[2] << endl
				 << "---------" << endl
				 << cell[3] << " | " << cell[4] << " | " << cell[5] << endl
				 << "---------" << endl
				 << cell[6] << " | " << cell[7] << " | " << cell[8] << endl
				 << "     " << endl;
			if (round == 9)
			{
				cout << "DRAW";
				break;
			}

			// winning condition
			for (int i = 0; i < 8; i++)
			{
				if (cell[winning[i][0]] == cell[winning[i][1]] &&
					cell[winning[i][1]] == cell[winning[i][2]] &&
					cell[winning[i][0]] != ' ')
				{
					if (cell[winning[i][0]] == 'X')
					{
						x_score += 1;
					}
					else
					{
						o_score += 1;
					}
					cout << cell[winning[i][0]] << " WINS!";
					running = 0;
					break;
				}

			}
			if (running == 0)
			{
			break;
			}

			// game input

			if (turn == 0)
			{
				cout << "X TURN: ";
				cin >> x_input;
				x_input -= 1;
				if (cell[x_input] == ' ')
				{
					cell[x_input] = 'X';
					turn += 1;
					round += 1;
				}
				else
				{
					continue;
				}
			}

			else if (turn == 1)
			{
				cout << "O TURN: ";
				cin >> o_input;
				o_input -= 1;
				if (cell[o_input] == ' ')
				{
					cell[o_input] = 'O';
					turn -= 1;
					round += 1;
				}
				else
				{
					continue;
				}
			}
		}
		cout << "\nPlay again? [Y][N]:";
		rep = toupper(getch());
	}
	while (rep == 'Y');
	cout << "\nThank you for playing!";
	getch();
	return 0;
}
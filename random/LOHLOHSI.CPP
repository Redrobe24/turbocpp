#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <dos.h>
#include <conio.h>

int main()
{
	srand(time(0));
	int gd = DETECT, gm, running = 1;
	int nkeys, okeys;
	int score = 0, state = 0;
	int x = 350, y = 40, cx = 331,cy = 250;
	char str[99];
	int hand1[] = {366, 250, 466, 150};
	int hand2[] = {336, 215, 436, 115};
	int limit;
	do {
		limit = rand() % 21;
	} while (limit < 10);

	initgraph(&gd, &gm, "//turboc3/bgi");
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(1, 1,	"LOHLOH SIMULATOR");
	getch();

	while (running) {
		cleardevice();
		// check
		if (score >= limit) {
			outtextxy(20, 50, "CUMMING");
			delay(500);
			outtextxy(135, 50, "..");
			delay(650);
			outtextxy(168, 50, "..");
			delay(800);
			outtextxy(200, 50, "..");
			delay(1000);
			running = 0;
			break;
		}
		//RANDOMIZER
		do {
			nkeys = (rand() % 4) + 1;
		} while (nkeys == okeys);
		okeys = nkeys;
		//OUTPUT
		outtextxy(x - 90, y, "PRESS");
		if (nkeys == 1) {
			outtextxy(x, y, "W");
		}
		else if (nkeys == 2) {
			outtextxy(x, y, "A");
		}
		else if (nkeys == 3) {
			outtextxy(x, y, "S");
		}
		else if (nkeys == 4) {
			outtextxy(x, y, "D");
		}
		outtextxy(10, 10, "TIMES STROKED:");
		sprintf(str, "%d", score);
		outtextxy(240, 10, str);
		/* ---------  TT  ----------- */
		// balls
		arc(250, 380, 70, 360, 50);
		arc(350, 380, 180, 110, 50);
		// shaft
		int shaft1[] = {269, 333, 269, 183};
		int shaft2[] = {331, 333, 331, 183};
		drawpoly(2, shaft1);
		drawpoly(2, shaft2);
		// head
		int hole[] = {300, 160, 300, 138};
		drawpoly(2, hole);
		arc(300, 125, 240, 300, 65);
		arc(314, 181, 110, 180, 45);
		arc(286, 181, 0, 70, 45);
		// hands
		circle(cx, cy, 35);
		drawpoly(2, hand1);
		drawpoly(2, hand2);

		/* -------------------------- */
		//INPUT
		switch (getch()) {
			case 'q':
				running = 0;
				break;
			case 'e':
				score += 1;
				break;
			case 'w':
				if (nkeys == 1) {
					score += 1;
					if (state == 0) {
						for (int i = 1; i <= 3; i += 2) {
							hand1[i] += 40;
							hand2[i] += 40;
							cy += 20;
						}
						state = 1;
					}
					else {
						for (int i = 1; i <= 3; i+=2) {
							hand1[i] -= 40;
							hand2[i] -= 40;
							cy -= 20;
						}
						state = 0;
					}
				}
				else if (score > 0 && nkeys != 1) {
					score -= 1;
				}
				break;
			case 'a':
				if (nkeys == 2) {
					score += 1;
					if (state == 0) {
						for (int i = 1; i <= 3; i += 2) {
							hand1[i] += 40;
							hand2[i] += 40;
							cy += 20;
						}
						state = 1;
					}
					else {
						for (int i = 1; i <= 3; i+=2) {
							hand1[i] -= 40;
							hand2[i] -= 40;
							cy -= 20;
						}
						state = 0;
					}
				}
				else if (score > 0 && nkeys != 2) {
					score -= 1;
				}
				break;
			case 's':
				if (nkeys == 3) {
					score += 1;
					if (state == 0) {
						for (int i = 1; i <= 3; i += 2) {
							hand1[i] += 40;
							hand2[i] += 40;
							cy += 20;
						}
						state = 1;
					}
					else {
						for (int i = 1; i <= 3; i+=2) {
							hand1[i] -= 40;
							hand2[i] -= 40;
							cy -= 20;
						}
						state = 0;
					}
				}
				else if (score > 0 && nkeys != 3) {
					score -= 1;
				}
				break;
			case 'd':
				if (nkeys == 4) {
					score += 1;
					if (state == 0) {
						for (int i = 1; i <= 3; i += 2) {
							hand1[i] += 40;
							hand2[i] += 40;
							cy += 20;
						}
						state = 1;
					}
					else {
						for (int i = 1; i <= 3; i+=2) {
							hand1[i] -= 40;
							hand2[i] -= 40;
							cy -= 20;
						}
						state = 0;
					}
				}
				else if (score > 0 && nkeys != 4) {
					score -= 1;
				}
				break;
		}
	}
	cleardevice();
	setbkcolor(WHITE);
	delay(1000);
	closegraph();
	return 0;
}
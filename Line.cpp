#include "Line.h"

Line::Line()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = '*';

	line[LL].set(x, y, c);
	line[LR].set(x+1, y, c);
	line[RL].set(x+2, y, c);
	line[RR].set(x+3, y, c);
}

Line::Line(int x, int y, char c)
{
	line[LL].set(x, y, c);
	line[LR].set(x+1, y, c);
	line[RL].set(x+2 , y, c);
	line[RR].set(x+3, y, c);
}

bool Line::move(Direction dir)
{
	bool checkMove[4] = { false,false,false,false };

	line[LL].draw(' ');
	line[LR].draw(' ');
	line[RL].draw(' ');
	line[RR].draw(' ');

	checkMove[0] = line[LL].move(dir);
	checkMove[1] = line[LR].move(dir);
	checkMove[2] = line[RL].move(dir);
	checkMove[3] = line[RR].move(dir);

	line[LL].draw();
	line[LR].draw();
	line[RL].draw();
	line[RR].draw();

	bool res = checkMove[LL] || checkMove[LR] || checkMove[RL] || checkMove[RR];
	return res;
}

void Line::draw(char c)
{
	line[LL].draw(c);
	line[LR].draw(c);
	line[RL].draw(c);
	line[RR].draw(c);
}			


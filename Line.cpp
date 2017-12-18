#include "Line.h"


Line::Line()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = '#';

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

void Line::move(Direction dir)
{
	line[LL].draw(' ');
	line[LR].draw(' ');
	line[RL].draw(' ');
	line[RR].draw(' ');

	line[LL].move(dir);
	line[LR].move(dir);
	line[RL].move(dir);
	line[RR].move(dir);

	line[LL].draw();
	line[LR].draw();
	line[RL].draw();
	line[RR].draw();

}

void Line::draw(char c)
{
	line[LL].draw(c);
	line[LR].draw(c);
	line[RL].draw(c);
	line[RR].draw(c);
}

bool Line::canMove(const Board& gameBoard, Direction dir)
{
	bool check[4] = { false,false,false,false };
	bool res;

	check[LL] = line[LL].canMove(gameBoard, dir);
	check[LR] = line[LR].canMove(gameBoard, dir);
	check[RL] = line[RL].canMove(gameBoard, dir);
	check[RR] = line[RR].canMove(gameBoard, dir);

	res = check[LL] && check[LR] && check[RL] && check[RR];
	return res;
}


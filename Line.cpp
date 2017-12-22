#pragma once
#include "Line.h"


Line::Line()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = '#';

	line[HORIZONTAL][LL].set(x, y, c);
	line[HORIZONTAL][LR].set(x + 1, y, c);
	line[HORIZONTAL][RL].set(x + 2, y, c);
	line[HORIZONTAL][RR].set(x + 3, y, c);

	line[VERTICAL][LL].set(x, y, c);
	line[VERTICAL][LR].set(x, y -1, c);
	line[VERTICAL][RL].set(x, y - 2, c);
	line[VERTICAL][RR].set(x, y - 3, c);
}

Line::Line(int x, int y, char c)
{
	line[HORIZONTAL][LL].set(x, y, c);
	line[HORIZONTAL][LR].set(x + 1, y, c);
	line[HORIZONTAL][RL].set(x + 2, y, c);
	line[HORIZONTAL][RR].set(x + 3, y, c);

	line[VERTICAL][LL].set(x, y, c);
	line[VERTICAL][LR].set(x, y - 1, c);
	line[VERTICAL][RL].set(x, y - 2, c);
	line[VERTICAL][RR].set(x, y - 3, c);
}

void Line::move(Direction dir)
{

	if (dir == ROTATE)
	{
		switch (state)
		{

		case HORIZONTAL:
			state = VERTICAL;

			line[HORIZONTAL][LL].draw(' ');
			line[HORIZONTAL][LR].draw(' ');
			line[HORIZONTAL][RL].draw(' ');
			line[HORIZONTAL][RR].draw(' ');

			line[HORIZONTAL][LL].move(dir);
			line[HORIZONTAL][LR].move(dir);
			line[HORIZONTAL][RL].move(dir);
			line[HORIZONTAL][RR].move(dir);

			line[VERTICAL][LL].move(dir);
			line[VERTICAL][LR].move(dir);
			line[VERTICAL][RL].move(dir);
			line[VERTICAL][RR].move(dir);

			line[VERTICAL][LL].draw();
			line[VERTICAL][LR].draw();
			line[VERTICAL][RL].draw();
			line[VERTICAL][RR].draw();
			break;

		case VERTICAL:
			state = HORIZONTAL;
			line[VERTICAL][LL].draw(' ');
			line[VERTICAL][LR].draw(' ');
			line[VERTICAL][RL].draw(' ');
			line[VERTICAL][RR].draw(' ');

			line[HORIZONTAL][LL].move(dir);
			line[HORIZONTAL][LR].move(dir);
			line[HORIZONTAL][RL].move(dir);
			line[HORIZONTAL][RR].move(dir);

			line[VERTICAL][LL].move(dir);
			line[VERTICAL][LR].move(dir);
			line[VERTICAL][RL].move(dir);
			line[VERTICAL][RR].move(dir);

			line[HORIZONTAL][LL].draw();
			line[HORIZONTAL][LR].draw();
			line[HORIZONTAL][RL].draw();
			line[HORIZONTAL][RR].draw();
			break;
		}

	}
	else
	{

		switch (state)
		{
		case HORIZONTAL:
			state = HORIZONTAL;
			line[HORIZONTAL][LL].draw(' ');
			line[HORIZONTAL][LR].draw(' ');
			line[HORIZONTAL][RL].draw(' ');
			line[HORIZONTAL][RR].draw(' ');

			line[HORIZONTAL][LL].move(dir);
			line[HORIZONTAL][LR].move(dir);
			line[HORIZONTAL][RL].move(dir);
			line[HORIZONTAL][RR].move(dir);

			line[VERTICAL][LL].move(dir);
			line[VERTICAL][LR].move(dir);
			line[VERTICAL][RL].move(dir);
			line[VERTICAL][RR].move(dir);


			line[HORIZONTAL][LL].draw();
			line[HORIZONTAL][LR].draw();
			line[HORIZONTAL][RL].draw();
			line[HORIZONTAL][RR].draw();
			break;
		case VERTICAL:
			state = VERTICAL;
			line[VERTICAL][LL].draw(' ');
			line[VERTICAL][LR].draw(' ');
			line[VERTICAL][RL].draw(' ');
			line[VERTICAL][RR].draw(' ');

			line[HORIZONTAL][LL].move(dir);
			line[HORIZONTAL][LR].move(dir);
			line[HORIZONTAL][RL].move(dir);
			line[HORIZONTAL][RR].move(dir);

			line[VERTICAL][LL].move(dir);
			line[VERTICAL][LR].move(dir);
			line[VERTICAL][RL].move(dir);
			line[VERTICAL][RR].move(dir);


			line[VERTICAL][LL].draw();
			line[VERTICAL][LR].draw();
			line[VERTICAL][RL].draw();
			line[VERTICAL][RR].draw();
			break;
		}

	}


}

void Line::draw(char c)
{
	switch (state)
	{
	case HORIZONTAL:
		line[HORIZONTAL][LL].draw(c);
		line[HORIZONTAL][LR].draw(c);
		line[HORIZONTAL][RL].draw(c);
		line[HORIZONTAL][RR].draw(c);
		break;
	case VERTICAL:
		line[VERTICAL][LL].draw(c);
		line[VERTICAL][LR].draw(c);
		line[VERTICAL][RL].draw(c);
		line[VERTICAL][RR].draw(c);
		break;
	}

}

bool Line::canMove(const Board& gameBoard, Direction dir)
{
	bool check[4] = { false,false,false,false };
	bool res;

	if (dir == ROTATE)
	{
		switch (state)
		{
		case VERTICAL:
			check[LL] = line[HORIZONTAL][LL].canMove(gameBoard, dir);
			check[LR] = line[HORIZONTAL][LR].canMove(gameBoard, dir);
			check[RL] = line[HORIZONTAL][RL].canMove(gameBoard, dir);
			check[RR] = line[HORIZONTAL][RR].canMove(gameBoard, dir);
			break;
		case HORIZONTAL:
			check[LL] = line[VERTICAL][LL].canMove(gameBoard, dir);
			check[LR] = line[VERTICAL][LR].canMove(gameBoard, dir);
			check[RL] = line[VERTICAL][RL].canMove(gameBoard, dir);
			check[RR] = line[VERTICAL][RR].canMove(gameBoard, dir);
			break;
		}
	}
	else
	{

		switch (state)
		{
		case HORIZONTAL:
			check[LL] = line[HORIZONTAL][LL].canMove(gameBoard, dir);
			check[LR] = line[HORIZONTAL][LR].canMove(gameBoard, dir);
			check[RL] = line[HORIZONTAL][RL].canMove(gameBoard, dir);
			check[RR] = line[HORIZONTAL][RR].canMove(gameBoard, dir);
			break;
		case VERTICAL:
			check[LL] = line[VERTICAL][LL].canMove(gameBoard, dir);
			check[LR] = line[VERTICAL][LR].canMove(gameBoard, dir);
			check[RL] = line[VERTICAL][RL].canMove(gameBoard, dir);
			check[RR] = line[VERTICAL][RR].canMove(gameBoard, dir);
			break;
		}

	}

	res = check[LL] && check[LR] && check[RL] && check[RR];
	return res;
}


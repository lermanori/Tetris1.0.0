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
	line[VERTICAL][LR].set(x, y - 1, c);
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

void Line::draw(char c)const
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
	if (dir == ROTATE)
	{
		switch (state)
		{
		case HORIZONTAL:
			return (checkIfCanMove(VERTICAL, gameBoard, dir));
			break;
		case VERTICAL:
			return (checkIfCanMove(HORIZONTAL, gameBoard, dir));
			break;
		}
	}
	else
		return (checkIfCanMove(state, gameBoard, dir));
}

bool Line::checkIfCanMove(shapeState state, const Board & gameBoard, Direction dir)
{
	bool check[4] = { false,false,false,false };
	bool res;

	check[LL] = line[state][LL].Point::canMove(gameBoard, dir, line[state][LL]);
	check[LR] = line[state][LR].Point::canMove(gameBoard, dir, line[state][LR]);
	check[RL] = line[state][RL].Point::canMove(gameBoard, dir, line[state][RL]);
	check[RR] = line[state][RR].Point::canMove(gameBoard, dir, line[state][RR]);

	res = check[LL] && check[LR] && check[RL] && check[RR];
	return res;
}

int Line::markShape(Board & gameBoard)
{
	int x = 0, y = 0;
	this->getPosInMatrix(this->getPoint(), x, y);
	
	switch (state)
	{
	case HORIZONTAL: // ORDER LL LR RL RR
		gameBoard(y)[x] = LN;
		gameBoard(y)[x + 1] = LN;
		gameBoard(y)[x + 2] = LN;
		gameBoard(y)[x + 3] = LN;
		break;

	case VERTICAL:// ORDER BOTTOM UPWARDS
		gameBoard(y)[x] = LN;
		gameBoard(y - 1)[x] = LN;
		gameBoard(y - 2)[x] = LN;
		gameBoard(y - 3)[x] = LN;
		break;

	}
	this->draw(LN);
	return gameBoard.checkLine();
}


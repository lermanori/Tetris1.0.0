#include "LShape.h"
LShape::LShape()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = '#';

	LTetrisShape[HORIZONTAL][LT].set(x, y, c);
	LTetrisShape[HORIZONTAL][LeftSide].set(x, y + 1, c);
	LTetrisShape[HORIZONTAL][Mid].set(x + 1, y + 1, c);
	LTetrisShape[HORIZONTAL][RightSide].set(x + 2, y + 1, c);

	LTetrisShape[VERTICAL][LT].set(x, y, c);
	LTetrisShape[VERTICAL][LeftSide].set(x - 1, y, c);
	LTetrisShape[VERTICAL][Mid].set(x - 1, y + 1, c);
	LTetrisShape[VERTICAL][RightSide].set(x - 1, y + 2, c);

	LTetrisShape[INV_HORIZONTAL][LT].set(x, y, c);
	LTetrisShape[INV_HORIZONTAL][LeftSide].set(x, y + 1, c);
	LTetrisShape[INV_HORIZONTAL][Mid].set(x - 1, y + 1, c);
	LTetrisShape[INV_HORIZONTAL][RightSide].set(x - 2, y + 1, c);

	LTetrisShape[INV_VERTICAL][LT].set(x, y, c);
	LTetrisShape[INV_VERTICAL][LeftSide].set(x - 1, y, c);
	LTetrisShape[INV_VERTICAL][Mid].set(x - 1, y - 1, c);
	LTetrisShape[INV_VERTICAL][RightSide].set(x - 1, y - 2, c);
}
LShape::LShape(int x, int y, char c)
{
	LTetrisShape[HORIZONTAL][LT].set(x, y, c);
	LTetrisShape[HORIZONTAL][LeftSide].set(x, y + 1, c);
	LTetrisShape[HORIZONTAL][Mid].set(x + 1, y + 1, c);
	LTetrisShape[HORIZONTAL][RightSide].set(x + 2, y + 1, c);

	LTetrisShape[VERTICAL][LT].set(x, y, c);
	LTetrisShape[VERTICAL][LeftSide].set(x - 1, y, c);
	LTetrisShape[VERTICAL][Mid].set(x - 1, y + 1, c);
	LTetrisShape[VERTICAL][RightSide].set(x - 1, y + 2, c);

	LTetrisShape[INV_HORIZONTAL][LT].set(x, y, c);
	LTetrisShape[INV_HORIZONTAL][LeftSide].set(x, y + 1, c);
	LTetrisShape[INV_HORIZONTAL][Mid].set(x - 1, y + 1, c);
	LTetrisShape[INV_HORIZONTAL][RightSide].set(x - 2, y + 1, c);

	LTetrisShape[INV_VERTICAL][LT].set(x, y, c);
	LTetrisShape[INV_VERTICAL][LeftSide].set(x - 1, y, c);
	LTetrisShape[INV_VERTICAL][Mid].set(x - 1, y - 1, c);
	LTetrisShape[INV_VERTICAL][RightSide].set(x - 1, y - 2, c);
}

void LShape::move(Direction dir)
{
	if (dir == ROTATE)
	{
		switch (state)
		{
		case HORIZONTAL:
			draw(state, SPACE);
			state = VERTICAL;
			draw(state, c);
			break;
		case VERTICAL:
			draw(state, SPACE);
			state = INV_HORIZONTAL;
			draw(state, c);
			break;
		case INV_HORIZONTAL:
			draw(state, SPACE);
			state = INV_VERTICAL;
			draw(state, c);
			break;
		case INV_VERTICAL:
			draw(state, SPACE);
			state = HORIZONTAL;
			draw(state, c);
			break;
		}
	}
	else
	{
		draw(state, SPACE);
		move(state, dir);
		draw(state, c);

	}


}

void LShape::move(shapeState state, Direction dir)
{

	LTetrisShape[HORIZONTAL][LT].move(dir);
	LTetrisShape[HORIZONTAL][LeftSide].move(dir);
	LTetrisShape[HORIZONTAL][Mid].move(dir);
	LTetrisShape[HORIZONTAL][RightSide].move(dir);

	LTetrisShape[VERTICAL][LT].move(dir);
	LTetrisShape[VERTICAL][LeftSide].move(dir);
	LTetrisShape[VERTICAL][Mid].move(dir);
	LTetrisShape[VERTICAL][RightSide].move(dir);

	LTetrisShape[INV_HORIZONTAL][LT].move(dir);
	LTetrisShape[INV_HORIZONTAL][LeftSide].move(dir);
	LTetrisShape[INV_HORIZONTAL][Mid].move(dir);
	LTetrisShape[INV_HORIZONTAL][RightSide].move(dir);

	LTetrisShape[INV_VERTICAL][LT].move(dir);
	LTetrisShape[INV_VERTICAL][LeftSide].move(dir);
	LTetrisShape[INV_VERTICAL][Mid].move(dir);
	LTetrisShape[INV_VERTICAL][RightSide].move(dir);
}

void LShape::draw(shapeState state, char c) const
{

	LTetrisShape[state][LT].draw(c);
	LTetrisShape[state][LeftSide].draw(c);
	LTetrisShape[state][Mid].draw(c);
	LTetrisShape[state][RightSide].draw(c);

}

bool LShape::canMove(const Board & gameBoard, Direction dir)
{
	if (dir == ROTATE)
	{
		switch (state)
		{
		case HORIZONTAL:
			return (checkIfCanMove(VERTICAL, gameBoard, dir));
			break;
		case VERTICAL:
			return (checkIfCanMove(INV_HORIZONTAL, gameBoard, dir));
			break;
		case INV_HORIZONTAL:
			return (checkIfCanMove(INV_VERTICAL, gameBoard, dir));
			break;
		case INV_VERTICAL:
			return (checkIfCanMove(HORIZONTAL, gameBoard, dir));
			break;
		}

	}
	else
	{
		return (checkIfCanMove(state, gameBoard, dir));
	}
}

bool LShape::checkIfCanMove(shapeState state, const Board & gameBoard, Direction dir)
{
	bool check[4] = { false,false,false,false };
	bool res;

	check[LT] = LTetrisShape[state][LT].canMove(gameBoard, dir);
	check[LeftSide] = LTetrisShape[state][LeftSide].canMove(gameBoard, dir);
	check[Mid] = LTetrisShape[state][Mid].canMove(gameBoard, dir);
	check[RightSide] = LTetrisShape[state][RightSide].canMove(gameBoard, dir);

	res = check[LT] && check[LeftSide] && check[Mid] && check[RightSide];
	return res;
}





#include "TShape.h"

TShape::TShape()
{
	int x = MIN_X + 5, y = MIN_Y+1;
	char c = '#';

	TTetrisShape[HORIZONTAL][MidBottom].set(x, y, c);
	TTetrisShape[HORIZONTAL][RightBottom].set(x + 1, y, c);
	TTetrisShape[HORIZONTAL][LeftBottom].set(x - 1, y, c);
	TTetrisShape[HORIZONTAL][Chupchik].set(x, y - 1, c);

	TTetrisShape[VERTICAL][MidBottom].set(x, y, c);
	TTetrisShape[VERTICAL][RightBottom].set(x, y + 1, c);
	TTetrisShape[VERTICAL][LeftBottom].set(x, y - 1, c);
	TTetrisShape[VERTICAL][Chupchik].set(x + 1, y, c);

	TTetrisShape[INV_HORIZONTAL][MidBottom].set(x, y, c);
	TTetrisShape[INV_HORIZONTAL][RightBottom].set(x - 1, y, c);
	TTetrisShape[INV_HORIZONTAL][LeftBottom].set(x + 1, y, c);
	TTetrisShape[INV_HORIZONTAL][Chupchik].set(x, y + 1, c);

	TTetrisShape[INV_VERTICAL][MidBottom].set(x, y, c);
	TTetrisShape[INV_VERTICAL][RightBottom].set(x, y - 1, c);
	TTetrisShape[INV_VERTICAL][LeftBottom].set(x, y + 1, c);
	TTetrisShape[INV_VERTICAL][Chupchik].set(x - 1, y, c);
}

TShape::TShape(int x, int y, char c)
{
	TTetrisShape[HORIZONTAL][MidBottom].set(x, y, c);
	TTetrisShape[HORIZONTAL][RightBottom].set(x + 1, y, c);
	TTetrisShape[HORIZONTAL][LeftBottom].set(x - 1, y, c);
	TTetrisShape[HORIZONTAL][Chupchik].set(x, y - 1, c);

	TTetrisShape[VERTICAL][MidBottom].set(x, y, c);
	TTetrisShape[VERTICAL][RightBottom].set(x, y + 1, c);
	TTetrisShape[VERTICAL][LeftBottom].set(x, y - 1, c);
	TTetrisShape[VERTICAL][Chupchik].set(x + 1, y, c);

	TTetrisShape[INV_HORIZONTAL][MidBottom].set(x, y, c);
	TTetrisShape[INV_HORIZONTAL][RightBottom].set(x - 1, y, c);
	TTetrisShape[INV_HORIZONTAL][LeftBottom].set(x + 1, y, c);
	TTetrisShape[INV_HORIZONTAL][Chupchik].set(x, y + 1, c);

	TTetrisShape[INV_VERTICAL][MidBottom].set(x, y, c);
	TTetrisShape[INV_VERTICAL][RightBottom].set(x, y - 1, c);
	TTetrisShape[INV_VERTICAL][LeftBottom].set(x, y + 1, c);
	TTetrisShape[INV_VERTICAL][Chupchik].set(x - 1, y, c);
}


void TShape::move(Direction dir)
{
	if (dir == ROTATE)
	{
		switch (state)
		{
		case HORIZONTAL:
			draw(SPACE);
			state = VERTICAL;
			draw(c);
			break;
		case VERTICAL:
			draw(SPACE);
			state = INV_HORIZONTAL;
			draw(c);
			break;
		case INV_HORIZONTAL:
			draw(SPACE);
			state = INV_VERTICAL;
			draw(c);
			break;
		case INV_VERTICAL:
			draw(SPACE);
			state = HORIZONTAL;
			draw(c);
			break;
		}
	}
	else
	{
		draw(SPACE);
		move(state, dir);
		draw(c);
	}
}

void TShape::move(shapeState state, Direction dir)
{
	TTetrisShape[HORIZONTAL][MidBottom].move(dir);
	TTetrisShape[HORIZONTAL][RightBottom].move(dir);
	TTetrisShape[HORIZONTAL][LeftBottom].move(dir);
	TTetrisShape[HORIZONTAL][Chupchik].move(dir);
	
	TTetrisShape[VERTICAL][MidBottom].move(dir);
	TTetrisShape[VERTICAL][RightBottom].move(dir);
	TTetrisShape[VERTICAL][LeftBottom].move(dir);
	TTetrisShape[VERTICAL][Chupchik].move(dir);
	
	TTetrisShape[INV_HORIZONTAL][MidBottom].move(dir);
	TTetrisShape[INV_HORIZONTAL][RightBottom].move(dir);
	TTetrisShape[INV_HORIZONTAL][LeftBottom].move(dir);
	TTetrisShape[INV_HORIZONTAL][Chupchik].move(dir);
	
	TTetrisShape[INV_VERTICAL][MidBottom].move(dir);
	TTetrisShape[INV_VERTICAL][RightBottom].move(dir);
	TTetrisShape[INV_VERTICAL][LeftBottom].move(dir);
	TTetrisShape[INV_VERTICAL][Chupchik].move(dir);
}

void TShape::draw(shapeState state, char c) const
{
	TTetrisShape[state][MidBottom].draw(c);
	TTetrisShape[state][RightBottom].draw(c);
	TTetrisShape[state][LeftBottom].draw(c);
	TTetrisShape[state][Chupchik].draw(c);
}

bool TShape::canMove(const Board & gameBoard, Direction dir)
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

bool TShape::checkIfCanMove(shapeState state, const Board & gameBoard, Direction dir)
{
	bool check[4] = { false,false,false,false };
	bool res;

	check[MidBottom] = TTetrisShape[state][MidBottom].canMove(gameBoard, dir);
	check[RightBottom] = TTetrisShape[state][RightBottom].canMove(gameBoard, dir);
	check[LeftBottom] = TTetrisShape[state][LeftBottom].canMove(gameBoard, dir);
	check[Chupchik] = TTetrisShape[state][Chupchik].canMove(gameBoard, dir);

	res = check[MidBottom] && check[RightBottom] && check[LeftBottom] && check[Chupchik];
	return res;
}

int TShape::markShape(Board & gameBoard)
{
	int x = 0, y = 0;
	this->getPosInMatrix(this->getPoint(), x, y);

	switch (state)
	{
	case HORIZONTAL: // 
		gameBoard(y)[x] = TSHP;
		gameBoard(y)[x + 1] = TSHP;
		gameBoard(y)[x - 1] = TSHP;
		gameBoard(y - 1)[x] = TSHP;
		break;

	case VERTICAL:// ORDER BOTTOM UPWARDS
		gameBoard(y)[x] = TSHP;
		gameBoard(y + 1)[x] = TSHP;
		gameBoard(y - 1)[x] = TSHP;
		gameBoard(y)[x + 1] = TSHP;
		break;

	case INV_HORIZONTAL: // 
		gameBoard(y)[x] = TSHP;
		gameBoard(y)[x - 1] = TSHP;
		gameBoard(y)[x + 1] = TSHP;
		gameBoard(y + 1)[x] = TSHP;
		break;

	case INV_VERTICAL:// ORDER BOTTOM UPWARDS
		gameBoard(y)[x] = TSHP;
		gameBoard(y - 1)[x] = TSHP;
		gameBoard(y + 1)[x] = TSHP;
		gameBoard(y)[x - 1] = TSHP;
		break;

	}
	this->draw(TSHP);
	return gameBoard.checkLine();
}


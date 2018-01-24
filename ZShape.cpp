#include "ZShape.h"

ZShape::ZShape()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = '#';

	ZTetrisShape[HORIZONTAL][LTop].set(x, y, c);
	ZTetrisShape[HORIZONTAL][RTop].set(x + 1, y, c);
	ZTetrisShape[HORIZONTAL][LBottom].set(x + 1, y + 1, c);
	ZTetrisShape[HORIZONTAL][RBottom].set(x + 2, y + 1, c);
	
	ZTetrisShape[VERTICAL][LTop].set(x, y, c);
	ZTetrisShape[VERTICAL][RTop].set(x, y + 1, c);
	ZTetrisShape[VERTICAL][LBottom].set(x - 1, y + 1, c);
	ZTetrisShape[VERTICAL][RBottom].set(x - 1, y + 2, c);

	ZTetrisShape[INV_HORIZONTAL][LTop].set(x, y, c);
	ZTetrisShape[INV_HORIZONTAL][RTop].set(x - 1, y, c);
	ZTetrisShape[INV_HORIZONTAL][LBottom].set(x - 1, y - 1, c);
	ZTetrisShape[INV_HORIZONTAL][RBottom].set(x - 2, y - 1, c);

	ZTetrisShape[INV_VERTICAL][LTop].set(x, y, c);
	ZTetrisShape[INV_VERTICAL][RTop].set(x, y - 1, c);
	ZTetrisShape[INV_VERTICAL][LBottom].set(x + 1, y - 1, c);
	ZTetrisShape[INV_VERTICAL][RBottom].set(x + 1, y - 2, c);
				 
}

ZShape::ZShape(int x, int y, char c)
{	

	ZTetrisShape[HORIZONTAL][LTop].set(x, y, c);
	ZTetrisShape[HORIZONTAL][RTop].set(x + 1, y, c);
	ZTetrisShape[HORIZONTAL][LBottom].set(x + 1, y + 1, c);
	ZTetrisShape[HORIZONTAL][RBottom].set(x + 2, y + 1, c);

	ZTetrisShape[VERTICAL][LTop].set(x, y, c);
	ZTetrisShape[VERTICAL][RTop].set(x, y + 1, c);
	ZTetrisShape[VERTICAL][LBottom].set(x - 1, y + 1, c);
	ZTetrisShape[VERTICAL][RBottom].set(x - 1, y + 2, c);

	ZTetrisShape[INV_HORIZONTAL][LTop].set(x, y, c);
	ZTetrisShape[INV_HORIZONTAL][RTop].set(x - 1, y, c);
	ZTetrisShape[INV_HORIZONTAL][LBottom].set(x - 1, y - 1, c);
	ZTetrisShape[INV_HORIZONTAL][RBottom].set(x - 2, y - 1, c);

	ZTetrisShape[INV_VERTICAL][LTop].set(x, y, c);
	ZTetrisShape[INV_VERTICAL][RTop].set(x, y - 1, c);
	ZTetrisShape[INV_VERTICAL][LBottom].set(x + 1, y - 1, c);
	ZTetrisShape[INV_VERTICAL][RBottom].set(x + 1, y - 2, c);
}

void ZShape::move(Direction dir)
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

void ZShape::move(shapeState state, Direction dir)
{

	ZTetrisShape[HORIZONTAL][LTop].move(dir);
	ZTetrisShape[HORIZONTAL][RTop].move(dir);
	ZTetrisShape[HORIZONTAL][LBottom].move(dir);
	ZTetrisShape[HORIZONTAL][RBottom].move(dir);

	ZTetrisShape[VERTICAL][LTop].move(dir);
	ZTetrisShape[VERTICAL][RTop].move(dir);
	ZTetrisShape[VERTICAL][LBottom].move(dir);
	ZTetrisShape[VERTICAL][RBottom].move(dir);

	ZTetrisShape[INV_HORIZONTAL][LTop].move(dir);
	ZTetrisShape[INV_HORIZONTAL][RTop].move(dir);
	ZTetrisShape[INV_HORIZONTAL][LBottom].move(dir);
	ZTetrisShape[INV_HORIZONTAL][RBottom].move(dir);

	ZTetrisShape[INV_VERTICAL][LTop].move(dir);
	ZTetrisShape[INV_VERTICAL][RTop].move(dir);
	ZTetrisShape[INV_VERTICAL][LBottom].move(dir);
	ZTetrisShape[INV_VERTICAL][RBottom].move(dir);

}

void ZShape::draw(shapeState state, char c) const
{
	ZTetrisShape[state][LTop].draw(c);
	ZTetrisShape[state][RTop].draw(c);
	ZTetrisShape[state][LBottom].draw(c);
	ZTetrisShape[state][RBottom].draw(c);
}

bool ZShape::canMove(const Board & gameBoard, Direction dir)
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

bool ZShape::checkIfCanMove(shapeState state, const Board & gameBoard, Direction dir)
{
	bool check[4] = { false,false,false,false };
	bool res;

	check[LTop] = ZTetrisShape[state][LTop].Point::canMove(gameBoard, dir, ZTetrisShape[state][LTop]);
	check[RTop] = ZTetrisShape[state][RTop].Point::canMove(gameBoard, dir, ZTetrisShape[state][RTop]);
	check[LBottom] = ZTetrisShape[state][LBottom].Point::canMove(gameBoard, dir, ZTetrisShape[state][LBottom]);
	check[RBottom] = ZTetrisShape[state][RBottom].Point::canMove(gameBoard, dir, ZTetrisShape[state][RBottom]);

	res = check[LTop] && check[RTop] && check[LBottom] && check[RBottom];
	return res;
}

int ZShape::markShape(Board & gameBoard)
{
	int x = 0, y = 0;
	this->getPosInMatrix(this->getPoint(), x, y);

	switch (state)
	{
	case HORIZONTAL: // 
		gameBoard(y)[x] = ZSHP;
		gameBoard(y)[x + 1] = ZSHP;
		gameBoard(y + 1)[x + 1] = ZSHP;
		gameBoard(y + 1)[x + 2] = ZSHP;
		break;

	case VERTICAL:// ORDER BOTTOM UPWARDS
		gameBoard(y)[x] = ZSHP;
		gameBoard(y + 1)[x] = ZSHP;
		gameBoard(y + 1)[x - 1] = ZSHP;
		gameBoard(y + 2)[x - 1] = ZSHP;
		break;

	case INV_HORIZONTAL: // 
		gameBoard(y)[x] = ZSHP;
		gameBoard(y)[x - 1] = ZSHP;
		gameBoard(y - 1)[x - 1] = ZSHP;
		gameBoard(y - 1)[x - 2] = ZSHP;
		break;

	case INV_VERTICAL:// ORDER BOTTOM UPWARDS
		gameBoard(y)[x] = ZSHP;
		gameBoard(y - 1)[x] = ZSHP;
		gameBoard(y - 1)[x + 1] = ZSHP;
		gameBoard(y - 2)[x + 1] = ZSHP;
		break;
	}
	this->draw(ZSHP);
	return gameBoard.checkLine();
}

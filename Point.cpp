#pragma once
#include "Point.h"
#include "Board.h"

class Board;

void Point::move(Direction dir)
{
	switch (dir)
	{
/*	case UP:
		direction_x = 0;
		direction_y = -1;
		break;
*/
	case RIGHT:
		direction_x = 1;
		direction_y = 0;
		break;
	case DOWN:
		direction_x = 0;
		direction_y = 1;
		break;
	case LEFT:
		direction_x = -1;
		direction_y = 0;
		break;
	default:
		direction_x = 0;
		direction_y = 0;
		break;
	}

	if (x >= MAX_X-1)
	{

		x = MAX_X-1;
	
	}
	else if (x <= MIN_X+1)
	{
		x = MIN_X+1;
		
	}
	else if (y >= MAX_Y-1)
	{
		y = MAX_Y;

	}
	else if (y < MIN_Y+1)
	{
		y = MIN_Y+1;
	}

	x += direction_x;
	y = (direction_y + y + 1);

}

bool Point::canMove(const Board &gameBoard, Direction dir)
{
	int x, y;
	this->getPosInMatrix(this->getX(), this->getY(), x, y);
	switch (dir)
	{
	case RIGHT:
		if (gameBoard.haveSpace(x + 1, y))
			return true;
		else
			return false;
		break;
	case DOWN:
		if (gameBoard.haveSpace(x, y + 2) && (gameBoard.haveSpace(x, y + 2)))
			return true;
		else
			return false;
		break;
	case LEFT:
		if (gameBoard.haveSpace(x - 1,y))
			return true;
		else
			return false;
		break;

	default:
		if (gameBoard.haveSpace(x,y + 1))
			return true;
		else
			return false;
		break;
	}
}
void Point::getPosInMatrix(const Point& pt, int &x, int &y)
{
	x = pt.getX() - MIN_X;
	y = pt.getY() - MIN_Y;
}

void Point::getPosInMatrix(int x, int y, int & xNewPos, int & yNewPos)
{
	xNewPos = x - MIN_X;
	yNewPos = y - MIN_Y;
}
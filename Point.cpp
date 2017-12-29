#pragma once
#include "Point.h"
#include "Board.h"

class Board;

void Point::move(Direction dir)
{
	switch (dir)
	{

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

	x += direction_x;
	y += direction_y;



}

bool Point::canMove(const Board &gameBoard, Direction dir)
{
	int x, y;
	this->getPosInMatrix(this->getX(), this->getY(), x, y);
	switch (dir)
	{
	case ROTATE:
		if (gameBoard.haveSpace(x, y))
			return true;
		else
			return false;
		break;
	case RIGHT:
		if (gameBoard.haveSpace(x + 1, y))
			return true;
		else
			return false;
		break;
	case DOWN:
		if (gameBoard.haveSpace(x, y + 1))
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
bool Point::canMoveJoker(const Board & gameBoard, Direction dir)
{
	int x, y;
	this->getPosInMatrix(this->getX(), this->getY(), x, y);
	switch (dir)
	{

	case RIGHT:
		if (gameBoard.haveSpaceJoker(x + 1, y))
			return true;
		else
			return false;
		break;
	case DOWN:
		if (gameBoard.haveSpaceJoker(x, y + 1))
			return true;
		else
			return false;
		break;
	case LEFT:
		if (gameBoard.haveSpaceJoker(x - 1, y))
			return true;
		else
			return false;
		break;

	default:
		if (gameBoard.haveSpaceJoker(x, y + 1))
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
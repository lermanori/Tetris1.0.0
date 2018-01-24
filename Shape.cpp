#pragma once
#include "Shape.h"

bool Shape::canMove(const Board & gameBoard, Direction dir)
{
		if (dir == ROTATE)
		{
			switch (this->getState())
			{
			case HORIZONTAL:
				return (this->checkIfCanMove(VERTICAL, gameBoard, dir));
				break;
			case VERTICAL:
				return (this->checkIfCanMove(INV_HORIZONTAL, gameBoard, dir));
				break;
			case INV_HORIZONTAL:
				return (this->checkIfCanMove(INV_VERTICAL, gameBoard, dir));
				break;
			case INV_VERTICAL:
				return (this->checkIfCanMove(HORIZONTAL, gameBoard, dir));
				break;
			}

		}
		else
		{
			return (this->checkIfCanMove(this->getState(), gameBoard, dir));
		}
}

void Shape::getPosInMatrix(const Point & pt, int & x, int & y)
{
	 x = pt.getX() - MIN_X;	
	 y = pt.getY() - MIN_Y; 
}

#pragma once
#include "ShapeFactory.h"

ShapeFactory::ShapeFactory()
{
	switch (shapeType)
	{
	case SQUARE:
		sqrPtr = (Square*)new Square;
		//	this->shapePtr = (Square*)new Square;
		break;
	case LINE:
		linePtr = (Line*)new Line;
		break;
	case BOMB:
		bombPtr = (Bomb*)new Bomb;
		break;
	}
}

void ShapeFactory::move(Direction dir)
{
	switch (shapeType)
	{
	case SQUARE:
		sqrPtr->move(dir);
		break;

	case LINE:
		linePtr->move(dir);
		break;

	case BOMB:
		bombPtr->move(dir);
		break;
	}
}

void ShapeFactory::draw(char c)const
{

	switch (shapeType)
	{
	case SQUARE:
		sqrPtr->draw(c);
		break;

	case LINE:
		linePtr->draw(c);
		break;

	case BOMB:
		bombPtr->draw(c);
		break;
	}
}

const Point& ShapeFactory::getPoint()const
{

	switch (shapeType)
	{
	case SQUARE:
		return(sqrPtr->getPoint());
		break;

	case LINE:
		return(linePtr->getPoint());
		break;

	case BOMB:
		return(bombPtr->getPoint());
		break;

	}
}

int ShapeFactory::getShapeState()const
{
	switch (shapeType)
	{
	case SQUARE:
		return 0;
		break;
	case LINE:
		return(linePtr->getState());
		break;
	case BOMB:
		return 0;
		break;
	default: //will never enter default
		return 0;
		break;
	}

}

bool ShapeFactory::canMove(Board& gameBoard, Direction dir)
{
	switch (shapeType)
	{
	case SQUARE:
		return(sqrPtr->canMove(gameBoard, dir));
		break;
	case LINE:
		return(linePtr->canMove(gameBoard, dir));
		break;
	case BOMB:
		return(bombPtr->canMove(gameBoard, dir));
		break;
	default://will never enter default
		return false;
		break;
	}
	
}

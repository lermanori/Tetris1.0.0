#pragma once
#include "ShapeFactory.h"

//Shape Probabilities Guide:
// 40% Squares
// 40% Lines
// 10% Bombs
// 10% Jokers
const int ShapeFactory::shapeProbabilities()
{
	const int x = rand() % 10;

	if (x <= 3)
		return SQUARE;
	else if (x > 3 && x <= 7)
		return LINE;
	else if (x == 8)
		return BOMB;
	else
		return JOKER;

}

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
	case JOKER:
		jokerPtr = (Joker*)new Joker;
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
	case JOKER:
		jokerPtr->move(dir);
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
	case JOKER:
		jokerPtr->draw(c);
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
	case JOKER:
		return(jokerPtr->getPoint());
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
	case JOKER:
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
	case JOKER:
		return(jokerPtr->canMove(gameBoard, dir));
		break;
	default://will never enter default
		return false;
		break;
	}
	
}

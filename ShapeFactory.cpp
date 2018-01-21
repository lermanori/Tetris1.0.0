#pragma once
#include "ShapeFactory.h"

Shape* ShapeFactory::createShape(const int shapeType)
{
	switch (shapeType)
	{
	case LINE:
		return new Line;
		break;
	case SQUARE:
		return new Square;
		break;
	case BOMB:
		return new Bomb;
		break;
	case JOKER:
		return new Joker;
		break;
	case LSHAPE:
		return new LShape;
		break;

	}
}

//Shape Probabilities Guide:
// 40% Squares
// 40% Lines
// 10% Bombs
// 10% Jokers
int ShapeFactory::shapeProbabilities()
{

	const int x = rand() % 13;
	
	if (x <= 3)
		return SQUARE;
	else if (x > 3 && x <= 7)
		return LINE;
	else if (x == 8)
		return BOMB;
	else if (x == 9)
		return JOKER;
	else
		return LSHAPE;

}


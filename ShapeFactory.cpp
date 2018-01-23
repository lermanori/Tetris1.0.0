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
	case ZSHAPE:
		return new ZShape;
		break;
	case TSHAPE:
		return new TShape;
		break;
	default:
		return nullptr;
	}
}

//Shape Probabilities Guide:
// 0.16 % SQUARES
// 0.16 % LINES
// 0.16 % LSHAPES
// 0.16 % ZSHAPES
// 0.16 % TSHAPES
// 0.0333 % BOMBS
// 0.1 % JOKERS
int ShapeFactory::shapeProbabilities()
{

	const int x = rand() % 30;
	if (x <= 5)
		return SQUARE;
	else if (x > 5 && x <= 10)
		return LINE;
	else if (x > 10 && x <= 15)
		return LSHAPE;
	else if (x > 15 && x <= 20)
		return ZSHAPE;
	else if (x > 20 && x <= 25)
		return TSHAPE;
	else if (x == 26)
		return BOMB;
	else if (x == 27 || x == 28 || x == 29)
		return JOKER;
		
}


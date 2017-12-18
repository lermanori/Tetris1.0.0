#include "ShapeFactory.h"

ShapeFactory::ShapeFactory()
{
	switch (shapeType)
	{
		case 0:
			sqrPtr = (Square*)new Square;
		//	this->shapePtr = (Square*)new Square;
			break;
		case 1:
			linePtr = (Line*)new Line;
			break;
		case 2:
			bombPtr = (Bomb*)new Bomb;
			break;
	}
}

bool ShapeFactory::move(Direction dir)
{
	switch (shapeType)
	{
	case 0:
		return(sqrPtr->move(dir) );
		break;

	case 1:
		return(linePtr->move(dir));
		break;

	case 2:
		return(bombPtr->move(dir));
		break;
	}
}

void ShapeFactory::draw(char c)
{

	switch (shapeType)
	{
	case 0:
		sqrPtr->draw(c);
		break;

	case 1:
		linePtr->draw(c);
		break;

	case 2:
		bombPtr->draw(c);
		break;
	}
}

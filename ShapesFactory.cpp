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

bool ShapeFactory::move(Direction dir)
{
	switch (shapeType)
	{
	case SQUARE:
		return(sqrPtr->move(dir) );
		break;

	case LINE:
		return(linePtr->move(dir));
		break;

	case BOMB:
		return(bombPtr->move(dir));
		break;
	}
}

void ShapeFactory::draw(char c)
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

const Point& ShapeFactory::getPoint()
{
	switch (shapeType)
	{
	case SQUARE:
		return(sqrPtr->getPoint);
		break;

	case LINE:
		linePtr->draw(c);
		break;

	case BOMB:
		bombPtr->draw(c);
		break;
	}
	return Point();
}

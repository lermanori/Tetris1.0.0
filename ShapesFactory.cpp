#include "ShapeFactory.h"

ShapeFactory::ShapeFactory()
{
	switch (x)
	{
		case 0:
			shapePtr = (Square*)new Square;
		//	this->shapePtr = (Square*)new Square;
			break;
		case 1:
			shapePtr = (Line*)new Line;
			break;
		case 2:
			shapePtr = (Bomb*)new Bomb;
			break;
	}
}

bool ShapeFactory::move(Direction dir)
{
	
	Square* sqrPtr= nullptr;
	Line* linePtr = nullptr;
	Bomb* bombPtr = nullptr;


	switch (x)
	{
	case 0:
		sqrPtr = (Square*)shapePtr;
		return( sqrPtr->move(dir) );
		break;

	case 1:
		linePtr = (Line*)shapePtr;
		return(linePtr->move(dir));
		break;

	case 2:
		bombPtr = (Bomb*)shapePtr;
		return(bombPtr->move(dir));
		break;
	}
}

void ShapeFactory::draw(char c)
{
	Square* sqrPtr = nullptr;
	Line* linePtr = nullptr;
	Bomb* bombPtr = nullptr;

	switch (x)
	{
	case 0:
		sqrPtr = (Square*)shapePtr;
		sqrPtr->draw(c);
		break;

	case 1:
		linePtr = (Line*)shapePtr;
		linePtr->draw(c);
		break;

	case 2:
		bombPtr = (Bomb*)shapePtr;
		bombPtr->draw(c);
		break;
	}
}

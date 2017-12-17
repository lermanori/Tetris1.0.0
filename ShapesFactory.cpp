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
	}
}

bool ShapeFactory::move(Direction dir)
{
	
	Square* sqrPtr= nullptr;
	Line* linePtr = nullptr;



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
	}
}

void ShapeFactory::draw(char c)
{
	Square* sqrPtr = nullptr;
	Line* linePtr = nullptr;



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
	}
}

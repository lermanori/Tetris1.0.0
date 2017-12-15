#include "ShapeFactory.h"

ShapeFactory::ShapeFactory()
{
	switch (x)
	{
		case 0:
			sqrPtr = (Square*)new Square;
		//	this->shapePtr = (Square*)new Square;
			break;
		case 1:
			sqrPtr = (Square*)new Square(MIN_X, MIN_Y, 'P');
			break;
	}
}

bool ShapeFactory::move(Direction dir)
{
	
	Square* ptrSq= nullptr;
	Square* ptrSq2 = nullptr;



	switch (x)
	{
	case 0:
		ptrSq = (Square*)sqrPtr;
		return( ptrSq->move(dir) );
		break;

	case 1:
		ptrSq2 = (Square*)sqrPtr;
		return(ptrSq2->move(dir));
		break;
	}
}

void ShapeFactory::draw(char c)
{
	Square* ptrSq = nullptr;
	Square* ptrSq2 = nullptr;



	switch (x)
	{
	case 0:
		ptrSq = (Square*)sqrPtr;
		ptrSq->draw(c);
		break;

	case 1:
		ptrSq2 = (Square*)sqrPtr;
		ptrSq2->draw(c);
		break;
	}
}

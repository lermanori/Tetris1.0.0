/************************************************************************************************************************************************
~~~~ ShapeFactory.h + ShapeFactory.cpp ~~~
 shape factory is the factory object as part of factory design pattern implementation

shape factory creates a random tetris object that is refred the shape object(through interface).


shapeProbabilities- controls the probabilities of the shape manufucture.

there is a static method that called create and uses as a general purpose function that is used to create object.
(factory design pattern)

************************************************************************************************************************************************/

#pragma once

#include "square.h"
#include "Line.h"
#include "bomb.h"
#include "Joker.h"
#include "LShape.h"
#include "ZShape.h"
#include "TShape.h"
#include "constants.h"

class ShapeFactory: public Shape
{


public:
	static int shapeProbabilities();
	static Shape* createShape(const int shapeType);

		
};
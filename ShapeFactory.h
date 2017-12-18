#pragma once
#include "square.h"
#include "Line.h"
#include "bomb.h"

//shape factory creates a random tetris object that is refred threw the shape itself.
//its using the void pointer to hold the adress to the part and used each time by casting to the desired object and activating the objects methods.  
class ShapeFactory
{
	void* shapePtr = nullptr;
	const int x = rand() % 3;
public:
	ShapeFactory();
	bool move(Direction dir);
	void draw(char c);
		
};
#pragma once
#include "square.h"
//shape factory creates a random tetris object that is refred threw the shape itself.
//its using the void pointer to hold the adress to the part and used each time by casting to the desired object and activating the objects methods.  
class ShapeFactory
{
	void* sqrPtr = nullptr;
	const int x = rand() % 2;
public:
	ShapeFactory();
	bool move(Direction dir);
	void draw(char c);
		
};
#pragma once
#include "square.h"
class ShapeFactory
{
	void* sqrPtr = nullptr;
	const int x = rand() % 2;
public:
	ShapeFactory();
	bool move(Direction dir);
	void draw(char c);
		
};
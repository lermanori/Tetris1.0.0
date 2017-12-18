#pragma once
#include "point.h"

enum { size = 4 };

class Square 
{
	Point s1[size];

	char c;

public:
	Square();
	Square(int x, int y, char c);
	bool move(Direction dir);
	void draw(char c);
	const Point& getPoint() { return s1[BL]; };
		
};
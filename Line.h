#pragma once
#include "Point.h"

enum { lineSize = 4 };

class Line
{
	Point line[lineSize];
	char c;

public:
	Line();
	Line(int x, int y, char c);
	bool move(Direction dir);
	void draw(char c);
};
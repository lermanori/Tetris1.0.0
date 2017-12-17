#pragma once

#include "Point.h"

class Bomb
{
	Point p;
	char c;

public:
	Bomb();
	Bomb(int x, int y, char c);
	bool move(Direction dir);
	void draw(char c);



};

#pragma once

#include <iostream>
#include "utils.h"
#include "constants.h"

class Point
{
	int x, y;
	char c;
	int direction_x = 0;
	int direction_y = 0;

public:
	Point() { x = MIN_X+5; y = MIN_Y; c = 'N'; }
	Point(int x, int y, int c)
	{
		set(x, y, c);
		this->draw();
	}
	void set(int x, int y, int c)
	{
		this->x = x;
		this->y = y;
		this->c = c;
	}
	int getX() { return x; }
	int getY() { return y; }
	void draw(char c)
	{
		gotoxy(x, y);
		std::cout << c;
		std::cout.flush();
	}
	void draw()
	{
		draw(c);
	}
	bool move(Direction dir);
};
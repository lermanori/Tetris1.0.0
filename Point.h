#pragma once

#include <iostream>
#include "utils.h"
#include "constants.h"


class Board;

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
	int getX()const { return x; }
	int getY()const { return y; }
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
	void move(Direction dir);
	bool canMove(const Board& gameBoard, Direction dir);
	void getPosInMatrix(const Point& pt, int &x, int &y);
	void getPosInMatrix(int x, int y, int & xNewPos, int & yNewPos);
};
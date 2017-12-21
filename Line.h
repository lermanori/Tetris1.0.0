#pragma once
#include "Point.h"

class Board;

enum { lineSize = 4 };

class Line
{
	Point line[2][lineSize]; //2 arrays for line. 1 horizontal and 1 vertical
	LineState state = HORIZONTAL;
	char c;

public:
	Line();
	Line(int x, int y, char c);
	void move(Direction dir);
	void draw(char c);
	const Point& getPoint() { return line[state][LL]; }
	LineState getState() { return state; }
	bool canMove(const Board& gameBoard, Direction dir);
};
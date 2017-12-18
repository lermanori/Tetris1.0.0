#pragma once
#include "Point.h"
#include "Board.h"

enum { lineSize = 4 };

class Line
{
	Point line[lineSize];
	LineState state = HORIZONTAL;
	char c;

public:
	Line();
	Line(int x, int y, char c);
	void move(Direction dir);
	void draw(char c);
	const Point& getPoint() { return line[LL]; }
	LineState getState() { return state; }
	bool canMove(const Board& gameBoard, Direction dir);
};
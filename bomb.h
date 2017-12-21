#pragma once

#include "Point.h"

class Bomb
{
	Point p;
	char c;

public:
	Bomb();
	Bomb(int x, int y, char c);
	void move(Direction dir);
	void draw(char c);
	const Point& getPoint() { return p; };
	bool canMove(const Board &gameBoard, Direction dir);


};

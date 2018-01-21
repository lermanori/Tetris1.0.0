/************************************************************************************************************************************************
~~~~ ZShape.h + ZShape.cpp ~~~

~~~IN ORDER TO FULLY UNDERSTAND THIS CLASS - YOU MUST READ Point.H~~~

CLASS MEMBERS:



MEMBER FUNCTIONS:

************************************************************************************************************************************************/
#pragma once
#include "Point.h"
#include "Shape.h"


class Board;

enum { ZSize = 4, numRotations = 4 };

class ZShape : public Shape
{
	Point ZTetrisShape[numRotations][ZSize]; //4 arrays for line. 1 horizontal and 1 vertical
	shapeState state = HORIZONTAL;
	char c = ZSHP;

public:
	ZShape();
	ZShape(int x, int y, char c);
	void move(Direction dir);
	void move(shapeState state, Direction dir);
	void draw(shapeState state, char c)const;
	void draw(char c)const { draw(state, c); }
	const Point& getPoint()const { return ZTetrisShape[state][LTop]; }
	shapeState getState()const { return state; }
	bool canMove(const Board& gameBoard, Direction dir);
	bool checkIfCanMove(shapeState state, const Board& gameBoard, Direction dir);
	ShapeTypes getShapeType()const { return ZSHAPE; }
};
/************************************************************************************************************************************************
~~~~ TShape.h + TShape.cpp ~~~

~~~IN ORDER TO FULLY UNDERSTAND THIS CLASS - YOU MUST READ Point.H~~~

CLASS MEMBERS:



MEMBER FUNCTIONS:

************************************************************************************************************************************************/
#pragma once
#include "Point.h"
#include "Shape.h"


class Board;

enum { TSize = 4, possibleRotations = 4 };

class TShape : public Shape
{
	Point TTetrisShape[possibleRotations][TSize]; //4 arrays for line. 1 horizontal and 1 vertical
	shapeState state = HORIZONTAL;
	char c = TSHP;

public:
	TShape();
	TShape(int x, int y, char c);
	void move(Direction dir);
	void move(shapeState state, Direction dir);
	void draw(shapeState state, char c)const;
	void draw(char c)const { draw(state, c); }
	const Point& getPoint()const { return TTetrisShape[state][MidBottom]; }
	shapeState getState()const { return state; }
	bool canMove(const Board& gameBoard, Direction dir);
	bool checkIfCanMove(shapeState state, const Board& gameBoard, Direction dir);
	ShapeTypes getShapeType()const { return TSHAPE; }
};
/************************************************************************************************************************************************
~~~~ LShape.h + LShape.cpp ~~~

~~~IN ORDER TO FULLY UNDERSTAND THIS CLASS - YOU MUST READ Point.H~~~

CLASS MEMBERS:



MEMBER FUNCTIONS:

************************************************************************************************************************************************/
#pragma once
#include "Board.h"

class Board;

enum { LSize = 4, numShapes = 4 };

class LShape : public Shape
{
	Point LTetrisShape[numShapes][LSize]; //4 arrays for line. 1 horizontal and 1 vertical
	shapeState state = HORIZONTAL;
	char c = LSHP;

public:
	LShape();
	LShape(int x, int y, char c);
	void move(Direction dir);
	void move(shapeState state, Direction dir);
	void draw(shapeState state, char c)const;
	void draw(char c)const { draw(state, c); }
	const Point& getPoint()const { return LTetrisShape[state][LT]; }
	shapeState getState()const { return state; }
	bool canMove(const Board& gameBoard, Direction dir);
	bool checkIfCanMove(shapeState state, const Board& gameBoard, Direction dir);
	ShapeTypes getShapeType()const { return LSHAPE; }
	int markShape(Board& gameBoard);

};
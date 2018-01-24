/************************************************************************************************************************************************
~~~~ LShape.h + LShape.cpp ~~~

~~~IN ORDER TO FULLY UNDERSTAND THIS CLASS - YOU MUST READ shape.H~~~

CLASS MEMBERS:
LTetrisShape- a 2 dimensional array that is holding the four points of the object for every state there is for the shape.
state- the current state of the shape
c- the char that will be written into the matrix and onto the console game.

MEMBER FUNCTIONS:

this object is implementing the interface that is given by shape
ctor- 1) with no parameters 2)parametrs:(int x,int y,char c) :
the constructor sets the points of the four possible states into the 2 dimensional array by the key point of the shape that was decided by us to be the chupchick

behavorial functions;
move- 1)with only direction as parameter,2)with state and direction parametrs:
the function is moving all points of the array if the dir is rotate it will change the state as well.
draw- 1)with state,char.2)with only char:
the function draws the object with selected char.
canMove,checkifcanmove,markShape- all do what thier name say.

setters,getters:
getPoint,getsState.


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
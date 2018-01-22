/************************************************************************************************************************************************
~~~~ Joker.h + Joker.cpp ~~~
Pre-Read recommendation: Point.h

What is?
A joker is a 1x1 shape described with a 'J' char(defined in constants.h).
The joker shape can move down freely in the board and it only stops if the user hits 'S' , or if the joker got to the last line in the board.
If a joker shape was used as the FINAL shape to erase a line, the score only updates with 50pts.


CLASS MEMBERS:
Point object and a char that represeents the joker.

MEMBER FUNCTIONS:
Constructor(empty) - creates a joker at (0,5) with the char 'J' by default (can be changed there)
Constructor - sets a point with parameters (not used in the game).
Move/Draw - being used as a bridge and calls the Point::move / Point::draw function accordingly.
canMove - being used as a bridge and calls Point::canMoveJoker function.


************************************************************************************************************************************************/
#pragma once

#include "Point.h"
#include "Shape.h"

class Joker: public Shape
{
	Point p;
	char c;

public:
	Joker();
	Joker(int x, int y, char c);
	void move(Direction dir);
	void draw(char c) const;
	const Point& getPoint()const { return p; };
	bool canMove(const Board& gameBoard, Direction dir);
	shapeState getState()const { return DUMMYSTATE; }
	ShapeTypes getShapeType()const { return JOKER; }

};

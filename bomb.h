/************************************************************************************************************************************************
~~~~ Bomb.h + Bomb.cpp ~~~
Pre-Read recommendation: Point.h

What is?
	A bomb is a 1x1 shape described with a '@' char (defined in constants.h).
	Once hitting an object on the game board(handeled in gameManager), the bomb explodes and erases every block in 3x3 range from the hiting point.
	If the bomb hits in one of the corners / board edges - in explodes less (depends on the case).
	The score is being reduced by 50 pts for every erased cell.

CLASS MEMBERS:
Point object and a char that represeents the bomb.

MEMBER FUNCTIONS:
Constructor(empty) - creates a bomb at (0,5) with the char '@' by default (can be changed there)
Constructor - sets a point with parameters (not used in the game).
Move/Draw/canMove - being used as a bridge and calls the Point::move / Point::draw / Point::canMove function accordingly.


************************************************************************************************************************************************/
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
	bool canMove(const Board& gameBoard, Direction dir);

};

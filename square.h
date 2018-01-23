/************************************************************************************************************************************************
~~~~ square.h + square.cpp ~~~
this is the class that represent the square object of the tetris shapes.
the square itself is defined by four points.
the constanst that important for this class are the locations of the point in the square-TL,BR...
~~~IN ORDER TO FULLY UNDERSTAND THIS CLASS - YOU MUST READ Point.H~~~

CLASS MEMBERS:
s1- s1 is an array of four points("changeble for coder at enum size at this class").
c- is the char of the line for representaion at console.




MEMBER FUNCTIONS:
ctor()-setting all four points of the square at a default location from BL and going clockwise changeble over ther,and sets the char to be SQR who is defind as a constant char at constants.h.
ctor(x,y,c)-setting all points by the BL corner that is acceptable from programer/user in int x,int y, char c and goes clockwise set the rest of the square.
move(dir)- first of all the move of is moving all four points by moving each point(explined in Point.h) in s1 array by drawin each point as a blank space than move the point according to the direction (a constant defind at constants.h)
		   and drawing them back at the new location of the point.
getPoint()-is a getter for point returning BL
canMove((const Board &,Direction)- check if the square can move to a spesific direcrtion and returns a boolean value for the abilty to move.
doing that by holding a array of 4 boolean values that is set by canMove of every point in the array , and then checkin with And if one of them is false.
the purpose is to make a definition "the square can move if all is 4 point can move".




************************************************************************************************************************************************/

#pragma once
#include "Board.h"


enum { size = 4 };


class Square : public Shape
{
	Point s1[size];

	char c;

public:
	Square();
	Square(int x, int y, char c);
	void move(Direction dir);
	void draw(char c)const;
	const Point& getPoint()const { return s1[BL]; }
	bool canMove(const Board& gameBoard, Direction dir);
	shapeState getState()const { return DUMMYSTATE; }
	ShapeTypes getShapeType()const { return SQUARE; }
	int markShape(Board& gameBoard);

	

};	
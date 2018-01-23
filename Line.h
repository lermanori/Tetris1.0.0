/************************************************************************************************************************************************
~~~~ Line.h + Line.cpp ~~~
This class represents the Line ( ---- ) object of the tetris shapes.
The line is defined as 4 point objects,  in two different states.
Once a line object is born, the class creates two lines according to 2 different states - Vertical and Horizontal.
As default, the line appears on the screen in a Horizontal state, and if the user clicks the rotation button,
the draw function 'erases' the old state line from the screen and draws the new state.

The constants that are important for this class are in constants.h - lineStates, lineParts... (LL=left left, LR=left right... from left to right).

~~~IN ORDER TO FULLY UNDERSTAND THIS CLASS - YOU MUST READ Point.H~~~

CLASS MEMBERS:

line[2][lineSize] - A two dimensional array , each array represents a vertical line or a horizontal line.
state - horizontal by default, can be changed by user choice.
c- is the char of the line for representaion at console.

MEMBER FUNCTIONS:
ctor() - Sets 2 lines - First line is Horizontal by default location from LL and going left to right. Second line is Vertical and it is set from bottom upwards.
ctor(x,y,c)- Sets 2 lines according to given values. Not used in the game.
move(dir) - Moves the line points considering its state (switch-case). First it erases the old line, moving each point (in Point.h) , and drawing it again
			in the new location.
draw(char)- Draws the line on the screen considering it's state.
getPoint()-is a getter for point returning LL point (most left / most bottom - depending on the state).
getState()- is a getter for the line state.
canMove((const Board &,Direction)- check if the line can move to a spesific direcrtion and returns a boolean value for the abilty to move.
doing that by holding a array of 4 boolean values that is set by canMove of every point in the array , and then checking with And if one of them is false.
the purpose is to make a definition "the line can move if all is 4 point can move".

************************************************************************************************************************************************/
#pragma once
#include "Board.h"




class Board;

enum { lineSize = 4, numLines = 2 };

class Line : public Shape
{
	Point line[numLines][lineSize]; //2 arrays for line. 1 horizontal and 1 vertical
	shapeState state = HORIZONTAL;
	char c;

public:
	Line();
	Line(int x, int y, char c);
	void move(Direction dir) ;
	void draw(char c)const ;
	const Point& getPoint()const  { return line[state][LL]; }
	shapeState getState()const  { return state; }
	bool canMove(const Board& gameBoard, Direction dir) ;
	ShapeTypes getShapeType()const  { return LINE; }
	int markShape(Board& gameBoard);

};
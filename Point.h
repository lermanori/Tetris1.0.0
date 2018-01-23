/************************************************************************************************************************************************
~~~~ point.h + point.cpp ~~~
point is the class that handles the point ,who is the smallest building block that we used, every tetris object is build from certion points.
and the tetris object functions are all bridges to call the base functions of point ,for example if we moved a line to the left we actually told the line to move his four points using move function of point class. 

CLASS MEMBERS:
x,y- x,y cordinates of the screen console the top left corner is(0,0) and goes positive to the right, and y goes positive down.
c- the char that whould be representing the point on the screen
MEMBER FUNCTIONS:
ctor()- setting x y and c to default values changble over there
ctor(x,y,c)- setting x as x etc. and printing the point
set(x,y,c)-setting x as x etc.
getters for x,y
draw- goes to the point using gotoxy(utils.h) and print the char at cursor  new location.
move-move is changing the x,y cordinates of the point by this logic; adding the diffrence between the locations to the point by switching the direction. the diffrence is stored at direction_var and is set by switching the direction an then added to the point.
canMove- can move is checking if  the gameboard point is empty using the same logic as move and the function havespace- who check if there is a space at the matrix
canmoveJoker- there is a diffrent can move for joker because the joker can move on pieces while the other parts cant.
				the actual diffrence is that the can move joker calls havespace joker and not have space.
getposinmatrix- is for  translating the cordinates of the screen into the cordinates of the matrix(substracts the borders out of the actual number)
ther is overload for this function one with point and one with actual coordinates.
************************************************************************************************************************************************/
#pragma once

#include <iostream>
#include "utils.h"
#include "constants.h"



class Board;

class Point
{
	int x, y;
	char c;
	int direction_x = 0;
	int direction_y = 0;

public:
	Point() { x = MIN_X+5; y = MIN_Y; c = 'N'; }
	Point(int x, int y, int c)
	{
		set(x, y, c);
		this->draw();
	}
	void set(int x, int y, int c)
	{
		this->x = x;
		this->y = y;
		this->c = c;
	}
	int getX()const { return x; }
	int getY()const { return y; }
	void draw(char c)const
	{
		gotoxy(x, y);
		std::cout << c;
		std::cout.flush();
	}
	void draw()const
	{
		draw(c);
	}
	void move(Direction dir);
	bool canMove(const Board& gameBoard, Direction dir);
	bool canMoveJoker(const Board& gameBoard, Direction dir);
	void getPosInMatrix(const Point& pt, int &x, int &y);
	void getPosInMatrix(int x, int y, int & xNewPos, int & yNewPos);
};
/******************************************************************************
14/12/17 - 1st Session
GOAL: making the framework, movint shapes on the screen .
15/12/17 - ori: making the shape factory class work. 
16/12/17 - ori: thinkng about a class named board who will include the static matrix(the type of the matrix is important exemple: a char matrix for the signs) of the board and the vars for the game like score and fallen items
class methods will be ctor- creating boards game and initaializing the vars, method: when a block cant move(end lif of block) its point will be send to the matrix and drawed over there.
also should be a method to check if a block exists in a certion range of points(dynamic borders)
17/12/17 - TEAM: added board class. Need to write set functions to score/fallenItems. Need to find a way to update the static matrix according to the shape.
also should draw the matrix including the ongoing updates.

********************************************************************************/


#pragma once
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "constants.h"
#include "square.h"	
#include "ShapeFactory.h"
#include "Board.h"

Direction keyPressedToDirection(char keyPressed);
enum { ESC = 27 };

int main()
{
	bool gameOn = true;
	bool existingShape = false;
	bool cantMove = false;
	bool canMove1 = true;
	char keyPressed = 0;
	Direction dir;
	ShapeFactory* shape = nullptr;
	Board board;

	while (gameOn)
	{

		while (keyPressed != ESC)
		{
			if (existingShape == false)//generating parts
			{ 
         		shape = new ShapeFactory;
				existingShape = true;
				board.setFallenItems(board.getFallenItems()+1);
			}

			Sleep(400);
			dir = keyPressedToDirection(keyPressed);
			canMove1 = shape->canMove(board, dir);
			if (canMove1)
			{
				shape->move(dir);
			}
		//	cantMove = shape->move(dir);

			if (!canMove1)//end life of moving shape
			{
				shape->draw(' ');
				board.markShape(*shape);
				delete shape;
				existingShape = false;
			}
			keyPressed = 0;

			if (_kbhit())
			{
				keyPressed = _getch();
			}
		}
	}
	system("pause");
}

//gets an input from keyboard and returns the relevant direction accordingly. Default returnd value
//will be STAY.
Direction keyPressedToDirection(char keyPressed)
{
	switch (keyPressed)
	{
	case 'w':
		return UP;
		break;
	case 'd':
		return RIGHT;
		break;
	case 's':
		return DOWN;
		break;
	case 'a':
		return LEFT;
		break;
	default:
		return STAY;
		break;

	}
}
/******************************************************************************
14/12/17 - 1st Session
GOAL: making the framework, movint shapes on the screen .
15/12/17
********************************************************************************/


#pragma once
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "constants.h"
#include "square.h"	
#include "ShapeFactory.h"

Direction keyPressedToDirection(char keyPressed);
enum { ESC = 27 };

int main()
{

	
	bool gameOn = true;
	bool existingShape = false;
	bool cantMove = false;
	char keyPressed = 0;
	Direction dir;
	ShapeFactory* shape = nullptr;
	
	while (gameOn)
	{
		while (keyPressed != ESC)
		{
			if (existingShape == false)///generating parts
			{ 
         		shape = new ShapeFactory;
				existingShape = true;
			}

			Sleep(100);
			dir = keyPressedToDirection(keyPressed);
			cantMove = shape->move(dir);

			if (cantMove == true)//end life of moving shape
			{
				shape->draw(' ');
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
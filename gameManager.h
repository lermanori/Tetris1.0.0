#pragma once
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
#include "Board.h"
#include <time.h>
#include <stdlib.h>
	enum { ESC = 27 };


class GameManager
{
	bool gameOn = false;
	bool gameFailure = false;
	bool quitGame = false;
	bool existingShape = false;

	char keyPressed = 0;
	unsigned int gameSpeed = 200;
	Direction dir;
	Direction dummy;
	ShapeFactory* shape = nullptr;
	Board board;

public:
	GameManager();
	void resetGame();
	void setGameOn() { gameOn = true; }
	void pauseGame() { gameOn = false; }
	void leaveGame() { quitGame = true; }
	void setSpeed(int newSpeed) {gameSpeed = newSpeed; gotoxy(SCORE_X - 7, SCORE_Y - 3); std::cout << gameSpeed; }
	int getSpeed() { return gameSpeed; }
	void runGame();
	Direction menu(char &keyPressed);
};
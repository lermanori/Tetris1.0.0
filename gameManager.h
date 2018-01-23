/************************************************************************************************************************************************
~~~~ gameManager.h + gameManager.cpp ~~~
Pre-Read recommendation: Board.h

What is?
	The Game Manager is in charge of all the logic side of the game.
	Events handled in
Method:
	
CLASS MEMBERS:
Constructor - plants the random seed based on the computers time.

MEMBER FUNCTIONS:

runGame - Responsible of the gameplay. In some places, the function updates the score according to the given scenario.
		Method:
		1. While User didnt hit '9' (9=quit game)
			1.1. If game is on (User pressed start)
				1.1.1. If there's no shape
					1.1.1.1 Generate a shape
					1.1.1.2 Set flag True
					1.1.1.3 Update fallen items
				1.1.2 If the shape can move down
					1.1.2.1 Move down
				1.1.3 Get input from the user
				1.1.4 If pressed 's' and shape is a joker
					1.1.4.1 Mark the joker in the current location in the matrix
					1.1.4.2 Kill the shape and set the flag
				1.1.5 Else if the shape can move to the requested direction
					1.1.5.1 Move to the requested direction
				1.1.6 Else (shape is not joker and cant move to requested direction)
					1.1.6.1 If the shape can move down
						1.1.6.1.1 Move down
					1.1.6.2 Else (the shape is about to die ^_^ )
						1.1.6.2.1 If the shape is a bomb ---> EXPLODE
						1.1.6.2.2 Draw a blank space on the current shape position
						1.1.6.2.3 If shape is not bomb ---> MARK IT IN THE GAME BOARD MATRIX (PRINTS THE GAMEBOARD AFTER)
						1.1.6.2.4 Kill the shape (free the allocation) and set flag as false
				1.1.7 Check if the user hit game over
					1.1.7.1 If user has failed the game
						1.1.7.1.1 Set gameOn flag as false
						1.1.7.1.2 Seset the game details
				1.1.8 Get input from buffer
			1.2 Else (No Game --- MENU MODE)
				1.2.1 Get input from the user
Menu - Gets an input from keyboard and returns the relevant direction accordingly. Default returnd value will be STAY direction.
************************************************************************************************************************************************/
#pragma once

#include <conio.h>
#include <iostream>
#include <Windows.h>
#include "constants.h"
#include "ShapeFactory.h"
#include <time.h>
#include <stdlib.h>

enum { ESC = 27 };


class GameManager
{
	bool gameOn = false; //Indicates weather the game is on or not(according to the player's choice - Menu Keys 1/2).
	bool gameFailure = false;//Indicates that the player has failed.
	bool quitGame = false;//Indicates that the player pressed 9 in order to close the game.
	bool existingShape = false;//Indicates weather there's a shape alive or not.

	char keyPressed = 0;
	double gameSpeed = 0.75; //gameSpeed - Speed Range: 100-200, jumps of 25m/s per click

	Direction dir; //direction of movement
	Direction dummy;

	Shape* shape = nullptr; //Every time when a shape gets generated, we allocate memory for it. Before we kill it we release the allocation and allocate again.
	Board board; //game board - explained in board.h
	int erasedLines = 0;
	time_t saveTime, currTime;


public:
	GameManager();
	void resetGame();
	void setGameOn() { gameOn = true; }
	void pauseGame() { gameOn = false; }
	void leaveGame() { quitGame = true; }
	void setSpeed(double newSpeed) {gameSpeed = newSpeed; gotoxy(SCORE_X - 7, SCORE_Y - 3); std::cout << gameSpeed*100; }
	double getSpeed() { return gameSpeed; }

	void runGame();
	Direction menu(char &keyPressed);
};
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
				1.1.2 Game Rythm: if the difference between the current time to the time in the beginning of the loop is greater than gameSpeed
					1.1.2.1 Move the shape down
				1.1.3 Get input from the user
				1.1.4 If pressed SPACE(HARD DROP)
					1.1.4.1 While the shape can move down
						1.1.4.1.1 Move Down
						1.1.4.1.2 Update Score : 2*(num of lines)
					1.1.4.2 Mark the shape
					1.1.4.3 Update the score
					1.1.4.4 Kill the shape and set the flag
				1.1.5 If pressed 's' and shape is a joker
					1.1.5.1 Mark the joker in the current location in the matrix
					1.1.5.2 Kill the shape and set the flag
				1.1.6 Else if the shape can move to the requested direction
					1.1.6.1 Move to the requested direction
				1.1.7 Else (shape is not joker and cant move to requested direction)
					1.1.7.1 If the shape can't move down
						1.1.7.1.1 If there is input in the buffer
							1.1.7.1.1.1 use the menu
					1.1.7.2 While the shape can move to a direction, and user clicked on something
						1.1.7.2.1 Move to the given dir
						1.1.7.2.2 If there is input in the buffer
							1.1.7.2.2.1 use the menu
						1.1.7.2.3 Else --> dir=STAY(noInput)
					1.1.7.3 If the shape can't move down - 
						1.1.7.3.1 Mark it in the matrix
						1.1.7.3.2 Kill the shape (free the allocation) and set flag as false

				1.1.8 Check if the user hit game over
					1.1.8.1 If user has failed the game
						1.1.8.1.1 Set gameOn flag as false
						1.1.8.1.2 Seset the game details
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
	double gameSpeed = 0.75; //gameSpeed - Speed Range: 0.25-1.25, jumps of 0.25m/s per click

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
	void setSpeed(double newSpeed);
	double getSpeed() { return gameSpeed; }

	void runGame();
	Direction menu(char &keyPressed);
};
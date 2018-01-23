/************************************************************************************************************************************************
~~~~ Board.h + Board.cpp ~~~
This class is responsible for handling the game menu, game board and score board.
~~~IN ORDER TO FULLY UNDERSTAND THIS CLASS - YOU MUST READ MATRIX.H~~~

CLASS MEMBERS:
gameBoard - A Matrix object. Represents the relevant 10x15 game board in the console and a full line indicator array. Matrix characteristics explained in Matrix.h .



MEMBER FUNCTIONS:
Constructor - calling the 3 private functions in order to draw the interface.

markShapeAndUpdateScore - Responsible of marking the shpae in the game board (will be explained in matrix.h), and to update the score.
							Method: using the numeric value returned from Matrix::markShape function and update the score according to the following logic:
							Single Line = 100pts , Double Line = 300pts, Three Lines = 500 Lines, Four Lines = 800pts.
							If a joker was used as the final shape to erase a line, score is updated by 50pts instead of 100.
							(but if a joker is not the last shape, updates as usual).

explodeBomb - Responsible of erasing cells when the bomb explodes.
							Method: Gets a the location of the bomb on the screen, and converts it into the relevant place in the game board matrix.
							The function then searches between 9 different bombing situations in the game board matrix - Starts on the Top-Left side,
							and goes clockwise to all the other cases(explained in the code).
							Once found the relevant situation, the function calls Matrix::eraseCell in order to erase the cells surrounding the bomb point
							in a clockwise order. The function collects the number of erased cells in order to update the score later.
							The function updates the score according to the game rules: reduces 50pts for every cell erased
							Eventually the function prints the updated game board matrix.

************************************************************************************************************************************************/

#pragma once
#include "utils.h"
#include "constants.h"
#include "Point.h"
#include "Shape.h"

#include <iostream> 
#include <iomanip>		// for setw and setfill functions used in setScore/setFallenItems/drawScoreBoard

class ShapeFactory;
class Point;

class Board
{
	class Matrix
	{
		//	char** gameBoard;
	public:
		char gameBoard[HEIGHT][WIDTH];
		int indicators[HEIGHT];
		void printMatrix();
		Matrix() { setMatrix(); }// matrix of spaces
		void setMatrix(char ch = SPACE);
	//	int markShape(const Shape& shape);
		void getPosInMatrix(const Point& pt, int &x, int &y);
		//static void getPosInMatrix(int x, int y, int &xNewPos, int&yNewPos);
		bool haveSpace(int x, int y)const;
		bool haveSpaceJoker(int x, int y)const;
//		void updateIndicators(const Shape& shape);
		int checkIfFullLine();

		void eraseLine(int i);
		int eraseCell(int i, int j);
	

		char* operator[] (int row) { return gameBoard[row]; }

	};
	Matrix gameBoard;
	int fallenItems = 0;
	int score = 0;

	//Screen Positions for the fallen items and score counters.
	const int scorePosX = SCORE_X;
	const int scorePosY = SCORE_Y;
	const int itemsPosX = FALLEN_ITEMS_X;
	const int itemsPosY = FALLEN_ITEMS_Y;

	//Private functions that are responsible for printing the game interface
	void drawBoard();
	void drawMenu();
	void drawScoreBoard();	



public:
	Board();
	void printMatrix() { gameBoard.printMatrix(); }
	void cleanScore() { setScore(EMPTY); }; 
	void setScore(int newScore);
	void setFallenItems(int numItems) { fallenItems = numItems; gotoxy(FALLEN_ITEMS_X, FALLEN_ITEMS_Y); std::cout << std::setfill('0') << std::setw(4) << fallenItems; };
	void cleanFallenItems() { setFallenItems(0); };
	int getScore() { return score; };
	int getFallenItems() { return fallenItems; };

	int checkLine() { return gameBoard.checkIfFullLine(); }
	void updateScore(int erasedLines, const Shape& shape);

	void explodeBomb(const Point &pt);
	
	char* operator() (int row) { gameBoard.indicators[row]++;  return gameBoard.gameBoard[row]; }
	char* operator[] (int row) { return gameBoard.gameBoard[row]; }
	
	/*
	The next functions are memumashot in matrix.h. They are being defined here in order to use as a bridge between objects.
	*/
	bool haveSpace(int x, int y)const;
	bool haveSpaceJoker(int x, int y)const;
	bool checkGameFailure();

	void showFailureMessage();

	
};
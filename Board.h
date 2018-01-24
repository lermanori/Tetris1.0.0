/************************************************************************************************************************************************
~~~~ Board.h + Board.cpp ~~~

~~~~~~~READ POINT.H before this file~~~~~~~~~
This class is responsible for handling the game menu, game board and score board.
Board class is also responsible of creating and handling the matrix. (By containing class Matrix inside it).


CLASS MEMBERS:
gameBoard - A Matrix object. Represents the relevant 10x15 game board in the console and a full line indicator array. Matrix characteristics explained in Matrix.h .



MEMBER FUNCTIONS:
Constructor - calling the 3 private functions in order to draw the interface.

OPERATORS:
[] - When the user tries to access a Board object with [index], this operator returns the gameBoard Matrix in the relevant  index
	 (this operator is mainly used in order to read from the matrix).
() - When the user tries to access a Board object with (index), this operator reteurns the gameBoard Matrix in the relevant index and
	 updates the relevant row in the indicators array with ++ ( this operator is mainly used in order to write to the matrix).

explodeBomb - Responsible of erasing cells when the bomb explodes.
							Method: Gets a the location of the bomb on the screen, and converts it into the relevant place in the game board matrix.
							The function then searches between 9 different bombing situations in the game board matrix - Starts on the Top-Left side,
							and goes clockwise to all the other cases(explained in the code).
							Once found the relevant situation, the function calls Matrix::eraseCell in order to erase the cells surrounding the bomb point
							in a clockwise order. The function collects the number of erased cells in order to update the score later.
							The function updates the score according to the game rules: reduces 50pts for every cell erased
							Eventually the function prints the updated game board matrix.



~~~~ CLASS MATRIX ~~~

What is?
This class represents the game board as a 15X10 char matrix(gameBoard), and an additional 15 "lines" array(indicators). The idea is that every shape of the game
is marked in the matrix in the relevant place, and then drawn to the screen. 
For every marked point in the matrix (For Example: a line is 4 points), the Indicators array in the relevant "line" gets updated by adding 1 to its value.
The idea of the indicators array is that once a cell in the array gets to the value "10", it means that the line is full and it needs to be erased.


CLASS MEMBERS:
gameBoard[15][10] - A char matrix represents the board.
indicators[15] - indicates for how many marked points the are in a given line.

MEMBER FUNCTIONS:
ctor() - Marks every cell in the gameBoard matrix with a SPACE, and every cell in the indicators array to 0.
setMatrix(ch) - Marks every cell in the gameBoard matrix with a given char, and every cell in the indicators array to 0.
markShape(const ShapeFactory& shape) - Marks a shape in the matrix in the relevant place.
				For any given shape, the function updates the indicators array with the number of points in every line, and then
				marks the relevant places of the shape into the matrix(It uses getPosInMatrix function that will be explained later).
				different cases are explained inside the function implementation.
				Returned Value: markShape returns an int - it calls checkIfFullLine that returns the number of points in the given line.
getPosInMatrix() - gets a Point object and returns byRef the relevant places of the point in the gameBoard matrix.
				calculation:
					X-leftBorder(32) = column in matrix
					Y-topBorder(4) = line in matrix
haveSpace(int, int) - returns a boolean value if the point is within the the borders and the matrix relevant cells are marked with a space.


checkIfFullLine() - holds a counter and it checks every cell in the indicators array, in case the value in a given cell is 10,
				  it calls eraseLine to erase it and sets a boolean flag to be true. If the flag is true the function will print the matrix
				  to show the updated matrix on the screen
				  returned value is the counter.

checkGameFailure()- will only return true (FAILURE) if the value in indicators[0] is different than 0.

eraseLine(int) - erases the first line of the matrix (puts spaces inside instead of old value) and than it goes in a loop on the matrix line,
				 from the given line (int i) 'upwards' to the first line. For every line it copies the line to the line above it, so at the end
			     the most bottom line will be erased. The function is also responsible to update the indicators array to match the values.

eraseCell(int, int) [RELEVANT TO BOMB] - gets an x,y point in the game matrix and 'erases' the value inside - it puts a SPACE instead.
										 the function only "erases" a cell if it wasn't empty - in case of an empty cell the function does nothing.
										 if needed, it also updates the relevant indicators cell with --.
										 retVal is 1 in case of an erased cell, and 0 if no cell was erased.

printMatrix() - prints the matrix.
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
	public:
		char gameBoard[HEIGHT][WIDTH];
		int indicators[HEIGHT];
		//Member Functions:
		void printMatrix();
		Matrix() { setMatrix(); }// matrix of spaces
		void setMatrix(char ch = SPACE);
		void getPosInMatrix(const Point& pt, int &x, int &y);
		bool haveSpace(int x, int y)const;
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
	void explodeBomb(const int x, const int y);
	char* operator() (int row) { gameBoard.indicators[row]++;  return gameBoard.gameBoard[row]; }
	char* operator[] (int row) { return gameBoard.gameBoard[row]; }
	
	bool checkGameFailure();
	void showFailureMessage();
	
	//The next function is implemented in matrix.h. It's being defined here in order to use as a bridge between objects.
	
	bool haveSpace(int x, int y)const { return gameBoard.haveSpace(x, y); }


	
};
/************************************************************************************************************************************************
~~~~ Matrix.h + Matrix.cpp ~~~
READ POINT.H before this file.

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
getPosInMatrix() BOTH - gets an x,y (either is integers or a Point object) and returns byRef the relevant places of the point in the gameBoard matrix.
				calculation:
					X-leftBorder(32) = column in matrix
					Y-topBorder(4) = line in matrix
haveSpace(int, int) - returns a boolean value if the point is within the the borders and the matrix relevant cells are marked with a space.
haveSpaceJoker(int, int) - returns a boolean value if the joker point is in the borders. JOKER CAN OVERRIDE EXISTING SHAPES.

updateIndicators(const shapeFactory&) - gets a shape and updates every cell in the indicators array with the number of points added to the cell.
										NOTE: the joker shape is not being handled there, as its being handeled in markShape func.

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
/*


class Matrix
{
	char gameBoard[15][10];
	//	char** gameBoard;
	int indicators[15];

public:
	Matrix(); // matrix of spaces
//	~Matrix();
	void setMatrix(char ch = SPACE);
	int markShape(const Shape& shape);
	void getPosInMatrix(const Point& pt, int &x, int &y);
	void getPosInMatrix(int x, int y, int &xNewPos, int&yNewPos);
	bool haveSpace(int x, int y)const;
	bool haveSpaceJoker(int x, int y)const;

	void updateIndicators(const Shape& shape);
	int checkIfFullLine();
	bool checkGameFailure();
	void eraseLine(int i);
	int eraseCell(int i, int j);
	void printMatrix();

};
*/
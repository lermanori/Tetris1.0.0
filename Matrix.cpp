#pragma once
#include "Matrix.h"



Matrix::Matrix()
{
	//NO NEED FOR DYNAMIC ALLOCATION - CONSIDER DELETION
	//gameBoard = new char*[HEIGHT];
	//for (int i = 0; i < HEIGHT; i++)
	//{
	//	gameBoard[i] = new char[WIDTH];
	//}

	for (int i = 0; i < HEIGHT; i++)
	{
		indicators[i] = EMPTY;
		for (int j = 0; j < WIDTH; j++)
			gameBoard[i][j] = SPACE;
	}

}
//NO NEED FOR DESTRUCTOR
//Matrix::~Matrix()
//{
//		for (int i = 0; i < HEIGHT; i++)
//		{
//			delete[] gameBoard[i];
//		}
//		delete[] gameBoard;
//}

void Matrix::setMatrix(char ch)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		indicators[i] = EMPTY;
		for (int j = 0; j < WIDTH; j++)
			gameBoard[i][j] = ch;
	}
}


void Matrix::markShape(const ShapeFactory& shape)
{
	const int shapeType = shape.getShapeType();
	int x = 0, y = 0;
	LineState state = (LineState)shape.getShapeState();

	updateIndicators(shape);

	switch (shapeType)
	{
	case SQUARE:
		getPosInMatrix(shape.getPoint(), x, y);
		gameBoard[y][x] = SQR;
		gameBoard[y][x + 1] = SQR;
		gameBoard[y - 1][x + 1] = SQR;
		gameBoard[y - 1][x] = SQR;

		shape.draw(SQR);
		break;
	case LINE:
		getPosInMatrix(shape.getPoint(), x, y);
		switch (state)
		{
		case HORIZONTAL:
			gameBoard[y][x] = LN;
			gameBoard[y][x + 1] = LN;
			gameBoard[y][x + 2] = LN;
			gameBoard[y][x + 3] = LN;
			break;

		case VERTICAL:
			gameBoard[y][x] = LN;
			gameBoard[y - 1][x] = LN;
			gameBoard[y - 2][x] = LN;
			gameBoard[y - 3][x] = LN;
			break;

		}
		shape.draw(LN);
		break;

	case BOMB:
		getPosInMatrix(shape.getPoint(), x, y);
		gameBoard[y][x] = BMB;
		shape.draw(BMB);
		break;
	case JOKER:
		getPosInMatrix(shape.getPoint(), x, y);
		if (gameBoard[y][x] == SPACE)
			indicators[y]++;
		gameBoard[y][x] = JKR;
		shape.draw(JKR);
		this->printMatrix();
		break;

	}

	checkIfFullLine();
}
void Matrix::getPosInMatrix(const Point& pt, int &x, int &y)
{
	x = pt.getX() - MIN_X;
	y = pt.getY() - MIN_Y;
}

void Matrix::getPosInMatrix(int x, int y, int & xNewPos, int & yNewPos)
{
	xNewPos = x - MIN_X;
	yNewPos = y - MIN_Y;
}

bool Matrix::haveSpace(int x, int y) const
{
	if (x < 10 && x > -1 && y >= 0 && y < 15 && (gameBoard[y][x] == SPACE))
		return true;
	else
		return false;
}

bool Matrix::haveSpaceJoker(int x, int y) const
{
	if (x < 10 && x > -1 && y >= 0 && y < 15)
		return true;
	else
		return false;
}

void Matrix::updateIndicators(const ShapeFactory &shape)
{
	const int shapeType = shape.getShapeType();
	int x = 0, y = 0;
	LineState state = (LineState)shape.getShapeState();

	getPosInMatrix(shape.getPoint(), x, y);

	switch (shapeType)
	{
	case SQUARE:
		indicators[y]++;
		indicators[y - 1]++;
		indicators[y]++;
		indicators[y - 1]++;
		break;
	case LINE:
		switch (state)
		{
		case HORIZONTAL:
			indicators[y] += 4;
			break;
		case VERTICAL:
			indicators[y]++;
			indicators[y - 1]++;
			indicators[y - 2]++;
			indicators[y - 3]++;
			break;
		}
		break;
	case BOMB:
		indicators[y]++;
		break;
	case JOKER:
		//handling this case manually in markShape function - joker case
		break;
	}	
//	checkIfFullLine();
}

void Matrix::checkIfFullLine()
{
	bool fullLine = false;
	for (int i = 0; i < HEIGHT; i++)
	{
		if (indicators[i] == FULL)
		{
			eraseLine(i);
			fullLine = true;
		}
	}
	if (fullLine)
		printMatrix();
}

bool Matrix::checkGameFailure()
{
	if (indicators[START] != EMPTY)
		return false;
	else
		return true;
}

//the matrix is now static and no dynamically allocated. 
//if this is okay we have to delete irrelevant notes.
void Matrix::eraseLine(int i)
{

	//	delete gameBoard[0];
	//	gameBoard[0] = new char[WIDTH];
	for (int j = 0; j < WIDTH; j++)
		gameBoard[0][j] = SPACE;

	for (int line = i; line > 0; line--)
	{
		for (int k = 0; k < WIDTH; k++) //constant number of actions therefore it's okay to have for inside for loop
		{	
			gameBoard[line][k] = gameBoard[line - 1][k];
		}
		indicators[0] = EMPTY;
		indicators[line] = indicators[line - 1];

		//		gameBoard[line] = gameBoard[line-1];
		//		indicators[line] = indicators[line-1];
	}

}

void Matrix::eraseCell(int j ,int i) //gets an index in the matrix and puts space in the i,j element in the matrix.
{
	 if (gameBoard[i][j] != SPACE)
		 indicators[i]--;
	 this->gameBoard[i][j] = SPACE;

}

void Matrix::printMatrix()
{
	gotoxy(MIN_X, MIN_Y);
	for (int i = 0; i < HEIGHT; i++)
	{
		gotoxy(MIN_X, MIN_Y + i);

		for (int j = 0; j < WIDTH; j++)
		{
			std::cout << gameBoard[i][j];
		}
	}
}

#pragma once
#include "Matrix.h"



Matrix::Matrix()
{
	gameBoard = new char*[HEIGHT];
	for (int i = 0; i < HEIGHT; i++)
	{
		gameBoard[i] = new char[WIDTH];
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		indicators[i] = EMPTY;
		for (int j = 0; j < WIDTH; j++)
			gameBoard[i][j] = SPACE;
	}

}

Matrix::~Matrix()
{
		for (int i = 0; i < HEIGHT; i++)
		{
			delete[] gameBoard[i];
		}
		delete[] gameBoard;
}

void Matrix::markShape(const ShapeFactory& shape)
{
	const int shapeType = shape.getShapeType();
	int x = 0, y = 0;
	LineState state = (LineState)shape.getShapeState();

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
			gameBoard[y + 1][x] = LN;
			gameBoard[y + 2][x] = LN;
			gameBoard[y + 3][x] = LN;
			break;

		}
		shape.draw(LN);
		break;

	case BOMB:
		getPosInMatrix(shape.getPoint(), x, y);
		gameBoard[y][x] = BMB;
		shape.draw(BMB);

	}

	updateIndicators(shape);

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
			indicators[y + 1]++;
			indicators[y + 2]++;
			indicators[y + 3]++;
			break;
		}
		break;
	case BOMB:
		indicators[y]++;
		break;
	}
	checkIfFullLine();
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

void Matrix::eraseLine(int i)
{

	for (int line = i; line > 0; line--)
	{
		gameBoard[line] = gameBoard[line-1];
		indicators[line] = indicators[line-1];
	}
	delete gameBoard[0];
	gameBoard[0] = new char[WIDTH];
	for (int j = 0; j < WIDTH; j++)
		gameBoard[0][j] = SPACE;
	indicators[0] = EMPTY;
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

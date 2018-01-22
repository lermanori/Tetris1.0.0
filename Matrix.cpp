#pragma once
#include "Matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		indicators[i] = EMPTY;
		for (int j = 0; j < WIDTH; j++)
			gameBoard[i][j] = SPACE;
	}

}

void Matrix::setMatrix(char ch)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		indicators[i] = EMPTY;
		for (int j = 0; j < WIDTH; j++)
			gameBoard[i][j] = ch;
	}
}

int Matrix::markShape(const Shape& shape)
{
	const int shapeType = shape.getShapeType();
	int x = 0, y = 0;
	shapeState state = shape.getState();

	updateIndicators(shape);

	switch (shapeType)
	{
	case SQUARE: //ORDER: BL BR TR TL
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
		case HORIZONTAL: // ORDER LL LR RL RR
			gameBoard[y][x] = LN;
			gameBoard[y][x + 1] = LN;
			gameBoard[y][x + 2] = LN;
			gameBoard[y][x + 3] = LN;
			break;

		case VERTICAL:// ORDER BOTTOM UPWARDS
			gameBoard[y][x] = LN;
			gameBoard[y - 1][x] = LN;
			gameBoard[y - 2][x] = LN;
			gameBoard[y - 3][x] = LN;
			break;

		}
		shape.draw(LN);
		break;

	case BOMB://isnt actually being marks - it explodes
		getPosInMatrix(shape.getPoint(), x, y);
		gameBoard[y][x] = BMB;
		shape.draw(BMB);
		break;
	case JOKER://marks the joker in the relevant place and it only updates the indicators array if the joker didnt override an existing point.
		getPosInMatrix(shape.getPoint(), x, y);
		if (gameBoard[y][x] == SPACE)
			indicators[y]++;
		gameBoard[y][x] = JKR;
		shape.draw(JKR);
		this->printMatrix();
		break;

	case LSHAPE:
		getPosInMatrix(shape.getPoint(), x, y);
		switch (state)
		{
		case HORIZONTAL: // 
			gameBoard[y][x] = LSHP;
			gameBoard[y + 1][x] = LSHP;
			gameBoard[y + 1][x + 1] = LSHP;
			gameBoard[y + 1][x + 2] = LSHP;
			break;

		case VERTICAL:// ORDER BOTTOM UPWARDS
			gameBoard[y][x] = LSHP;
			gameBoard[y][x - 1] = LSHP;
			gameBoard[y + 1][x - 1] = LSHP;
			gameBoard[y + 2][x - 1] = LSHP;
			break;

		case INV_HORIZONTAL:
			gameBoard[y][x] = LSHP;
			gameBoard[y + 1][x] = LSHP;
			gameBoard[y + 1][x - 1] = LSHP;
			gameBoard[y + 1][x - 2] = LSHP;
			break;
		case INV_VERTICAL:
			gameBoard[y][x] = LSHP;
			gameBoard[y][x - 1] = LSHP;
			gameBoard[y - 1][x - 1] = LSHP;
			gameBoard[y - 2][x - 1] = LSHP;
			break;
		}
		shape.draw(LSHP);
		break;
	case ZSHAPE:
		getPosInMatrix(shape.getPoint(), x, y);
		switch (state)
		{
		case HORIZONTAL: // 
			gameBoard[y][x] = ZSHP;
			gameBoard[y][x + 1] = ZSHP;
			gameBoard[y + 1][x + 1] = ZSHP;
			gameBoard[y + 1][x + 2] = ZSHP;
			break;

		case VERTICAL:// ORDER BOTTOM UPWARDS
			gameBoard[y][x] = ZSHP;
			gameBoard[y + 1][x] = ZSHP;
			gameBoard[y + 1][x - 1] = ZSHP;
			gameBoard[y + 2][x - 1] = ZSHP;
			break;

		case INV_HORIZONTAL: // 
			gameBoard[y][x] = ZSHP;
			gameBoard[y][x - 1] = ZSHP;
			gameBoard[y - 1][x - 1] = ZSHP;
			gameBoard[y - 1][x - 2] = ZSHP;
			break;

		case INV_VERTICAL:// ORDER BOTTOM UPWARDS
			gameBoard[y][x] = ZSHP;
			gameBoard[y - 1][x] = ZSHP;
			gameBoard[y - 1][x + 1] = ZSHP;
			gameBoard[y - 2][x + 1] = ZSHP;
			break;

		}
		shape.draw(ZSHP);
		break;

	case TSHAPE:
		getPosInMatrix(shape.getPoint(), x, y);
		switch (state)
		{
		case HORIZONTAL: // 
			gameBoard[y][x] = ZSHP;
			gameBoard[y][x + 1] = ZSHP;
			gameBoard[y][x - 1] = ZSHP;
			gameBoard[y - 1][x] = ZSHP;
			break;

		case VERTICAL:// ORDER BOTTOM UPWARDS
			gameBoard[y][x] = ZSHP;
			gameBoard[y + 1][x] = ZSHP;
			gameBoard[y - 1][x] = ZSHP;
			gameBoard[y][x + 1] = ZSHP;
			break;

		case INV_HORIZONTAL: // 
			gameBoard[y][x] = ZSHP;
			gameBoard[y][x - 1] = ZSHP;
			gameBoard[y][x + 1] = ZSHP;
			gameBoard[y + 1][x] = ZSHP;
			break;

		case INV_VERTICAL:// ORDER BOTTOM UPWARDS
			gameBoard[y][x] = ZSHP;
			gameBoard[y - 1][x] = ZSHP;
			gameBoard[y + 1][x] = ZSHP;
			gameBoard[y][x - 1] = ZSHP;
			break;

		}
		shape.draw(TSHP);
		break;

	}
	return checkIfFullLine();

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

void Matrix::updateIndicators(const Shape &shape)
{
	const int shapeType = shape.getShapeType();
	int x = 0, y = 0;
	shapeState state = shape.getState();

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

	case LSHAPE:

		switch (state)
		{
		case HORIZONTAL: // ORDER LL LR RL RR
			indicators[y]++;
			indicators[y + 1]++;
			indicators[y + 1]++;
			indicators[y + 1]++;
			break;

		case VERTICAL:// ORDER BOTTOM UPWARDS
			indicators[y]++;
			indicators[y]++;
			indicators[y + 1]++;
			indicators[y + 2]++;
			break;

		case INV_HORIZONTAL:
			indicators[y]++;
			indicators[y + 1]++;
			indicators[y + 1]++;
			indicators[y + 1]++;
			break;
		case INV_VERTICAL:
			indicators[y]++;
			indicators[y]++;
			indicators[y - 2]++;
			indicators[y - 1]++;
			break;
		}

		break;
	case ZSHAPE:

		switch (state)
		{
		case HORIZONTAL: // ORDER 
			indicators[y]++;
			indicators[y]++;
			indicators[y + 1]++;
			indicators[y + 1]++;
			break;

		case VERTICAL:// ORDER BOTTOM UPWARDS
			indicators[y]++;
			indicators[y + 1]++;
			indicators[y + 1]++;
			indicators[y + 2]++;
			break;

		case INV_HORIZONTAL: // ORDER 
			indicators[y]++;
			indicators[y]++;
			indicators[y - 1]++;
			indicators[y - 1]++;
			break;

		case INV_VERTICAL:// ORDER BOTTOM UPWARDS
			indicators[y]++;
			indicators[y - 1]++;
			indicators[y - 1]++;
			indicators[y - 2]++;
			break;
		}
		break;
	case TSHAPE:

		switch (state)
		{
		case HORIZONTAL: // ORDER 
			indicators[y]++;
			indicators[y]++;
			indicators[y]++;
			indicators[y - 1]++;
			break;

		case VERTICAL:// ORDER BOTTOM UPWARDS
			indicators[y]++;
			indicators[y]++;
			indicators[y - 1]++;
			indicators[y + 1]++;
			break;

		case INV_HORIZONTAL: // ORDER 
			indicators[y]++;
			indicators[y]++;
			indicators[y]++;
			indicators[y + 1]++;
			break;

		case INV_VERTICAL:// ORDER BOTTOM UPWARDS
			indicators[y]++;
			indicators[y]++;
			indicators[y - 1]++;
			indicators[y + 1]++;
			break;
		}



		break;
	}

}

int Matrix::checkIfFullLine()
{
	int counter = 0;
	bool fullLine = false;
	for (int i = 0; i < HEIGHT; i++)
	{
			if (indicators[i] >= FULL)
		{
			eraseLine(i);
			fullLine = true;
			counter++;
		}
	}
	if (fullLine)
		printMatrix();
	return counter;
}

bool Matrix::checkGameFailure()
{
	if (indicators[START] != EMPTY)
		return false;
	else
		return true;
}

void Matrix::eraseLine(int i)
{
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
	}

}

int Matrix::eraseCell(int j, int i) //gets an index in the matrix and puts space in the i,j element in the matrix.
{
	if (gameBoard[i][j] != SPACE)
	{
		indicators[i]--;
		this->gameBoard[i][j] = SPACE;
		return 1;
	}
	else
		return 0;
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

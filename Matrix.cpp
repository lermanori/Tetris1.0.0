#pragma once
#include "Matrix.h"



Matrix::Matrix()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
			gameBoard[i][j] = SPACE;
	}
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

}
void Matrix::getPosInMatrix(const Point& pt, int &x, int &y)
{
	x = pt.getX() - LEFTBORDER;
	y = pt.getY() - TOPBORDER;
}

void Matrix::getPosInMatrix(int x, int y, int & xNewPos, int & yNewPos)
{
	xNewPos = x - LEFTBORDER;
	yNewPos = y - TOPBORDER;
}

bool Matrix::haveSpace(int x, int y) const
{
	if ((gameBoard[y][x] == SPACE)&&x<10&&x>=-1&&y>=0&&y<15)
		return true;
	else
		return false;
}

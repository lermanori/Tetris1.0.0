#pragma once
#include "constants.h"
#include "ShapeFactory.h"

class Point;

class Matrix 
{
//	char gameBoard[15][10];
	char** gameBoard;
	int indicators[15];

public:
	Matrix(); // matrix of spaces
	void markShape(const ShapeFactory& shape);
	void getPosInMatrix(const Point& pt, int &x, int &y);
	void getPosInMatrix(int x, int y, int &xNewPos, int&yNewPos);
	bool haveSpace(int x, int y)const;
	void updateIndicators(const ShapeFactory& shape);
	void checkIfFullLine();
	void eraseLine(int i);
	void printMatrix();
};
#pragma once
#include "constants.h"
#include "ShapeFactory.h"

class Point;

class Matrix
{
	char gameBoard[15][10];
	//	char** gameBoard;
	int indicators[15];

public:
	Matrix(); // matrix of spaces
//	~Matrix();
	void setMatrix(char ch = SPACE);
	void markShape(const ShapeFactory& shape);
	void getPosInMatrix(const Point& pt, int &x, int &y);
	void getPosInMatrix(int x, int y, int &xNewPos, int&yNewPos);
	bool haveSpace(int x, int y)const;
	void updateIndicators(const ShapeFactory& shape);
	void checkIfFullLine();
	bool checkGameFailure();
	void eraseLine(int i);
	void eraseCell(int i, int j);
	void printMatrix();

};
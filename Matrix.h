#pragma once
#include "constants.h"
#include "ShapeFactory.h"

class Matrix 
{
	char gameBoard[15][10];

public:
	Matrix(); // matrix of spaces
	void markShape(ShapeFactory shape);


};
#include "Matrix.h"

Matrix::Matrix()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 10; j++)
			gameBoard[i][j] = SPACE;
	}
}

void Matrix::markShape(ShapeFactory shape)
{
	

}

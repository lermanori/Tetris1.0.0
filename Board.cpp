#pragma once
#include "Board.h"
//MATRIX MEMBER FUNCTIONS
void Board::Matrix::setMatrix(char ch)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		indicators[i] = EMPTY;
		for (int j = 0; j < WIDTH; j++)
			gameBoard[i][j] = ch;
	}
}

int Board::Matrix::markShape(const Shape& shape)
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

void Board::Matrix::getPosInMatrix(const Point& pt, int &x, int &y)
{

	x = pt.getX() - MIN_X;
	y = pt.getY() - MIN_Y;
}

void Board::Matrix::getPosInMatrix(int x, int y, int & xNewPos, int & yNewPos)
{
	xNewPos = x - MIN_X;
	yNewPos = y - MIN_Y;
}

bool Board::Matrix::haveSpace(int x, int y) const
{
	if (x < 10 && x > -1 && y >= 0 && y < 15 && (gameBoard[y][x] == SPACE))
		return true;
	else
		return false;
}

bool Board::Matrix::haveSpaceJoker(int x, int y) const
{
	if (x < 10 && x > -1 && y >= 0 && y < 15)
		return true;
	else
		return false;
}

void Board::Matrix::updateIndicators(const Shape &shape)
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

int Board::Matrix::checkIfFullLine()
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

bool Board::Matrix::checkGameFailure()
{
	if (indicators[START] != EMPTY)
		return false;
	else
		return true;
}

void Board::Matrix::eraseLine(int i)
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

int Board::Matrix::eraseCell(int j, int i) //gets an index in the matrix and puts space in the i,j element in the matrix.
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

void Board::Matrix::printMatrix()
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

//BOARD MEMBER FUNCTIONS
Board::Board()
{
	drawBoard();
}


void Board::setScore(int newScore)
{
	score = newScore;
	if (score <= 0)
		score = 0;
	gotoxy(SCORE_X - 7, SCORE_Y);
	std::cout << std::setfill('0') << std::setw(6) << score;
}

void Board::markShapeAndUpdateScore(const Shape& shape)
{
	int numLinesErased;
	numLinesErased = gameBoard.markShape(shape);

	switch (numLinesErased)
	{

	case ONE:
		if (shape.getShapeType() == JOKER)
			this->setScore(this->getScore() + 50);
		else

			this->setScore(this->getScore() + 100);
		break;
	case TWO:
		this->setScore(this->getScore() + 300);
		break;
	case THREE:
		this->setScore(this->getScore() + 500);
		break;
	case FOUR:
		this->setScore(this->getScore() + 800);
		break;
	}
}

void Board::explodeBomb(const Point & pt)
{
	int x = 0, y = 0;
	int erasedCells = 0;
	gameBoard.getPosInMatrix(pt, x, y);

	if (x == START && y == START) //TOP LEFT
	{
		erasedCells += gameBoard.eraseCell(x + 1, y);
		erasedCells += gameBoard.eraseCell(x + 1, y + 1);
	}
	else if (x < WIDTH && y == START)//TOP CENTRAL
	{
		erasedCells += gameBoard.eraseCell(x + 1, y);
		erasedCells += gameBoard.eraseCell(x, y + 1);
		erasedCells += gameBoard.eraseCell(x - 1, y);

	}
	else if (x == WIDTH - 1 && y == START)//TOP RIGHT
	{
		erasedCells += gameBoard.eraseCell(x, y + 1);
		erasedCells += gameBoard.eraseCell(x - 1, y + 1);
		erasedCells += gameBoard.eraseCell(x - 1, y);
	}
	else if (x == WIDTH - 1 && y < END)//RIGHT SIDE
	{
		erasedCells += gameBoard.eraseCell(x, y + 1);
		erasedCells += gameBoard.eraseCell(x - 1, y + 1);
		erasedCells += gameBoard.eraseCell(x - 1, y);
		erasedCells += gameBoard.eraseCell(x - 1, y - 1);
		erasedCells += gameBoard.eraseCell(x, y - 1);
	}
	else if (x == WIDTH - 1 && y == END - 1)//BOTTOM RIGHT
	{
		erasedCells += gameBoard.eraseCell(x - 1, y);
		erasedCells += gameBoard.eraseCell(x - 1, y - 1);
		erasedCells += gameBoard.eraseCell(x, y - 1);
	}
	else if (x < WIDTH && y == END - 1)//BOTTOM CENTRAL
	{
		erasedCells += gameBoard.eraseCell(x - 1, y);
		erasedCells += gameBoard.eraseCell(x - 1, y - 1);
		erasedCells += gameBoard.eraseCell(x, y - 1);
		erasedCells += gameBoard.eraseCell(x + 1, y - 1);
		erasedCells += gameBoard.eraseCell(x + 1, y);
	}
	else if (x == START && y == END - 1)//BOTTOM LEFT
	{
		erasedCells += gameBoard.eraseCell(x, y - 1);
		erasedCells += gameBoard.eraseCell(x + 1, y - 1);
		erasedCells += gameBoard.eraseCell(x + 1, y);
	}
	else if (x == START && y < END)//LEFT
	{
		erasedCells += gameBoard.eraseCell(x + 1, y);
		erasedCells += gameBoard.eraseCell(x + 1, y + 1);
		erasedCells += gameBoard.eraseCell(x, y + 1);
		erasedCells += gameBoard.eraseCell(x, y - 1);
		erasedCells += gameBoard.eraseCell(x + 1, y - 1);
	}
	else //ANY OTHER PLACE IN BOARD
	{
		erasedCells += gameBoard.eraseCell(x, y - 1);
		erasedCells += gameBoard.eraseCell(x + 1, y - 1);
		erasedCells += gameBoard.eraseCell(x + 1, y);
		erasedCells += gameBoard.eraseCell(x + 1, y + 1);
		erasedCells += gameBoard.eraseCell(x, y + 1);
		erasedCells += gameBoard.eraseCell(x - 1, y + 1);
		erasedCells += gameBoard.eraseCell(x - 1, y);
		erasedCells += gameBoard.eraseCell(x - 1, y - 1);
	}

	this->setScore(this->getScore() - BOMB_SCORE_REDUCTION * erasedCells);
	gameBoard.printMatrix();
}

bool Board::haveSpace(int x, int y)const
{
	return gameBoard.haveSpace(x, y);
}

bool Board::haveSpaceJoker(int x, int y) const
{
	return gameBoard.haveSpaceJoker(x, y);
}

void Board::showFailureMessage()
{
	gameBoard.setMatrix();
	gameBoard.printMatrix();
	gotoxy(((LEFTBORDER + RIGHTBORDER) / 2) - 2, ((TOPBORDER + BOTTOMBORDER) / 2) - 2);
	std::cout << "GAME";
	gotoxy(((LEFTBORDER + RIGHTBORDER) / 2) - 1, ((TOPBORDER + BOTTOMBORDER) / 2) - 1);
	std::cout << "OVER!";

}

void Board::drawBoard()
{
	drawMenu();
	drawScoreBoard();
	//drawing top border
	gotoxy(LEFTBORDER, TOPBORDER);
	for (int i = LEFTBORDER; i < RIGHTBORDER + 1; i++)
	{
		std::cout << "$";
	}

	//drawing right border
	for (int i = MIN_Y; i < BOTTOMBORDER; i++)
	{
		gotoxy(RIGHTBORDER, i);
		std::cout << "$";
	}

	//drawing bottom border
	gotoxy(LEFTBORDER, BOTTOMBORDER);
	for (int i = LEFTBORDER; i < RIGHTBORDER + 1; i++)
	{
		std::cout << "$";
	}

	//drawing left border
	for (int i = MIN_Y; i < BOTTOMBORDER; i++)
	{
		gotoxy(LEFTBORDER, i);
		std::cout << "$";
	}


}

void Board::drawMenu()
{
	gotoxy(3, TOPBORDER);
	std::cout << "Menu:" << std::endl << std::endl;
	std::cout << "\t1. Start Game" << std::endl << std::endl;
	std::cout << "\t2. Pause/Play" << std::endl << std::endl;
	std::cout << "\t3. Speed UP" << std::endl << std::endl;
	std::cout << "\t4. Speed DOWN" << std::endl << std::endl;
	std::cout << "\t9. EXIT" << std::endl << std::endl;

}

void Board::drawScoreBoard()
{
	gotoxy(scorePosX - 14, scorePosY - 3);
	std::cout << "Speed: 150 m/s";
	gotoxy(scorePosX - 14, scorePosY);
	std::cout << "Score: " << std::setfill('0') << std::setw(6) << score;
	gotoxy(scorePosX - 7, scorePosY);
	gotoxy(itemsPosX - 14, itemsPosY);
	std::cout << "Fallen Items: " << std::setfill('0') << std::setw(4) << fallenItems;

}

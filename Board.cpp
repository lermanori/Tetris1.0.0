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


void Board::Matrix::getPosInMatrix(const Point& pt, int &x, int &y)
{
	x = pt.getX() - MIN_X;
	y = pt.getY() - MIN_Y;
}
/*
void Board::Matrix::getPosInMatrix(int x, int y, int & xNewPos, int & yNewPos)
{
	xNewPos = x - MIN_X;
	yNewPos = y - MIN_Y;
}
*/

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


void Board::updateScore(int erasedLines, const Shape & shape)
{
	switch (erasedLines)
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
	default:
		break;
	}
}

void Board::explodeBomb(const int x , const int y)
{
	int erasedCells = 0;

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



bool Board::checkGameFailure()
{
	if (gameBoard.indicators[START] != EMPTY)
		return true;
	else
		return false;
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
	std::cout << "Speed: " << std::setw(4)<< "750 m / s";
	gotoxy(scorePosX - 14, scorePosY);
	std::cout << "Score: " << std::setfill('0') << std::setw(6) << score;
	gotoxy(scorePosX - 7, scorePosY);
	gotoxy(itemsPosX - 14, itemsPosY);
	std::cout << "Fallen Items: " << std::setfill('0') << std::setw(4) << fallenItems;

}

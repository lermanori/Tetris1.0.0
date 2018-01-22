#pragma once
#include "Board.h"
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

#pragma once
#include "Board.h"

Board::Board()
{
	drawBoard();
}

void Board::markShape(const ShapeFactory & shape)
{
	gameBoard.markShape(shape);
}


void Board::explodeBomb(const Point & pt)
{
	int x = 0, y = 0;
	gameBoard.getPosInMatrix(pt, x, y);

	if (x == START && y == START) //TOP LEFT
	{
		gameBoard.eraseCell(x + 1, y);
		gameBoard.eraseCell(x + 1, y + 1);
	}
	else if (x < WIDTH && y == START)//TOP CENTRAL
	{
		gameBoard.eraseCell(x + 1, y);
		gameBoard.eraseCell(x, y + 1);
		gameBoard.eraseCell(x - 1, y);
	}
	else if (x == WIDTH-1 && y == START)//TOP RIGHT
	{
		gameBoard.eraseCell(x, y + 1);
		gameBoard.eraseCell(x - 1, y + 1);
		gameBoard.eraseCell(x - 1, y);
	}
	else if (x == WIDTH-1 && y < END)//RIGHT SIDE
	{
		gameBoard.eraseCell(x, y + 1);
		gameBoard.eraseCell(x - 1, y + 1);
		gameBoard.eraseCell(x - 1, y);
		gameBoard.eraseCell(x - 1, y - 1);
		gameBoard.eraseCell(x, y - 1);
	}
	else if (x == WIDTH - 1 && y == END-1)//BOTTOM RIGHT
	{
		gameBoard.eraseCell(x - 1, y);
		gameBoard.eraseCell(x - 1, y - 1);
		gameBoard.eraseCell(x, y - 1);
	}
	else if (x < WIDTH && y == END - 1)//BOTTOM CENTRAL
	{
		gameBoard.eraseCell(x - 1, y);
		gameBoard.eraseCell(x - 1, y - 1);
		gameBoard.eraseCell(x, y - 1);
		gameBoard.eraseCell(x + 1, y - 1);
		gameBoard.eraseCell(x + 1, y);
	}
	else if (x == START && y == END - 1)//BOTTOM LEFT
	{
		gameBoard.eraseCell(x, y - 1);
		gameBoard.eraseCell(x + 1, y - 1);
		gameBoard.eraseCell(x + 1, y);
	}
	else if (x == START && y < END)//LEFT
	{
		gameBoard.eraseCell(x + 1, y);
		gameBoard.eraseCell(x + 1, y + 1);
		gameBoard.eraseCell(x, y + 1);
		gameBoard.eraseCell(x, y - 1);
		gameBoard.eraseCell(x + 1, y -1);
	}
	else //ANY OTHER PLACE IN BOARD
	{
		gameBoard.eraseCell(x, y - 1);
		gameBoard.eraseCell(x + 1, y - 1);
		gameBoard.eraseCell(x + 1, y);
		gameBoard.eraseCell(x + 1, y + 1);
		gameBoard.eraseCell(x, y + 1);
		gameBoard.eraseCell(x - 1, y + 1);
		gameBoard.eraseCell(x - 1, y);
		gameBoard.eraseCell(x - 1, y - 1);

	}

	gameBoard.printMatrix();
}
bool Board::haveSpace(int x, int y)const
{
	return gameBoard.haveSpace(x, y);
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
	std::cout << "Speed: " << gameSpeed << " m/s";
	gotoxy(scorePosX - 14, scorePosY);
	std::cout << "Score: ";
	gotoxy(scorePosX - 7, scorePosY);
	std::cout << score;
	gotoxy(itemsPosX - 14, itemsPosY);
	std::cout << "Fallen Items: " << fallenItems;

}

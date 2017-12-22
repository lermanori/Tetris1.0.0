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

bool Board::haveSpace(int x, int y)const
{
	return gameBoard.haveSpace(x, y);
}

void Board::showFailureMessage()
{
	gameBoard.setMatrix();
	gameBoard.printMatrix();
	gotoxy(((LEFTBORDER + RIGHTBORDER) / 2)-2, ((TOPBORDER + BOTTOMBORDER) / 2)-2);
	std::cout << "GAME";
	gotoxy(((LEFTBORDER + RIGHTBORDER) / 2) -1, ((TOPBORDER + BOTTOMBORDER) / 2) -1);
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

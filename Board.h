#pragma once
#include "utils.h"
#include "constants.h"
#include <iostream>

class Board
{
	char board[15][10];
	int fallenItems = 0;
	int score = 0;
	const int scorePosX = SCORE_X;
	const int scorePosY = SCORE_Y;
	const int itemsPosX = FALLEN_ITEMS_X;
	const int itemsPosY = FALLEN_ITEMS_Y;

	void drawBoard();
	void drawMenu();
	void drawScoreBoard();

public:
	Board();
	void setScore(int newScore) { score = newScore; gotoxy(SCORE_X, SCORE_Y); std::cout << score; };
	void setFallenItems(int numItems) { fallenItems = numItems; gotoxy(FALLEN_ITEMS_X, FALLEN_ITEMS_Y); std::cout << fallenItems; };
	int getScore() { return score; };
	int getFallenItems() { return fallenItems; };
};
#pragma once
#include "utils.h"
#include "constants.h"
#include "Matrix.h"
#include <iostream>
#include <iomanip>

class ShapeFactory;

class Board
{
	Matrix gameBoard;
	int fallenItems = 0;
	int score = 0;
	int gameSpeed = 150;
	const int scorePosX = SCORE_X;
	const int scorePosY = SCORE_Y;
	const int itemsPosX = FALLEN_ITEMS_X;
	const int itemsPosY = FALLEN_ITEMS_Y;

	void drawBoard();
	void drawMenu();
	void drawScoreBoard();

public:
	Board();
	void printMatrix() { gameBoard.printMatrix(); }
	void cleanScore() { setScore(EMPTY); }; //std::cout << SPACE << SPACE << SPACE; };
	void setScore(int newScore);
	void setFallenItems(int numItems) { fallenItems = numItems; gotoxy(FALLEN_ITEMS_X, FALLEN_ITEMS_Y); std::cout << std::setfill('0') << std::setw(4) << fallenItems; };
	void cleanFallenItems() { setFallenItems(0); };
	int getScore() { return score; };
	int getFallenItems() { return fallenItems; };
	void markShape(const ShapeFactory &shape);
	void explodeBomb(const Point &pt);
	bool haveSpace(int x, int y)const;
	bool haveSpaceJoker(int x, int y)const;

	bool checkGameFailure() { return gameBoard.checkGameFailure(); }
	void showFailureMessage();

	
};
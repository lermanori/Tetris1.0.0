#pragma once
#include "utils.h"
#include "constants.h"
#include "Matrix.h"
#include <iostream>

class ShapeFactory;

class Board
{
	Matrix gameBoard;
	int fallenItems = 0;
	int score = 0;
	int gameSpeed = 200;
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
	void cleanScore(char ch) { gotoxy(SCORE_X - 7, SCORE_Y); std::cout << SPACE << SPACE; };
	void setScore(int newScore) { score = newScore; gotoxy(SCORE_X - 7, SCORE_Y); std::cout << score; };
	void setFallenItems(int numItems) { fallenItems = numItems; gotoxy(FALLEN_ITEMS_X, FALLEN_ITEMS_Y); std::cout << fallenItems; };
	void cleanFallenItems(const char) { gotoxy(FALLEN_ITEMS_X, FALLEN_ITEMS_Y); std::cout << SPACE << SPACE; };
	int getScore() { return score; };
	int getFallenItems() { return fallenItems; };
	void markShape(const ShapeFactory &shape);
	bool haveSpace(int x, int y)const;
	bool checkGameFailure() { return gameBoard.checkGameFailure(); }
	void showFailureMessage();

	
};
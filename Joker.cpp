#pragma once
#include "Joker.h"

Joker::Joker()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = JKR;
	p.set(x, y, c);
}

Joker::Joker(int x, int y, char c)
{
	p.set(x, y, c);
}

void Joker::move(Direction dir)
{
		p.draw(' ');
		p.move(dir);
		p.draw();
}

void Joker::draw(char c) const
{
	p.draw(c);
}

bool Joker::canMove(const Board& gameBoard, Direction dir)
{
	bool res;

	res = p.canMoveJoker(gameBoard, dir);

	return res;
}

int Joker::markShape(Board & gameBoard)
{
	int x = 0, y = 0;
	this->getPosInMatrix(this->getPoint(), x, y);
	if (gameBoard[y][x] == SPACE)
		gameBoard(y)[x] = JKR;
	else
		gameBoard[y][x] = JKR;

	this->draw(JKR);
	gameBoard.printMatrix();
	return gameBoard.checkLine();
}




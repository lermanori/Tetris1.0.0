#pragma once
#include "bomb.h"

Bomb::Bomb()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = BMB;
	p.set(x, y, c);
}

Bomb::Bomb(int x, int y, char c)
{
	p.set(x, y, c);
}

void Bomb::move(Direction dir)
{
	p.draw(' ');
	p.move(dir);
	p.draw();
}

void Bomb::draw(char c)const
{
	p.draw(c);
}

bool Bomb::canMove(const Board& gameBoard, Direction dir)
{
	bool res;
	res = p.canMove(gameBoard, dir);

	return res;
}

int Bomb::markShape(Board & gameBoard)
{
	int x = 0, y = 0;
	this->getPosInMatrix(this->getPoint(), x, y);

	gameBoard.explodeBomb(x,y);
	return gameBoard.checkLine();
}





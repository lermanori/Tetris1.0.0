#pragma once
#include "square.h"

Square::Square()
{
	int x = MIN_X + 5, y = MIN_Y + 1;
	char c = SQR;
	s1[BL].set(x, y, c);
	s1[BR].set(x + 1, y, c);
	s1[TR].set(x + 1, y - 1, c);
	s1[TL].set(x, y - 1, c);
}

Square::Square(int x, int y, char c = SQR)
{
	s1[BL].set(x, y, c);
	s1[BR].set(x + 1, y, c);
	s1[TR].set(x + 1, y - 1, c);
	s1[TL].set(x, y - 1, c);
}
void Square::move(Direction dir)
{
	s1[BL].draw(' ');
	s1[BR].draw(' ');
	s1[TR].draw(' ');
	s1[TL].draw(' ');

	s1[BL].move(dir);
	s1[BR].move(dir);
	s1[TR].move(dir);
	s1[TL].move(dir);

	s1[BL].draw();
	s1[BR].draw();
	s1[TR].draw();
	s1[TL].draw();

}

void Square::draw(char c)const
{
	s1[BR].draw(c);
	s1[TR].draw(c);
	s1[TL].draw(c);
	s1[BL].draw(c);

}

bool Square::canMove(const Board &gameBoard, Direction dir)
{
	bool check[4] = { false, false, false, false };
	bool res;

	check[BL] = s1[BL].canMove(gameBoard, dir);
	check[BR] = s1[BR].canMove(gameBoard, dir);
	check[TR] = s1[TR].canMove(gameBoard, dir);
	check[TL] = s1[TL].canMove(gameBoard, dir);

	res = check[BL] && check[BR] && check[TR] && check[TL];
	return res;

}

int Square::markShape(Board &gameBoard)
{
	int x = 0, y = 0;
	this->getPosInMatrix(this->getPoint(), x, y);


	//ORDER: BL BR TR TL
	gameBoard(y)[x] = SQR;
	gameBoard(y)[x + 1] = SQR;
	gameBoard(y - 1)[x + 1] = SQR;
	gameBoard(y - 1)[x] = SQR;


	this->draw(SQR);
	return gameBoard.checkLine();

}





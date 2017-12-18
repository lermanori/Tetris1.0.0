#include "bomb.h"

Bomb::Bomb()
{
	int x = MIN_X + 5, y = MIN_Y;
	char c = '@';
	p.set(x, y, c);
}

Bomb::Bomb(int x, int y, char c)
{
	p.set(x, y, c);
}

bool Bomb::move(Direction dir)
{
	bool checkMove = false;

	p.draw(' ');

	checkMove = p.move(dir);
	
	p.draw();

	
	return checkMove;
}

void Bomb::draw(char c)
{
	p.draw(c);
}

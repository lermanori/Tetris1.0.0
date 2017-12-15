#include "square.h"

Square::Square()
{
	int x = MIN_X+5, y = MIN_Y;
	char c = '*';
	s1[BL].set(x, y, c);
	s1[BR].set(x + 1, y, c);
	s1[TR].set(x + 1, y - 1, c);
	s1[TL].set(x, y - 1, c);
}

Square::Square(int x, int y, char c = '*')
{
	s1[BL].set(x, y, c);
	s1[BR].set(x+1, y, c);
	s1[TR].set(x+1, y-1, c);
	s1[TL].set(x, y-1, c);
}
bool Square::move(Direction dir)
{
	bool checkMove[4] = { false,false,false,false };


	s1[BL].draw(' ');
	s1[BR].draw(' ');
	s1[TR].draw(' ');
	s1[TL].draw(' ');

	checkMove[BL] = s1[BL].move(dir);
	checkMove[BR] = s1[BR].move(dir);
	checkMove[TR] = s1[TR].move(dir);
	checkMove[TL] = s1[TL].move(dir);

	s1[BL].draw();
	s1[BR].draw();
	s1[TR].draw();
	s1[TL].draw();
	
	bool res = checkMove[BL] ||	checkMove[BR] || checkMove[TR] || checkMove[TL];
	return res;
}

void Square::draw(char c)
{
	s1[BR].draw(c);
	s1[TR].draw(c);
	s1[TL].draw(c);
	s1[BL].draw(c);

}


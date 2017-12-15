#include "Point.h"

bool Point::move(Direction dir)
{
	switch (dir)
	{
/*	case UP:
		direction_x = 0;
		direction_y = -1;
		break;
*/
	case RIGHT:
		direction_x = 1;
		direction_y = 0;
		break;
	case DOWN:
		direction_x = 0;
		direction_y = 1;
		break;
	case LEFT:
		direction_x = -1;
		direction_y = 0;
		break;
	default:
		direction_x = 0;
		direction_y = 0;
		break;
	}

	if (x > MAX_X)
	{

		x = MAX_X-1;
	
	}
	else if (x < MIN_X)
	{
		x = MIN_X+1;
		
	}
	else if (y > MAX_Y)
	{
		y = MAX_Y-1;
		return true;
	}
	else if (y < MIN_Y)
	{
		y = MIN_Y+1;
	}

	x += direction_x;
	y = (direction_y + y + 1);
	return false;
}

#pragma once

enum Direction { UP, RIGHT, DOWN, LEFT, STAY };
enum SquareParts { BL = 0, BR, TR, TL }; //Bottom Left etc.. anti-clockwise
enum LineParts { LL = 0, LR, RL, RR }; //left to right
enum BoardPos { };
enum Borders {
	MIN_X = 30, MIN_Y = 5, MAX_X = 39, MAX_Y = 18, LEFTBORDER = MIN_X-1, TOPBORDER = MIN_Y-1,
	RIGHTBORDER = MAX_X+1, BOTTOMBORDER = MAX_Y+1, SCORE_X = RIGHTBORDER + 25, SCORE_Y = MIN_Y + 3,
	FALLEN_ITEMS_X = SCORE_X, FALLEN_ITEMS_Y = SCORE_Y + 3};


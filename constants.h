#pragma once

enum Direction { UP, RIGHT, DOWN, LEFT, STAY };
enum SquareParts { BL = 0, BR, TR, TL }; //Bottom Left etc.. anti-clockwise
enum LineParts { LL = 0, LR, RL, RR }; //left to right
enum BoardPos { };
enum ShapeTypes{SQUARE = 0, LINE , BOMB};
enum LineState { HORIZONTAL = 0, VERTICAL };

enum Borders {
	MIN_X = 32, MIN_Y = 4, MAX_X = MIN_X+9, MAX_Y = MIN_Y+14, LEFTBORDER = MIN_X-1, TOPBORDER = MIN_Y-1,
	RIGHTBORDER = MAX_X+1, BOTTOMBORDER = MAX_Y+1, SCORE_X = RIGHTBORDER + 25, SCORE_Y = MIN_Y + 3,
	FALLEN_ITEMS_X = SCORE_X, FALLEN_ITEMS_Y = SCORE_Y + 3};

const char SPACE = ' ';
const int EMPTY = 0;
const char SQR = '*';
const char BMB = '@';
const char LN = '#';

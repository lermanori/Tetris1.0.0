/************************************************************************************************************************************************
~~~~ Constants.h ~~~

What is?
	This header file contains all the constants we use in the program.
************************************************************************************************************************************************/
#pragma once


enum Direction { ROTATE, RIGHT, DOWN, LEFT, STAY, HARDDROP };
enum SquareParts { BL = 0, BR, TR, TL }; //Bottom Left, Bottom Right, Top Right, Top Left ( anti-clockwise)
enum LineParts { LL = 0, LR, RL, RR }; //Left-Left, Left-Right,Right-Left, Right-Right
enum BoardPos { };
enum ShapeTypes{SQUARE = 0, LINE , BOMB, JOKER};
enum LineState { HORIZONTAL = 0, VERTICAL };
enum Numbers{ ONE=1, TWO, THREE, FOUR};
//Borders - Defined for the x,y positions of the user interface
enum Borders {
	MIN_X = 32, MIN_Y =4, MAX_X = MIN_X+9, MAX_Y = MIN_Y+14, LEFTBORDER = MIN_X-1, TOPBORDER = MIN_Y-1,
	RIGHTBORDER = MAX_X+1, BOTTOMBORDER = MAX_Y+1, SCORE_X = RIGHTBORDER + 25, SCORE_Y = MIN_Y + 3,
	FALLEN_ITEMS_X = SCORE_X, FALLEN_ITEMS_Y = SCORE_Y + 3};
enum MatrixDetails { HEIGHT = 15, WIDTH = 10 };
enum indicatorDetails { START = 0,END = 15 };

//CONSTANTS FOR THE GAME KEYS
const char START_GAME = '1';
const char PLAY_PAUSE = '2';
const char SPEED_UP = '3';
const char SPEED_DOWN = '4';
const char HARD_DROP = 32;
const char EXIT = '9';
const char SPACE = ' ';

//Default Numeric Values:
const int EMPTY = 0;
const int FULL = 10;
const int MAX_SPEED = 100;
const int MIN_SPEED = 200;
const int SPEED_CHANGE = 25;
const int BOMB_SCORE_REDUCTION = 50;

//Shape Charachters
const char SQR = '#';
const char BMB = '@';
const char LN = '#';
const char JKR = 'J';

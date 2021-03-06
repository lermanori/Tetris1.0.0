/************************************************************************************************************************************************
~~~~ Constants.h ~~~

What is?
	This header file contains all the constants we use in the program.
************************************************************************************************************************************************/
#pragma once


enum Direction { ROTATE, RIGHT, DOWN, LEFT, STAY, HARDDROP };
enum SquareParts { BL = 0, BR, TR, TL }; //Bottom Left, Bottom Right, Top Right, Top Left ( anti-clockwise)
enum LineParts { LL = 0, LR, RL, RR }; //Left-Left, Left-Right,Right-Left, Right-Right
enum LParts { LT = 0, LeftSide, Mid, RightSide }; //LT = where the chupchik at
enum ZParts { LTop =0, RTop, LBottom, RBottom};
enum TParts { MidBottom=0, RightBottom, LeftBottom, Chupchik};
enum BoardPos { };
enum ShapeTypes{SQUARE = 0, LINE , BOMB, JOKER, LSHAPE, ZSHAPE, TSHAPE};
enum shapeState { HORIZONTAL = 0, VERTICAL , INV_HORIZONTAL, INV_VERTICAL, DUMMYSTATE  }; //each sshape can ave a maximum of 4 different states . Example: line has only the first two states, square has only one state.
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


//SPEEDS
const char very_slow[10] = { 'V', 'E', 'R','Y', ' ', 'S', 'L','O','W','\0' };
const char slow[10] = { 'S', 'L', 'O','W', ' ', ' ', ' ',' ',' ','\0' };
const char normal[10] = { 'N', 'O', 'R','M', 'A', 'L', ' ',' ',' ','\0' };
const char fast[10] = { 'F', 'A', 'S','T', ' ', ' ', ' ',' ',' ','\0' };
const char very_fast[10] = { 'V', 'E', 'R','Y', ' ', 'F', 'A','S','T','\0' };




//Default Numeric Values:
const int EMPTY = 0;
const int FULL = 10;
const double MAX_SPEED = 0.25;
const double MIN_SPEED = 1.25;
const double SPEED_CHANGE = 0.25;
const int BOMB_SCORE_REDUCTION = 50;

//Shape Charachters
const char SQR = '#';
const char BMB = '@';
const char LN = '#';
const char JKR = 'J';
const char LSHP = '#';
const char ZSHP = '#';
const char TSHP = '#';
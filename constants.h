#pragma once

enum Direction { UP, RIGHT, DOWN, LEFT, STAY };
enum SquareParts { BL = 0, BR, TR, TL }; //Bottom Left etc.. anti-clockwise
enum LineParts { LL = 0, LR, RL, RR }; //left to right
enum BoardPos { };
enum Borders { MIN_X = 30, MIN_Y = 5, MAX_X = 40, MAX_Y = 20 };

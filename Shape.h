#pragma once


class Point;
//class Board;

class Shape 
{
public:
	virtual void move(Direction) = 0;
	virtual void draw(char)const = 0;
	virtual const Point& getPoint()const = 0;
	virtual shapeState getState()const = 0;
	virtual ShapeTypes getShapeType()const = 0;
	virtual bool canMove(const Board& gameBoard, Direction dir) = 0;
	virtual int markShape(Board& gameBoard) = 0;
	void getPosInMatrix(const Point &pt, int &x, int &y) { x = pt.getX() - MIN_X;	y = pt.getY() - MIN_Y; }
};
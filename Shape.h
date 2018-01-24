/************************************************************************************************************************************************
this object is an abstract object that is used as the interface class as part of factory design pattern implentation
and polymorphisem of the shape.
************************************************************************************************************************************************/

#pragma once
#include "constants.h"
#include "Point.h"

class Point;
class Board;

class Shape 
{
public:
	virtual void move(Direction) = 0;
	virtual void draw(char)const = 0;
	virtual const Point& getPoint()const = 0;
	virtual shapeState getState()const = 0;
	virtual ShapeTypes getShapeType()const = 0;
	virtual bool canMove(const Board& gameBoard, Direction dir);
	virtual bool checkIfCanMove(shapeState state, const Board & gameBoard, Direction dir) = 0;
	virtual int markShape(Board& gameBoard) = 0;
	void getPosInMatrix(const Point &pt, int &x, int &y);
};
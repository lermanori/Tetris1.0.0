#pragma once
#include "square.h"
#include "Line.h"
#include "bomb.h"
#include "Joker.h"


//shape factory creates a random tetris object that is refred threw the shape itself.
//its using the void pointer to hold the adress to the part and used each time by casting to the desired object and activating the objects methods.  
class ShapeFactory
{
	Square* sqrPtr = nullptr;
	Line* linePtr = nullptr;
	Bomb* bombPtr = nullptr;
	Joker* jokerPtr = nullptr;


	const int shapeType = rand() %4;
//	const int shapeType = JOKER;
	

public:
	ShapeFactory();
	void move(Direction dir);
	void draw(char c)const;
	const int getShapeType()const { return shapeType; };
	const Point& getPoint()const ;
	int getShapeState() const;
	bool canMove(Board& gameBoard, Direction dir);
		
};
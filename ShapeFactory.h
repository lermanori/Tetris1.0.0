/************************************************************************************************************************************************
~~~~ ShapeFactory.h + ShapeFactory.cpp ~~~

shape factory creates a random tetris object that is refred threw the shape itself.
its using the void pointer to hold the adress to the part and used each time by casting to the desired object and activating the objects methods.

CLASS MEMBERS:
there are two kinds of class members:
1.the class members  pointers to every diffrent type of tetris object because the method of the class is to fill only the pointer of the object that was craeted while the rest are nullptr. 
what means that if a type is added to the tetris there should be another pointer here added.
2. the const shapeType- this const represent the type of the shape the value of the const is decided at shape propabilities becauese there where too many speicial objects  craeted when it was total random,probabilities can be changed over there.
	after the shape is decided we know what shape to craete and baisiclly this is the varible who handles all the navigating the shape object to his right function according to choice of random shape .
MEMBER FUNCTIONS:

the most used method in this class is  usin a switch on the shapetype in order to switch between the diffrent shapes and calling the relavent function for each shapetype(tetris object).
well call this method here method x
ctor- using method x to craete the right shape
move\canMove- using method x to move\check if can be moved the right shape
getShapeType-getter for shape type.
getPoint- using method x to get point .
getShapeState-this function is onlt rellevent to line a this moment,for every other type dosent matter, using method x to ge line state if line is the shape

shapeProbabilities- explaind at 2. of class members

************************************************************************************************************************************************/

#pragma once

#include "square.h"
#include "Line.h"
#include "bomb.h"
#include "Joker.h"
#include "LShape.h"
#include "constants.h"

class ShapeFactory: public Shape
{

//	const int shapeType = shapeProbabilities();
//	const int shapeType = JOKER;
	

public:
	static int shapeProbabilities();
	static Shape* createShape(const int shapeType);

		
};
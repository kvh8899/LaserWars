#include "Shapes.h"

Shape::Shape(float x, float y) : xCoord(x), yCoord(y)
{
}

float Shape::getXCoord() const
{
	return this->xCoord;
}

Shape* Shape::setXCoord(float xCoord)
{
	this->xCoord = xCoord;
	return this;
}

float Shape::getYCoord() const
{
	return this->yCoord;
}

Shape* Shape::setYCoord(float yCoord)
{
	this->yCoord = yCoord;
	return this;
}
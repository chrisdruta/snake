//------------------------------------------------------------------------------------------------
//
// File: snakepart.h
// Author: Chris Druta
// Date: January 12, 2017
//
// Description: contains snakepart class declarations
//
//------------------------------------------------------------------------------------------------

#include "snake.h"

/**********************************************************************************/

SnakePart::SnakePart(int yPos, int xPos) {
	this->yPos = yPos;
	this->xPos = xPos;
}

SnakePart::SnakePart() {
	//Nothing to do here....
}

int SnakePart::getX() {
	return this->xPos;
}

int SnakePart::getY() {
	return this->yPos;
}

void SnakePart::setX(int xPos) {
	this->xPos = xPos;
	return;
}

void SnakePart::setY(int yPos) {
	this->yPos = yPos;
	return;
}

void SnakePart::setXY(int xPos, int yPos) {
	this->xPos = xPos;
	this->yPos = yPos;

	return;
}

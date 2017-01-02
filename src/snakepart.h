//------------------------------------------------------------------------------------------------
//
// File: User.h
// Author: Chris Druta
// Date: December 05, 2016
//
// Description: contains User class declarations
//
//------------------------------------------------------------------------------------------------

#ifndef SNAKEPART_H
#define SNAKEPART_H

/**********************************************************************************/

class SnakePart {
private:
	int xPos, yPos;

public:
	SnakePart(int yPos, int xPos);
	SnakePart(); //deafult constructor

	int getX();
	int getY();
	void setX(int xPos);
	void setY(int yPos);
	void setXY(int xPos, int yPos);

};

#endif

/**********************************************************************************/

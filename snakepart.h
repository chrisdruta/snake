//------------------------------------------------------------------------------------------------
//
// File: snakepart.h
// Author: Chris Druta
// Date: January 12, 2017
//
// Description: contains snakepart class functions
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

	bool operator==(const SnakePart& rhs) const;

};

#endif

/**********************************************************************************/

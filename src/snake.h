//------------------------------------------------------------------------------------------------
//
// File: User.h
// Author: Chris Druta
// Date: December 05, 2016
//
// Description: contains User class declarations
//
//------------------------------------------------------------------------------------------------

#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <ncurses.h>
#include "snakepart.h"

/**********************************************************************************/

class Snake {
private:
	int maxHeight, maxWidth;
	char bodyChar, direction;
	bool grow;
	std::vector<SnakePart> snake;
	WINDOW* gameWin;

public:
	Snake(int yMax, int xMax);
	Snake(); //deafult constructor

	void moveSnake();
	void drawSnake();

	std::vector<SnakePart>& getVector();
};




#endif

/**********************************************************************************/

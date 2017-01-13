//------------------------------------------------------------------------------------------------
//
// File: snake.h
// Author: Chris Druta
// Date: January 12, 2017
//
// Description: contains snake class declarations
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

	void setDirection(char dir);

	std::vector<SnakePart>& getVector();
};




#endif

/**********************************************************************************/

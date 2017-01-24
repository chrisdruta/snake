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
#include <stdlib.h>
#include <time.h>
#include "snakepart.h"

/**********************************************************************************/

class Snake {
private:
	int maxHeight, maxWidth;
	char bodyChar, foodChar, direction;
	SnakePart food;
	bool grow;
	std::vector<SnakePart> snake;
	WINDOW* gameWin;

public:
	Snake(int yMax, int xMax);
	Snake(); //deafult constructor

	void makeFood();
	void drawFood();

	void moveSnake();
	void drawSnake();

	void growSnake();
	int checkCol();

	//setters and getters
	void setDirection(char dir);
	char& getDirection();

	void setGrow(bool grow);
	bool getGrow();

	//DEBUG functions
	void printSnakePos();
	void printFoodPos();
	std::vector<SnakePart>& getVector();
};




#endif

/**********************************************************************************/

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
#include <time.h>
#include <stdlib.h>
#include "snakepart.h"

/**********************************************************************************/

class Snake {
private:
	int maxHeight, maxWidth;
	char bodyChar, foodChar, direction;
	bool grow;

	std::vector<SnakePart> snake;
	SnakePart food;

	WINDOW* gameWin;

public:
	Snake(int yMax, int xMax);
	Snake(); //deafult constructor

	//snake stuff
	void moveSnake();
	void drawSnake();

	void growSnake();
	int checkCol();

	void gameOver();

	//setters and getters
	void setDirection(char dir);
	char& getDirection();

	//food stuff
	void setGrow(bool grow);
	bool getGrow();

	void makeFood();
	void drawFood();
	void moveFood();
	void removeFood();

	//DEBUG functions
	void printSnakePos();
	void printFoodPos();
	std::vector<SnakePart>& getVector();
};




#endif

/**********************************************************************************/

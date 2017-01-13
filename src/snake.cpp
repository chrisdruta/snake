//------------------------------------------------------------------------------------------------
//
// File: snake.cpp
// Author: Chris Druta
// Date: January 12, 2017
//
// Description: contains snake class functions
//
//------------------------------------------------------------------------------------------------

#include "snake.h"

/**********************************************************************************/

Snake::Snake(int yMax, int xMax) {

	this->maxHeight = yMax;
	this->maxWidth = xMax;

	this->bodyChar = 'o';
	this->direction = 'r';

	this->grow = false;

	int xTemp = (xMax/ 2) - 3; //used for SnakePart constructor

	for(int i = 5; i > 0; i--) {
		this->snake.push_back(SnakePart(yMax/ 2, xTemp + i));
	}

	gameWin = newwin(this->maxHeight, this->maxWidth, 1, 1);
	wrefresh(gameWin); refresh();

}

Snake::Snake() {
	//Nothing to do here....
}

void Snake::moveSnake() {
	int xTemp1 = this->snake.at(0).getX();
	int yTemp1 = this->snake.at(0).getY();
	int xTemp2, yTemp2;

	//Strange behaviour here. Up and down behave opposite for some reason.

	switch(this->direction) {
		case 'l':
			this->snake.at(0).setXY(xTemp1 - 1, yTemp1);
			break;
		case 'r':
			this->snake.at(0).setXY(xTemp1 + 1, yTemp1);
			break;
		case 'u':
			this->snake.at(0).setXY(xTemp1, yTemp1 - 1);
			break;
		case 'd':
			this->snake.at(0).setXY(xTemp1, yTemp1 + 1);
			break;
	}

	xTemp2 = xTemp1;
	yTemp2 = yTemp1;

	for (int i = 1; i < (int) this->snake.size(); i++) {

		xTemp1 = this->snake.at(i).getX();
		yTemp1 = this->snake.at(i).getY();
		this->snake.at(i).setXY(xTemp2, yTemp2);
		xTemp2 = xTemp1;
		yTemp2 = yTemp1;
	}

	return;
}

void Snake::drawSnake() {
	wclear(gameWin);
	for (int i = 0; i < (int) this->snake.size(); i++) {
		mvwaddch(this->gameWin, this->snake.at(i).getY(), this->snake.at(i).getX(), this->bodyChar);
	}

	wrefresh(this->gameWin); refresh();

	return;
}

void Snake::setDirection(char dir) {

	this->direction = dir;
	return;
}

std::vector<SnakePart>& Snake::getVector() {
	return this->snake;
}

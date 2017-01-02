//------------------------------------------------------------------------------------------------
//
// File: User.h
// Author: Chris Druta
// Date: December 05, 2016
//
// Description: contains User class declarations
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

	for(int i = 5; i > 0; i--) {
		this->snake.push_back(SnakePart(yMax/ 2, (xMax + i)/ 2));
	}

	gameWin = newwin(this->maxHeight, this->maxWidth, 1, 1);
	wrefresh(gameWin); refresh();

}

Snake::Snake() {
	//Nothing to do here....
}

void Snake::moveSnake() {
	int xPos = this->snake.at(0).getX();
	int yPos = this->snake.at(0).getY();

	switch(this->direction) {
		case 'l':
			this->snake.at(0).setX(--xPos);
			break;
		case 'r':
			this->snake.at(0).setX(++xPos);
			break;
		case 'u':
			this->snake.at(0).setY(++yPos);
			break;
		case 'd':
			this->snake.at(0).setY(--yPos);
			break;
	}

	//if(this->grow == false)
	//	this->snake.pop_back();


	return;
}

void Snake::drawSnake() {
	wclear(gameWin);
	for (int i = 0; i < (int) this->snake.size(); i++) {
		mvwaddch(this->gameWin, this->snake.at(i).getY(), this->snake.at(i).getX(), bodyChar);
	}

	wrefresh(this->gameWin); refresh();

	return;
}

std::vector<SnakePart>& Snake::getVector() {
	return this->snake;
}

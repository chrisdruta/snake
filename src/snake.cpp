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
	this->foodChar = 'Q';
	this->direction = 'r';

	this->grow = false;

	int xTemp = (xMax/ 2) - 3; //used for SnakePart constructor

	for(int i = 5; i > 0; i--) { //creates snake with length of 5
		this->snake.push_back(SnakePart(yMax/ 2, xTemp + i));
	}

	//game window to draw to
	gameWin = newwin(this->maxHeight, this->maxWidth, 1, 1);

	wrefresh(gameWin); refresh();

	makeFood();
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

	if (this->grow) {
		this->snake.push_back(SnakePart(yTemp2, xTemp2));
		this->grow = false;
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

int Snake::checkCol() { //0 means no collision, 1 means edge/self, 2 means food
	if (this->snake.at(0).getX() == -1 || this->snake.at(0).getX() == maxWidth)
		return 1;

	else if (this->snake.at(0).getY() == -1 || this->snake.at(0).getY() == maxHeight)
		return 1;

	else if (this->snake.at(0).getY() == this->food.getY() && this->snake.at(0).getX() == this->food.getX())
		return 2;

	for (int i = 1; i < (int) this->snake.size(); i++) {
		if (this->snake.at(0) == this->snake.at(i))
			return 1;
	}

	return 0;
}

void Snake::gameOver() { //game over animation

	//int i  = (int) this->snake.size() * (int) this->snake.size();
	//int count = 0;

	while(1) {
		for (int i = 0; i < (int) this->snake.size(); i++) {
			if (this->snake.at(i).getY() != this->maxHeight - 1)
				if (mvwinch(this->gameWin, this->snake.at(i).getY() + 1, this->snake.at(i).getX()) == ' ') {
					this->snake.at(i).setY(this->snake.at(i).getY() + 1);
					usleep(50000);
					drawSnake();
				}



		}

		//usleep(100000);
	}

	return;
}

void Snake::growSnake() {
	setGrow(true);

	return;
}

void Snake::setDirection(char dir) {
	this->direction = dir;

	return;
}

char& Snake::getDirection() {
	return this->direction;
}

void Snake::setGrow(bool grow) {
	this->grow = true;

	return;
}

bool Snake::getGrow() {
	return this->grow;
}

void Snake::makeFood() {

	int xPos = rand() % this->maxWidth - 1;
	int yPos = rand() % this->maxHeight - 1;

	if (xPos <= 0)
		xPos++;
	if (yPos <= 0)
		yPos++;

	int i;
	bool isUnique = true;

	this->food = SnakePart(yPos, xPos);

	do { //gets food location, not already inside snake
		isUnique = true;

		for (i = 0; i < (int) this->snake.size(); i++) {
			if (this->food == this->snake.at(i))
				isUnique = false;
		}

		if (!isUnique) {

			xPos = rand() % this->maxWidth - 1;
			yPos = rand() % this->maxHeight - 1;

			if (xPos <= 0)
				xPos++;
			if (yPos <= 0)
				yPos++;

			this->food.setXY(xPos, yPos);
		}
	} while (!isUnique);

	return;
}

void Snake::drawFood() {
	wattron(this->gameWin, A_BOLD);
	mvwaddch(this->gameWin, this->food.getY(), this->food.getX(), this->foodChar);
	refresh(); wrefresh(this->gameWin);
	wattroff(this->gameWin, A_BOLD);

	return;
}

void Snake::moveFood() {
	int xPos = rand() % this->maxWidth - 1;
	int yPos = rand() % this->maxHeight - 1;

	if (xPos <= 0)
		xPos++;
	if (yPos <= 0)
		yPos++;

	int i;
	bool isUnique = true;

	this->food.setXY(xPos, yPos);

	do { //gets food location, not already inside snake
		isUnique = true;

		for (i = 0; i < (int) this->snake.size(); i++) {
			if (this->food == this->snake.at(i))
				isUnique = false;
		}

		if (!isUnique) {

			xPos = rand() % this->maxWidth - 1;
			yPos = rand() % this->maxHeight - 1;

			if (xPos <= 0)
				xPos++;
			if (yPos <= 0)
				yPos++;

			this->food.setXY(xPos, yPos);
		}
	} while (!isUnique);

	return;
}

void Snake::removeFood() {
	this->food.setXY(-5, -5); //move to unreachable place

	return;
}


//DEBUG
void Snake::printSnakePos() {
	mvwprintw(this->gameWin, maxHeight - 2, 2, "%d, %d", this->snake.at(0).getX(), this->snake.at(0).getY());
	wrefresh(this->gameWin); refresh();

	return;
}


void Snake::printFoodPos() {

	mvwprintw(this->gameWin, 2, 2, "%d, %d", this->food.getX(), this->food.getY());

	wrefresh(this->gameWin); refresh();


	return;
}

std::vector<SnakePart>& Snake::getVector() {
	return this->snake;
}

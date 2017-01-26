/**********************************************************************************/

/*
* File: main.cpp
* Author: Chris Druta
* Date: 12-23-16
*
* Description: Snake game written in C++ using ncurses
*
*/

/**********************************************************************************/

#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "timer.h"
#include "snake.h"

/**********************************************************************************/

//Main stuff
void startScreen(int yMax, int xMax);
void updateScore(WINDOW* scoreWin, int& currScore, int& highScore, bool incPnts);
void loseScreen(int yMax, int xMax);

char getDirection(WINDOW* gameWin, char& direction);

//DEBUG
void printTimeBool(Timer& timer);

/**********************************************************************************/

int main(){

	initscr();
	setlocale(LC_CTYPE,"C-UTF-8");
	curs_set(false);
	keypad(stdscr, true);
	noecho();
	cbreak();

	//ncurse colors
	start_color();
	use_default_colors(); //enable background

	init_pair(1, 1, 1);

	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);

	startScreen(yMax, xMax);

	int currScore = 0, highScore = 0;
	unsigned int speed = 100000;

	WINDOW* scoreWin = newwin(4, xMax, yMax - 4, 0);
	WINDOW* gameBorder = newwin(yMax - 4, xMax, 0, 0);

	box(scoreWin, 0, 0);
	box(gameBorder, 0, 0);
	wrefresh(gameBorder);

	updateScore(scoreWin, currScore, highScore, false);
	refresh();

	Snake snake(yMax - 6, xMax - 2);

	snake.drawSnake();
	usleep(1000000);

	char direction = 'r';

	Timer time5(1);

	//nodelay(stdscr, true);
	while(1) {

		direction = getDirection(gameBorder, snake.getDirection());
		snake.setDirection(direction);
		snake.moveSnake();

		if (snake.checkCol() == 1)
			startScreen(yMax, xMax);

		else if (snake.checkCol() == 2) {
			snake.growSnake();
			updateScore(scoreWin, currScore, highScore, true);
			snake.removeFood();
			//snake.delFood();// causing error
			time5.startThread();
		}

		snake.drawSnake();
		if (!time5.isTime())
			snake.drawFood();
		else {
			snake.moveFood();
			snake.drawFood();
			time5.stopThread();
		}

		//Debug
		snake.printSnakePos();
		printTimeBool(time5);
		if (!time5.isTime())
			snake.printFoodPos();

		if (snake.getDirection() == 'u' || snake.getDirection() == 'd')
			usleep(speed * 1.4);
		else
			usleep(speed);
	}

	endwin();

	return 0;
}

/**********************************************************************************/

void startScreen(int yMax, int xMax) {

	int xPos = (xMax - 27)/ 2;
	int yPos = (yMax - 4)/ 2;

	WINDOW* win1 = newwin(yMax, xMax, 0, 0);
	keypad(win1, TRUE);
	refresh();

	wattron(win1, A_BOLD);

	mvwprintw(win1, yPos, xPos, 		" ___              _\n");
	mvwprintw(win1, yPos + 1, xPos, "/ __| _ _   __ _ | |__ ___");
	mvwprintw(win1, yPos + 2, xPos, "\\__ \\| ' \\ / _` || / // -_)");
	mvwprintw(win1, yPos + 3, xPos, "|___/|_||_|\\__,_||_\\_\\\\___|");

	wattroff(win1, A_BOLD);

	mvwprintw(win1, yPos + 5, (xMax - 20)/ 2, "Press Enter to start");
	//box(win1, 0, 0);
	wrefresh(win1); refresh();

	while(getch() != 10) {}

	delwin(win1);
	clear(); refresh();

	return;
}

void updateScore(WINDOW* scoreWin, int& currScore, int& highScore, bool incPnts) {

	if (incPnts)
		currScore++;

	wattron(scoreWin, A_BOLD);

	mvwprintw(scoreWin, 1, 1, "Score: %d", currScore);
	mvwprintw(scoreWin, 2, 1, "Highscore: %d", highScore);
	wrefresh(scoreWin); refresh();

	wattroff(scoreWin, A_BOLD);

	return;
}

char getDirection(WINDOW* gameWin, char&  direction) {
	cbreak();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	int input;

	input = getch();

	switch(input) {
		case KEY_UP:
			if (direction != 'd')
				direction = 'u';
			break;
		case KEY_DOWN:
			if (direction != 'u')
				direction = 'd';
			break;
		case KEY_LEFT:
			if (direction != 'r')
				direction = 'l';
			break;
		case KEY_RIGHT:
			if (direction != 'l')
				direction = 'r';
			break;
	}

	flushinp();

	return direction;
}

//DEBUG
void printTimeBool(Timer& timer) {
	mvwprintw(stdscr, 2, 12, "%d", timer.isTime());
	refresh();

	return;
}

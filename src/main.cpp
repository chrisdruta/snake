/**********************************************************************************/

/*
* File: main.cpp
* Author: Chris Druta
* Date: 12-23-16
*
* Description: sna takes in data of twitter uses and creates a graph from the data. It then performs a social network analysis,
* reccomending people to follow given an input username.
*
*/

/**********************************************************************************/

#include <iostream>
#include <ncurses.h>
#include "snake.h"

/**********************************************************************************/

void startScreen(int yMax, int xMax);
void updateScore(WINDOW* scoreWin, int currScore, int highScore);

/**********************************************************************************/

int main(){

	initscr();
	curs_set(FALSE);
	noecho();

	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);

	startScreen(yMax, xMax);

	int currScore = 0, highScore = 0;

	WINDOW* scoreWin = newwin(4, xMax, yMax - 4, 0);
	WINDOW* gameBorder = newwin(yMax - 4, xMax, 0, 0);

	box(scoreWin, 0, 0);
	box(gameBorder, 0, 0);
	wrefresh(gameBorder);

	updateScore(scoreWin, currScore, highScore);
	refresh();

	Snake snake(yMax - 6, xMax - 2);

	snake.drawSnake();

	mvprintw(3, 3, "Vector Size: %d", snake.getVector().size());

	getch();

	while(1) {
		snake.moveSnake();
		snake.drawSnake();

		getch();
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

void updateScore(WINDOW* scoreWin, int currScore, int highScore) {

	wattron(scoreWin, A_BOLD);

	mvwprintw(scoreWin, 1, 1, "Score: %d", currScore);
	mvwprintw(scoreWin, 2, 1, "Highscore: %d", highScore);
	wrefresh(scoreWin); refresh();

	wattroff(scoreWin, A_BOLD);

	return;
}

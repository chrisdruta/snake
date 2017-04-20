//------------------------------------------------------------------------------------------------
//
// File: snakepart.h
// Author: Chris Druta
// Date: January 23, 2017
//
// Description: contains timer class declarations
//
//------------------------------------------------------------------------------------------------

#include "timer.h"

/**********************************************************************************/

Timer::Timer(int sec) {
	this->timeSec = sec;
	this->timePass = false;
}

Timer::Timer() {
	//Nothing to do here...
}

void Timer::start() {
	usleep(timeSec * 1000000);
	this->timePass = true;
	//this->_thread.join();
	//usleep(100001);
	//this->_thread.join();

	return;
}

void Timer::startThread() {
	this->_thread = std::thread(&Timer::start, this);
	this->_thread.detach();
}

void Timer::stopThread() {
	this->timePass = false;
	return;
}

bool Timer::isTime() {
	return this->timePass;
}

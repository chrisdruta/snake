//------------------------------------------------------------------------------------------------
//
// File: timer.h
// Author: Chris Druta
// Date: January 23, 2017
//
// Description: contains timer class functions
//
//------------------------------------------------------------------------------------------------

#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <time.h>

/**********************************************************************************/

class Timer {
private:
	std::thread _thread;
	long unsigned int time;

public:
	Timer(int sec);

	void start();
	void stop();


};

#endif

/**********************************************************************************/

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

#include <unistd.h>
#include <time.h>
#include <thread>


/**********************************************************************************/

class Timer {
private:
	std::thread _thread;
	unsigned int timeSec;
	bool timePass;

public:
	Timer(int sec);
	Timer();

	void start();
	//void stop();

	void startThread();
	void stopThread();

	bool isTime();
};

#endif

/**********************************************************************************/

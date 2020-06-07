#pragma once
#include "ctime"

//code uit opdrachten van cpp periode 2.4
class StopWatch
{
private:
	clock_t startTime;
	clock_t endTime;
public:
	void start();
	void stop();
	int getElapsedTime();
	StopWatch();
};


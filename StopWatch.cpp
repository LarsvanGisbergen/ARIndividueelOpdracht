#include "StopWatch.h"

void StopWatch::start()
{
	startTime = std::clock();
}

void StopWatch::stop()
{
	endTime = std::clock();
}

int StopWatch::getElapsedTime()
{
	return endTime - startTime;
}

StopWatch::StopWatch()
{
	start();
}

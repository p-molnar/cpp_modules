#include "Timer.hpp"
#include <sys/time.h>
#include <stdexcept>

void Timer::startTimer(void)
{
	timeval tv;
	if (gettimeofday(&tv, NULL) != 0)
		throw std::runtime_error("Timer error");

	start_time = tv.tv_sec + tv.tv_usec * 10000000;
}

void Timer::stopTimer(void)
{
	timeval tv;
	if (gettimeofday(&tv, NULL) != 0)
		throw std::runtime_error("Timer error");

	end_time = tv.tv_sec + tv.tv_usec * 1000000;
}

unsigned int Timer::getTimeElapsed(void)
{
	return end_time - start_time;
}

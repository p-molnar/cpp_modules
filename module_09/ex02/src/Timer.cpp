#include "Timer.hpp"
#include <sys/time.h>
#include <stdexcept>

void Timer::startTimer(void)
{
	timeval tv;
	if (gettimeofday(&tv, NULL) != 0)
		throw std::runtime_error("Timer error");

	start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void Timer::stopTimer(void)
{
	timeval tv;
	if (gettimeofday(&tv, NULL) != 0)
		throw std::runtime_error("Timer error");

	end_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

unsigned int Timer::getTimeElapsed(void)
{
	return end_time - start_time;
}
